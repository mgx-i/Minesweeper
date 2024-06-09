#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include "grid.hpp"

/**
 * @brief 
 * 
 */

class Cell 
{
    private :
        bool _is_mined;
        short int _number_of_neighbouring_mines = -1;
        bool _is_flagged = false;
        bool _is_suspiciously_flagged = false;
        bool _is_visible = false;
        Grid & _parent_grid;
    
    public :
        Cell (bool is_mined, Grid & parent_grid);
        
        bool isMine();
        bool isVisible();
        bool isFlagged();
        bool isSuspiciouslyFlagged();
        short int getNumberOfNeighbouringMines();
        Grid getParentGrid();

        bool dig(); //retourne la case
        void flag();
        void removeFlag();
        void flagSuspiciously();
        void removeSuspiciousFlag();
        bool isFlaggedAppropriatly();
};



#endif


