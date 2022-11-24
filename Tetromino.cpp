//
//  Tetromino.cpp
//  Lab-6
//
//  Created by Chester Francisco on 2022-10-21.
//

#include "Tetromino.h"
#include <iostream>
#include <random>

Tetromino::Tetromino() {
   setShape(TetShape::S);
}

TetColor Tetromino::getColor() const {
    return color;
}

TetShape Tetromino::getShape() const {
    return shape;
}

void Tetromino::setShape(TetShape shape) {
    this->shape = shape;
    color = static_cast<TetColor>(shape);
    
    switch(shape) {
        case TetShape::S:
            blockLocs = {Point(-1,0), Point(0,0), Point(0,1), Point(1,1)};
            break;
        case TetShape::Z:
            blockLocs = {Point(0,0), Point(1,0), Point(0,1), Point(-1,1)};
            break;
        case TetShape::L:
            blockLocs = {Point(0,0), Point(0,1), Point(0,-1), Point(1,-1)};
            break;
        case TetShape::J:
            blockLocs = {Point(0,0), Point(0,-1), Point(0,1), Point(-1,-1)};
            break;
        case TetShape::O:
            blockLocs = {Point(0,1), Point(0,0), Point(1,1), Point(1,0)};
            break;
        case TetShape::I:
            blockLocs = {Point(0,-1), Point(0,0), Point(0,1), Point(0,2)};
            break;
        case TetShape::T:
            blockLocs = {Point(0,0), Point(1,0), Point(-1,0), Point(0,-1)};
            break;
    }
}

void Tetromino::rotateClockwise() {
    for (Point& pt: blockLocs) {
        pt.swapXY();
        pt.multiplyY(-1);
    }
}

void Tetromino::printToConsole() const{
    
   
    
    for(int y = 3; y > -3; y--) {
         std::cout << "" << std::endl;
         for(int x = -3; x < 3; x++){
            bool foundMatch = false;
             for(Point pt: blockLocs) {
                if(pt.getY() == y && pt.getX() == x){
                   foundMatch = true;
                }
             }
            if(foundMatch) {
               std::cout << "x";
            } else {
               std::cout << ".";
            }
         }
     }
}

TetShape Tetromino::getRandomShape() {
    return static_cast<TetShape>(rand() % TetShape::COUNT);
}

