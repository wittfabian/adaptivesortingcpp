/* 
 * File:   Point_2.h
 * Author: Fabian Witt
 *
 */

#ifndef POINT_2_H
#define	POINT_2_H

#include "Point_1.h"

class Point_2 : public Point_1 {
public:
    Point_2(double x = 0.0, double y = 0.0);
    virtual ~Point_2();
    
    virtual double  y() const;
    virtual int     dimension() const;
    
    friend std::ostream& operator<<(std::ostream& s, const Point_2& p);
    
protected:
    double  ycoord;
};

#endif	/* POINT_2_H */

