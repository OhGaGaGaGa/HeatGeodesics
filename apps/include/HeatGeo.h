#ifndef HEAT_GEO_H
#define HEAT_GEO_H

#include <Eigen/Core>
#include <Eigen/SparseCholesky>
#include "vertex.h"
#include "face.h"
#include "edge.h"

class HeatGeo {
public:
    HeatGeo(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F, int fir = 0) : first(fir) {
        check_asserts(V, F);

        for (int i = 0; i < V.rows(); i++) {
            vertices.emplace_back(V.row(i), i);
        }

        int edgecnt = 0;
        for (int i = 0; i < F.rows(); i++) {
            Face f{vertices[F(i, 0)], vertices[F(i, 1)], vertices[F(i, 2)], i};
            faces.push_back(f);

            vertices[F(i, 0)].addFace(f);
            vertices[F(i, 1)].addFace(f);
            vertices[F(i, 2)].addFace(f);

            Edge* e1 = vertices[F(i, 0)].getEdgeTo(vertices[F(i, 1)]);
            if (!e1) {
                e1 = new Edge(vertices[F(i, 0)], vertices[F(i, 1)], edgecnt++);
                edges.push_back(*e1);
                vertices[F(i, 0)].addEdge(*e1);
                vertices[F(i, 1)].addEdge(*e1);
            } 
            e1->addFace(f);
            f.addEdge(*e1);

            Edge* e2 = vertices[F(i, 1)].getEdgeTo(vertices[F(i, 2)]);
            if (!e2) {
                e2 = new Edge(vertices[F(i, 1)], vertices[F(i, 2)], edgecnt++);
                edges.push_back(*e2);
                vertices[F(i, 1)].addEdge(*e2);
                vertices[F(i, 2)].addEdge(*e2);
            }
            e2->addFace(f);
            f.addEdge(*e2);

            Edge* e3 = vertices[F(i, 2)].getEdgeTo(vertices[F(i, 0)]);
            if (!e3) {
                e3 = new Edge(vertices[F(i, 2)], vertices[F(i, 0)], edgecnt++);
                edges.push_back(*e3);
                vertices[F(i, 2)].addEdge(*e3);
                vertices[F(i, 0)].addEdge(*e3);
            }
            e3->addFace(f);
            f.addEdge(*e3);
        } 
    }

    void compute_geodesics();
    std::vector<double> write_geodesics();

private:
    std::vector<Vertex> vertices;
    std::vector<Face> faces;
    std::vector<Edge> edges;
    int first;
    Eigen::SimplicialCholesky<Eigen::SparseMatrix<double>> heatSolver;
    Eigen::SimplicialCholesky<Eigen::SparseMatrix<double>> poissonSolver;
    void check_asserts(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F) {
        assert(V.cols() == 3 && "Only support 3D data. ");
        assert(F.cols() == 3 && "Only support triangle mesh. ");
    }
    void buildCotanOperator(Eigen::SparseMatrix<double>& Lc) const;
    void buildAreaMatrix(Eigen::SparseMatrix<double> &A) const;
    double computeTimeStep() const;
};

#endif // HEAT_GEO_H