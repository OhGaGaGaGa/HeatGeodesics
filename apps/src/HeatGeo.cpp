#include "HeatGeo.h"
#include "vertex.h"

// // --- Geodesic Heat Method methods ---
// void HeatGeo::buildCotanOperator(Eigen::SparseMatrix<double> &Lc) const {
//     std::vector<Eigen::Triplet<double>> LcTriplet;

//     for (VertexConstIterator vci = verticesBegin(); vci != verticesEnd(); vci++) {
//         double sumCoefficients = 0.0;
//         for (MeshVertex::EdgeConstIterator eci = vci->edgesBegin(); eci != vci->edgesEnd(); ++eci) {
//             // (cotA + cotB)
//             double coefficient = (*eci)->sumCotans();
//             sumCoefficients += coefficient;

//             Vertex const *otherVertex = (*eci)->getOtherEndpoint(&(*vci));
//             LcTriplet.push_back(Eigen::Triplet<double>(vci->getIndex(), otherVertex->getIndex(), coefficient));
//         }

//         LcTriplet.push_back(Eigen::Triplet<double>(vci->getIndex(), vci->getIndex(), -sumCoefficients));
//     }

//     Lc.setFromTriplets(LcTriplet.begin(), LcTriplet.end());
// }

// void HeatGeo::buildAreaMatrix(Eigen::SparseMatrix<double> &A) const {
//     std::vector<Eigen::Triplet<double>> ATriplet;

//     for (int i = 0; i < V.rows(); i++) {

//         double areas = 0.0;
//         for (MeshVertex::EdgeConstIterator veci = vci->edgesBegin(); veci != vci->edgesEnd(); ++veci) {
//             // multipling with 0.5, because same area is calculated twice
//             double area = 0.5 * (*veci)->sumAreas();
//             areas += area;
//         }

//         // one third of the neighbouring areas
//         areas *= (1.0 / 3.0);

//         ATriplet.push_back(Eigen::Triplet<double>(i, i, areas));
//     }

//     A.setFromTriplets(ATriplet.begin(), ATriplet.end());
// }

// double HeatGeo::computeTimeStep() const {
//     // t = avg edge length ^ 2
//     double avgLength = 0.0;
//     for (EdgeConstIterator eci = edgesBegin(); eci != edgesEnd(); eci++) {
//         avgLength += eci->getLength();
//     }
//     avgLength /= (double)edges.size();
//     return avgLength * avgLength;
// }

// void HeatGeo::compute_geodesics() {
//     auto nv = V.rows();

//     // Cot Operator
//     Eigen::SparseMatrix<double> Lc(nv, nv);
//     buildCotanOperator(Lc);
//     poissonSolver.compute(Lc);

//     // build diagonal area matrix
//     Eigen::SparseMatrix<double> A(nv, nv);
//     buildAreaMatrix(A);

//     // compute time step
//     double t = computeTimeStep();

//     // 1. compute heat flow for time t
//     heatSolver.compute(A - t * Lc);
// }

std::vector<double> HeatGeo::write_geodesics() {
    // write geodesics
    return std::vector<double>(vertexs.size(), 0);
}