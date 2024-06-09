
#include "cell.hpp"
#include "grid.hpp"


Cell::Cell (bool is_mined,Grid & parent_grid) : _parent_grid(parent_grid)
{
    this -> _is_mined = is_mined;
}


bool Cell::isMine() {
    return this -> _is_mined;
}

bool Cell::isVisible() {
    return this -> _is_visible;
}

bool Cell::isFlagged() {
    return this -> _is_flagged;
}

bool Cell::isSuspiciouslyFlagged() {
    return this -> _is_suspiciously_flagged;
}

short int Cell::getNumberOfNeighbouringMines() {
    return this -> _number_of_neighbouring_mines;
}

Grid Cell::getParentGrid() {
    return this -> _parent_grid; //BESOIN DE REF??
}

bool Cell::dig() 
{
    this -> _is_visible = true;
    this -> _is_flagged = false;
    this -> _is_suspiciously_flagged = false;
    return this -> _is_mined;
}

void Cell::flag() 
{
    this -> _is_flagged = true;
    Cell::removeSuspiciousFlag();
}

void Cell::removeFlag() 
{
    this -> _is_flagged = false;
}

void Cell::flagSuspiciously() 
{
    this -> _is_suspiciously_flagged = true;
    Cell::removeFlag();
}

void Cell::removeSuspiciousFlag()
{
    this -> _is_suspiciously_flagged = false;
}

bool Cell::isFlaggedAppropriatly()
{
    if (Cell::isFlagged() && Cell::isSuspiciouslyFlagged())
    {
        return false;
    }
    else
    {
        return true;
    }
}


