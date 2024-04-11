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
    }

    void compute_geodesics();
    std::vector<double> write_geodesics();

private:
    std::vector<Vertex> vertexs;
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