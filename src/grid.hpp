#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>


class Grid
{
    /**
     * @brief A cell which is part of a @ref Grid. 
     * Can contain a mine and be flagged with a regular flag or a question mark flag.
     * By default the cell is not uncovered.
     */
    class Cell 
    {
        private :
            /** @brief Tells if the cell is mined */
            bool _is_mined; 
            /** @brief Tells the number of mines in neighbouring cells (-1 if not calculated yet) */
            short int _number_of_neighbouring_mines = -1;
            /** @brief Tells if the cell is flagged */
            bool _is_flagged = false;
            /** @brief Tells if the cell is marked with a question mark flag */
            bool _is_suspiciously_flagged = false;
            /** @brief Tells if the cell is uncovered by the player */
            bool _is_uncovered = false;
            /** @brief References the parent grid */
            Grid & _parent_grid;
        
        public :
            /**
             * @brief Construct a new Cell object
             * 
             * @param is_mined Mines / does not mine a cell
             * @param parent_grid Reference of the parent grid
             */
            Cell (bool is_mined, Grid & parent_grid);
            
            /**
             * @brief Tells if the cell is mined
             * 
             * @return true the cell is mined
             * @return false the cell is not mined
             */
            bool isMined();
            /**
             * @brief Tells if the cell is uncovered
             * 
             * @return true the cell is uncovered
             * @return false the cell is not uncovered
             */
            bool isUncovered();
            /**
             * @brief Tells if the cell is flagged
             * 
             * @return true the cell is flagged
             * @return false the cell is not flagged
             */
            bool isFlagged();
            /**
             * @brief Tells if the cell is marked with a question mark flag
             * 
             * @return true the cell is marked with a question mark flag
             * @return false the cell is not marked with a question mark flag
             */
            bool isSuspiciouslyFlagged();
            /**
             * @brief Get the Number Of Neighbouring Mines
             * 
             * @return short int number of neighbouring mines (-1 if not calculated yet)
             */
            short int getNumberOfNeighbouringMines();
            /**
             * @brief Get the Parent Grid object
             * 
             * @return Grid the grid containing this cell
             */
            Grid getParentGrid();

            /**
             * @brief Uncovers the cell and removes all flags
             * 
             * @return true the cell is mined
             * @return false the cell is not mined 
             */
            bool dig();
            /**
             * @brief Places a flag on the cell, removes eventual question mark flag
             * 
             */
            void flag();
            /**
             * @brief Removes eventual regular flag on the cell
             * 
             */
            void removeFlag();
            /**
             * @brief Places a question mark flag on the cell, removes eventual regular flag
             * 
             */
            void flagSuspiciously();
            /**
             * @brief Removes eventual question mark flag
             * 
             */
            void removeSuspiciousFlag();
    };


};



#endif