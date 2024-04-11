#include "HeatGeo.h"
#include "vertex.h"

// --- Geodesic Heat Method methods ---
void HeatGeo::buildCotanOperator(Eigen::SparseMatrix<double> &Lc) const {
    std::vector<Eigen::Triplet<double>> LcTriplet;

    for (int i = 0; i < vertices.size(); i++) {
        const Vertex *v        = &vertices[i];
        double sumCoefficients = 0.0;
        for (auto e : v->getEdges()) {
            // (cotA + cotB)
            double bothCot = e->sumCotan();
            sumCoefficients += bothCot;

            Vertex *otherVertex = e->anotherVertex(*v);
            LcTriplet.push_back(Eigen::Triplet<double>(v->getIndex(), otherVertex->getIndex(), bothCot));
        }

        LcTriplet.push_back(Eigen::Triplet<double>(v->getIndex(), v->getIndex(), -sumCoefficients));
    }

    Lc.setFromTriplets(LcTriplet.begin(), LcTriplet.end());
}

void HeatGeo::buildAreaMatrix(Eigen::SparseMatrix<double> &A) const {
    std::vector<Eigen::Triplet<double>> ATriplet;

    for (int i = 0; i < vertices.size(); i++) {
        const Vertex *v = &vertices[i];
        double areas = 0.0;
        for (auto& e : v->getEdges()) {
            double area = 0.5 * e->sumArea(); // avoid duplicate
            areas += area;
        }

        // one third of the neighbouring areas
        areas *= (1.0 / 3.0);

        ATriplet.push_back(Eigen::Triplet<double>(v->getIndex(), v->getIndex(), areas));
    }

    A.setFromTriplets(ATriplet.begin(), ATriplet.end());
}

double HeatGeo::computeTimeStep() const {
    // t = avg edge length ^ 2
    double avgLength = 0.0;
    for (auto &e : edges) {
        avgLength += e.getLength();
    }
    avgLength /= (double)edges.size();
    return avgLength * avgLength;
}

void HeatGeo::compute_geodesics() {
    auto nv = static_cast<Eigen::Index>(vertices.size());

    // Cot Operator
    Eigen::SparseMatrix<double> Lc(nv, nv);
    buildCotanOperator(Lc);
    poissonSolver.compute(Lc);

    // build diagonal area matrix
    Eigen::SparseMatrix<double> A(nv, nv);
    buildAreaMatrix(A);

    // compute time step
    double t = computeTimeStep();

    // 1. compute heat flow for time t
    heatSolver.compute(A - t * Lc);
}

std::vector<double> HeatGeo::write_geodesics() {
    // write geodesics
    return std::vector<double>(vertices.size(), 0);
}