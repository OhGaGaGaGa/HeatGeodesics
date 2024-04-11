#include "VTKwriter.h"
#include <iostream>

void VTKwriter::write_colored_points() {
    _out << "# vtk DataFile Version 2.0" << '\n';
    _out << "vtk output" << '\n';
    _out << "ASCII" << '\n';
    _out << "DATASET UNSTRUCTURED_GRID" << '\n';

    _out << "POINTS " << _vertex.rows() << " double" << '\n';
    for (int i = 0; i < _vertex.rows(); i++) {
        for (int j = 0; j < _vertex.cols(); j++)
            _out << _vertex(i, j) << " ";
        _out << '\n';
    }
    _out << '\n';

    _out << "CELLS " << _vertex.rows() << " " << _vertex.rows() * 2 << '\n';
    for (int i = 0; i < _vertex.rows(); i++) {
        _out << "1 " << i << '\n';
    }
    _out << '\n';

    _out << "CELL_TYPES " << _vertex.rows() << '\n';
    for (int i = 0; i < _vertex.rows(); i++)
        _out << 1 << '\n';
    _out << '\n';

    assert(_vertex.rows() == _category.size() && "Test Data Size != Test Data Tag");

    _out << "POINT_DATA " << _vertex.rows() << '\n';
    _out << "SCALARS color double 1" << '\n';
    _out << "LOOKUP_TABLE default" << '\n';

    for (auto val : _category) {
        _out << val << '\n';
    }
}

void VTKwriter::write_grid() {
    _out << "# vtk DataFile Version 2.0" << '\n';
    _out << "vtk output" << '\n';
    _out << "ASCII" << '\n';
    _out << "DATASET UNSTRUCTURED_GRID" << '\n';

    _out << "POINTS " << _vertex.rows() << " double" << '\n';
    for (int i = 0; i < _vertex.rows(); i++) {
        for (int j = 0; j < _vertex.cols(); j++)
            _out << _vertex(i, j) << " ";
        _out << '\n';
    }
    _out << '\n';

    _out << "CELLS " << _grid.rows() << " " << _grid.rows() * 9 << '\n';
    for (int i = 0; i < _grid.rows(); i++) {
        _out << "8";
        for (auto val : _grid.row(i)) {
            _out << " " << val;
        }
        _out << '\n';
    }
    _out << '\n';

    _out << "CELL_TYPES " << _grid.rows() << '\n';
    for (int i = 0; i < _grid.rows(); i++)
        _out << 12 << '\n';
    _out << '\n';

    _out << "POINT_DATA " << _vertex.rows() << '\n';
    _out << "SCALARS WindingNumber double 1" << '\n';
    _out << "LOOKUP_TABLE default" << '\n';

    for (auto i = 0; i < _vertex.rows(); i++) {
        _out << _wn[i] << '\n';
    }
}