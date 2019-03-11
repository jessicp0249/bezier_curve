/**
File: point.h
Description: Header file for Point class.  Each Point object contains two fields to represent its location on an xy coordinate plane.
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
*/

#include<cassert>
#ifndef POINT_H
#define POINT_H

class Point
{
public:
    // Default constructor. Initializes data fields with zeroes
    Point();
    // Constructor. Initializes x and y coordinates with the given values
    Point(double x, double y);
    // Accessor. Returns x coordinate
    double get_x() const;
    // Accessor. Returns y coordinate
    double get_y() const;
    // Accessor. If axis is x, returns m_x. If axis is y, returns m_y
    double get_coord(char axis) const;
    // Mutator. Sets value of x coordinate
    void set_x(double x);
    // Mutator. Sets value of y coordinate
    void set_y(double y);

private:
    double m_x;    // x coordinate
    double m_y;    // y coordinate
};

Point::Point()
{
    m_x = 0;
    m_y = 0;
}

Point::Point(double x, double y)
{
    m_x = x;
    m_y = y;
}

double Point::get_x() const
{
    return m_x;
}

double Point::get_y() const
{
    return m_y;
}

double Point::get_coord(char axis) const
{
    // char axis must indicate either x or y value
    assert(axis=='x' || axis=='y');
    double coord;

    if(axis=='x')
        coord = get_x();
    else if(axis=='y')
        coord = get_y();

    return coord;
}

void Point::set_x(double x)
{
    m_x = x;
}

void Point::set_y(double y)
{
    m_y = y;
}

#endif
