/* 
 * File:   Point_2.cpp
 * Author: Fabian
 * 
 * Created on 8. November 2015, 13:03
 */

#include "Point_2.h"

Point_2::Point_2(double x, double y) : Point_1::Point_1(x), ycoord(y) {}

Point_2::~Point_2() {}

double Point_2::y() const {
    return ycoord;
}

int Point_2::dimension() const {
    return 2;
}
