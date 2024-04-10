#include <Eigen/Core>

#ifndef OBJ_H
#define OBJ_H

namespace zjucad::gauwn::io {
    bool read_obj2d(const std::string &filepath, Eigen::MatrixXd &V, Eigen::MatrixXi &L);
    bool read_obj3d(const std::string &filepath, Eigen::MatrixXd &V, Eigen::MatrixXi &F);
} // namespace zjucad::gauwn::io

#endif // OBJ_H