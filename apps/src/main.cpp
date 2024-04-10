#include <Eigen/Core>
#include "CLI11.h"
#include "obj.h"

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

    return 0;
}