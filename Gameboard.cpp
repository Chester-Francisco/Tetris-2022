//
//  Gameboard.cpp
//  Lab-7
//
//  Created by Chester Francisco on 2022-10-31.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cassert>
#include "Gameboard.h"


// constructor - empty() the grid
Gameboard::Gameboard() {
   empty();
}

// fill the board with EMPTY_BLOCK
//   (iterate through each rowIndex and fillRow() with EMPTY_BLOCK))
// - params: none
// - return: nothing
void Gameboard::empty() {
   for(int row = 0; row < MAX_Y; row++){
      fillRow(row, EMPTY_BLOCK);
   }
}

// print the grid contents to the console (for debugging purposes)
//   use std::setw(2) to space the contents out
//   (google it, you'll need to #include <iomanip>).
//   If the content == EMPTY_BLOCK, print a '.', otherwise print the content.
// - params: none
// - return: nothing
void Gameboard::printToConsole() const  {
   
   for(int row = 0; row < MAX_Y; row++) {
      for(int col = 0; col < MAX_X; col++){
         if(grid[row][col] == EMPTY_BLOCK) {
            std::cout << std::setw(2) << ".";
         }
         else {
            std::cout << std::setw(2) << grid[row][col];
         
         }
      }
      std::cout << std::endl;
      
   }
}

// get the content at a given point
// assert the point is valid (use isValidPoint())
// - param 1: a Point (the XY of the content we want to retrieve)
// - return: an int, the content from the grid at the specified point
int Gameboard::getContent(const Point& pt) const {
   assert(isValidPoint(pt));
   return grid[pt.getY()][pt.getX()];
}

// get the content at a given XY location
// assert the point is valid (use isValidPoint())
// - param 1: an int for X (column)
// - param 2: an int for Y (row)
// - return: an int, the content from the grid at the specified XY
int Gameboard::getContent(int x, int y) const {
   assert(isValidPoint(x, y));
   return Gameboard::grid[y][x];
}

// set the content at a given point (ignore invalid points)
// - param 1: a Point
// - param 2: an int representing the content we want to set at this location.
void Gameboard::setContent(const Point& pt, int content) {
   bool valid = isValidPoint(pt);
   if(valid) {
      grid[pt.getY()][pt.getX()] = content;
      
   }
}

// set the content at an x,y position (ignore invalid points)
// - param 1: an int for X (column)
// - param 2: an int for Y (row)
// - param 3: an int representing the content we want to set at this location
void Gameboard::setContent(int x, int y, int content) {
   bool valid = isValidPoint(x, y);
   
   if(valid){
      grid[y][x] = content;
   }
}

// set the content for a set of points (ignore invalid points)
// - param 1: a vector of Points representing locations
// - param 2: an int representing the content we want to set.
void Gameboard::setContent(const std::vector<Point>& points, int content) {
   
   for(Point pt: points){
      if(isValidPoint(pt)) {
         grid[pt.getY()][pt.getX()] = content;
      }
   }
}

// Determine if (valid) all points passed in are empty
// *** IMPORTANT: Assume invalid x,y values can be passed to this method.
// Invalid meaning outside the bounds of the grid.
// * ONLY TEST VALID POINTS (use isValidPoint()). Ignore invalid Points.
// Using invalid points to index into the grid would cause undefined behaviour.
// - param 1: a vector of Points representing locations to test
// - return: true if the content at ALL VALID points is EMPTY_BLOCK, false otherwise
bool Gameboard::areAllLocsEmpty(const std::vector<Point>& points) const {
  
   for(Point pt: points) {
      if(isValidPoint(pt)) {
         if(grid[pt.getY()][pt.getX()] != EMPTY_BLOCK) {
            return false;
         }
      }
   }
   
   return true;
}

//// Remove all completed rows from the board
////   use getCompletedRowIndices() and removeRows()
//// - params: none
//// - return: the count of completed rows removed
int Gameboard::removeCompletedRows() {
   
   std::vector<int> completedRows = getCompletedRowIndices();
   removeRows(completedRows);

   return static_cast<int>(completedRows.size());
}

//// A getter for the spawn location
//// - params: none
//// - returns: a Point, representing our private spawnLoc
Point Gameboard::getSpawnLoc() {
   return spawnLoc;
}

// Determine if a given Point is a valid grid location
// - param 1: a Point object
// - return: true if the point is a valid grid location, false otherwise
bool Gameboard::isValidPoint(const Point& pt) const {
   
   if(pt.getX() < 0 || pt.getX() >= MAX_X) {
      return false;
   }
   else if (pt.getY() < 0 || pt.getY() >= MAX_Y) {
      return false;
   }
   
   return true;
}

// Determine if a given XY is a valid grid location
// - param 1: an int representing x
// - param 2: an int representing y
// - return: true if the x,y is a valid grid location, false otherwise
bool Gameboard::isValidPoint(int x, int y) const {
   
   if(x < 0 || x >= MAX_X) {
      return false;
   }
   else if (y < 0 || y >= MAX_Y) {
      return false;
   }
   
   return true;
}

// return a bool indicating if a given row is full (no EMPTY_BLOCK in the row)
// assert the row index is valid
// - param 1: an int representing the row index we want to test
// - return: bool representing if the row is completed
bool Gameboard::isRowCompleted(int rowIndex) const {
   
   if(rowIndex >= 0 && rowIndex < MAX_Y) {
      for(int  x = 0; x < MAX_X; x++) {
         if(grid[rowIndex][x] == EMPTY_BLOCK) {
            return false;
         }
      }
   }

   return true;
}

// fill a given grid row with specified content
// - param 1: an int representing a row index
// - param 2: an int representing content
// - return: nothing
void Gameboard::fillRow(int row, int content) {
   assert(row >= 0 && row < MAX_Y);
   
   for(int x = 0; x < MAX_X; x++) {
      grid[row][x] = content;
   }
}

// scan the board for completed rows.
// Iterate through grid rows and use isRowCompleted(rowIndex)
// - params: none
// - return: a vector of completed row indices (integers).
std::vector<int> Gameboard::getCompletedRowIndices() const {
   std::vector<int> completedRows;
   
   for(int row = 0; row < MAX_Y; row++) {
      if(isRowCompleted(row)) {
         completedRows.push_back(row);
      }
   }
   return completedRows;
}

// copy a source row's contents into a target row.
// - param 1: an int representing the source row index
// - param 2: an int representing the target row index
// - return: nothing
void Gameboard::copyRowIntoRow(int rowSource, int rowTarget) {
   assert(rowSource >= 0 && rowSource < MAX_Y);
   assert(rowTarget >= 0 && rowTarget < MAX_Y);
   
   for(int x = 0; x < MAX_X; x++) {
      grid[rowTarget][x] = grid[rowSource][x];
   }
}
   
// In gameplay, when a full row is completed (filled with content)
// it gets "removed".  To be exact, the row itself is not removed
// but the content from the row above it is copied into it.
// This continues all the way up the grid until the first row is copied
// into the second row.  Finally, the first row is filled with EMPTY_BLOCK
// Given a row index:
//   1) Assert the row index is valid
//   2) Starting at rowIndex, copy each row above the removed
//     row "one-row-downwards" in the grid.
//     (loop from y=rowIndex-1 down to 0, and copyRowIntoRow(y, y+1)).
//   3) call fillRow() on the first row (and place EMPTY_BLOCKs in it).
// - param 1: an int representing a row index
// - return: nothing
void Gameboard::removeRow(int rowIndex) {
   
   if(rowIndex >= 0 && rowIndex < MAX_Y) {
      for(int y = rowIndex-1; y >= 0; y--) {
         copyRowIntoRow(y, y+1);
   
      }
   }  fillRow(0, EMPTY_BLOCK);
}

// given a vector of row indices, remove them.
//   Iterate through the vector, call removeRow() on each row index.
// - param 1: a vector of integers representing row indices we want to remove
// - return: nothing
void Gameboard::removeRows(const std::vector<int>& indices) {
   for(int i: indices) {
      removeRow(i);
   }
}
