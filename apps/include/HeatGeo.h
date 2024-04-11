#ifndef HEAT_GEO_H
#define HEAT_GEO_H

#include <Eigen/Core>
#include <utility>

class HeatGeo {
public:
    HeatGeo(Eigen::MatrixXd V, Eigen::MatrixXi F) : V(std::move(V)), F(std::move(F)) {
        check_asserts();
    }
    HeatGeo(Eigen::MatrixXd V, Eigen::MatrixXi F, int fir) : V(std::move(V)), F(std::move(F)), first(fir) {
        check_asserts();
    }

    void compute_geodesics();
    std::vector<double> write_geodesics();

private:
    Eigen::MatrixXd V;
    Eigen::MatrixXi F;
    int first = 0;
    void check_asserts() {
        assert(V.cols() == 3 && "Only support 3D data. ");
        assert(F.cols() == 3 && "Only support triangle mesh. ");
    }
};

#endif // HEAT_GEO_H