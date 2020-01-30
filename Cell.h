//
// Created by zahalka on 17/01/2020.
//

#ifndef MILESTONE_2_CELL_H
#define MILESTONE_2_CELL_H

#include "State.h"

class Cell {
    int column{};
    int row{};
public:
    //Constructor
    Cell(int _column, int _row) : column(_column), row(_row) {}
    //default constructor
    Cell() = default;
    //return the column
    int getColumn() {
        return this->column;
    }
    //return the row.
    int getRow() {
        return this->row;
    }
    //compare
    bool operator==(Cell m) {
        return (this->row == m.getRow() && this->column == m.getColumn());
    }
};

#endif //MILESTONE_2_CELL_H
