//
//  GridTetromino.cpp
//  Lab-6
//
//  Created by Chester Francisco on 2022-11-11.
//
#include "GridTetromino.h"
#include <stdio.h>
#include <vector>


// constructor, initialize gridLoc to 0,0
GridTetromino::GridTetromino() : gridLoc(0,0) {}

// a getter for the tetromino's location
// - params: none
// - return: a Point (the private member variable gridLoc)
Point GridTetromino::getGridLoc() const {
   return gridLoc;
}

// a setter for the tetronimo's location
// - param 1: int x
// - param 2: int y
// return: nothing
void GridTetromino::setGridLoc(int x, int y) {
   gridLoc.setXY(x,y);
   gridLoc.swapXY();
}

// a setter for the tetromino's location
// param 1: a Point (the new gridLoc)
// return: nothing
void GridTetromino::setGridLoc(const Point& pt) {
   gridLoc.setXY(pt.getX(), pt.getY());
}

// transpose the gridLoc of this shape
//   (1,0) represents a move to the right (x+1)
//   (-1,0) represents a move to the left (x-1)
//   (0,1) represents a move down (y+1)
// - param 1: int xOffset, the x offset (distance) to move
// - param 2: int yOffset, the y offset (distance) to move
// - return: nothing
void GridTetromino::move(int xOffset, int yOffset) {
   if(xOffset == 1 && yOffset == 0) {
      gridLoc.setXY(gridLoc.getX() + 1, gridLoc.getY());
   }
   else if (xOffset == -1 && yOffset == 0) {
      gridLoc.setXY(gridLoc.getX() - 1, gridLoc.getY());
   }
   else {
       gridLoc.setXY(gridLoc.getX(), gridLoc.getY() + 1);
   }
   
}

// Build and return a vector of Points to represent our inherited
// blockLocs vector mapped to the gridLoc of this object instance.
// You will need to provide this class access to blockLocs (from the Tetromino class).
// eg: if we have a Point [x,y] in our vector,
// and our gridLoc is [5,6] the mapped Point would be [5+x,6+y].
// params: none:
// return: a vector of Point objects.
std::vector<Point> GridTetromino::getBlockLocsMappedToGrid() const {

   std::vector<Point> mappedPoints;

   for(Point pt: blockLocs) {
        mappedPoints.push_back( Point(pt.getX() + gridLoc.getX(), pt.getY() + gridLoc.getY()) );
   }
   return mappedPoints;
}
