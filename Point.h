//
//  Point.h
//  Lab-6
//
//  Created by Chester Francisco on 2022-10-21.
//

#ifndef Point_h
#define Point_h

#include <stdio.h>
#include <string>

class Point {
      
   friend class TestSuite;
   
private:
    int x;
    int y;

public:
    Point();
    Point(int x, int y);
    
    int getX() const;
    int getY() const;
    
    void setX(int x);
    void setY(int y);
    void setXY(int x, int y);
    void swapXY();
    void multiplyX(int factor);
    void multiplyY(int factor);
    
    std::string toString() const;
};



#endif /* Point_h */
