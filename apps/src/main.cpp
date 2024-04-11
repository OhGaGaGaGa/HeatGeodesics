#include <Eigen/Core>
#include "CLI11.h"
#include "HeatGeo.h"
#include "obj.h"
#include "vtk.h"
#include "VTKwriter.h"

int main(int argc, char **argv) {
    CLI::App app("Geodesics in Heat implementation. ");
    app.set_config("--config");

    std::string input;
    app.add_option("-i,--input", input,
                   "The input model file (obj).")
    ->required()
    ->check(CLI::ExistingFile);

    std::string output;
    app.add_option("-o,--output", output,
                   "The output mesh file.")
    ->required();

    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        return app.exit(e);
    }

    Eigen::MatrixXd V;
    Eigen::MatrixXi F;
    bool res = zjucad::gauwn::io::read_obj3d(input, V, F);
    if (!res) {
        std::cout << "Read OBJ Error! " << '\n';
        return 0;
    }

    // std::vector<double> val(V.rows(), 0);
    HeatGeo heat(V, F, 0);
    heat.compute_geodesics();
    auto val = heat.write_geodesics();
    VTKwriter writer(output.c_str(), V, val);
    bool output_file_status = writer.file_status();
    if (!output_file_status) {
        std::cout << "Open writing VTK Error! " << '\n';
        return 0;
    }
    writer.write_colored_points();

    return 0;
}