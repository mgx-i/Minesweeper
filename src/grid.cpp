
#include "grid.hpp"


Grid::Cell::Cell (bool is_mined,Grid & parent_grid) : _parent_grid(parent_grid)
{
    this -> _is_mined = is_mined;
}


bool Grid::Cell::isMined() {
    return this -> _is_mined;
}

bool Grid::Cell::isUncovered() {
    return this -> _is_uncovered;
}

bool Grid::Cell::isFlagged() {
    return this -> _is_flagged;
}

bool Grid::Cell::isSuspiciouslyFlagged() {
    return this -> _is_suspiciously_flagged;
}

short int Grid::Cell::getNumberOfNeighbouringMines() {
    return this -> _number_of_neighbouring_mines;
}

Grid Grid::Cell::getParentGrid() {
    return this -> _parent_grid;
}

bool Grid::Cell::dig() 
{
    this -> _is_uncovered = true;
    this -> _is_flagged = false;
    this -> _is_suspiciously_flagged = false;
    return this -> _is_mined;
}

void Grid::Cell::flag() 
{
    this -> _is_flagged = true;
    Grid::Cell::removeSuspiciousFlag();
}

void Grid::Cell::removeFlag() 
{
    this -> _is_flagged = false;
}

void Grid::Cell::flagSuspiciously()
{
    this -> _is_suspiciously_flagged = true;
    Grid::Cell::removeFlag();
}

void Grid::Cell::removeSuspiciousFlag()
{
    this -> _is_suspiciously_flagged = false;
}

