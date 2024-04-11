#include <Eigen/Core>
#include "CLI11.h"
#include "HeatGeo.h"
#include "obj.h"
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

    HeatGeo heat(V, F);
    // heat.compute_geodesics();
    auto val = heat.write_geodesics();
    VTKwriter writer(output.c_str(), V, val);
    bool output_file_status = writer.file_status();
    if (!output_file_status) {
        std::cout << "Open writing VTK Error! " << '\n';
        return 0;
    }
    writer.write_colored_points();

    // Eigen::SparseMatrix<double,Eigen::RowMajor> Test(2, 3);
    // Test.insert(0, 1) = 34;
    // Test.insert(1, 2) = 56;
    // using std::cout;
    // for (int k = 0; k < Test.outerSize(); ++k){
    //     for (Eigen::SparseMatrix<double,Eigen::RowMajor>::InnerIterator it(Test, k); it; ++it){
    //         cout << it.row() <<"\t";
    //         cout << it.col() << "\t";
    //         cout << it.value() << std::endl;
    //     }
    //     cout << "row: " << k << std:: endl;
    // }
    /*
0       1       34
row: 0
1       2       56
row: 1
[jkwang@
    */

    return 0;
}