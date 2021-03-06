/* 
 * File:   Point_1.h
 * Author: Fabian Witt
 *
 */

#ifndef POINT_1_H
#define	POINT_1_H

class Point_1 {
public:
    Point_1(double x = 0.0);
    virtual ~Point_1();
    
    virtual double x() const;
    virtual double y() const;
    virtual int    dimension() const;
    
    friend std::ostream& operator<<(std::ostream& s, const Point_1& p);
    
protected:
    double xcoord;
};

#endif	/* POINT_1_H */

