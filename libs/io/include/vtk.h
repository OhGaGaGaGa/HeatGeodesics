#ifndef VTK_H
#define VTK_H

#include <Eigen/Core>
#include <fmt/os.h>
#include "stdgenerator.h"

namespace zjucad::gauwn::io {

void write_vtk_header(fmt::ostream &out);
 void write_vtk_vertex(fmt::ostream &out, const Eigen::MatrixXd &vertex);
 void write_vtk_cells_heterogeneous(
    fmt::ostream &out, const coro::generator<int> &info);
 void write_vtk_cells_homogeneous(
    fmt::ostream &out, const Eigen::MatrixXi &cells, int cell_type);

 void write_vtk_point_data(
    fmt::ostream &out, int n);
 void write_vtk_cell_data(
    fmt::ostream &out, int n);
 void write_vtk_scalars(
    fmt::ostream &out, const Eigen::VectorXd &data, const std::string &name);

 void write_vtk_vectors(
    fmt::ostream &out, const Eigen::MatrixXd &data, const std::string &name);

 void write_vtk_field(
    fmt::ostream &out, const Eigen::MatrixXd &data, const std::string &name);
 void write_vtk_curve(fmt::ostream &out, const Eigen::MatrixXd &vertex, const Eigen::MatrixXi &line);

} // namespace zjucad::gauwn::io

#endif // VTK_H