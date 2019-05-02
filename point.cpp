/**
File: point.cpp
Description: Implementation for Point class.  Each Point object contains two fields to represent its location on an xy coordinate plane.
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
*/

#include<iostream>
#include<cassert>
#include<cmath>
#include<ctgmath>
#include "point.h"

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

void Point::set_xy(double x, double y)
{
    set_x(x);
    set_y(y);
}

double Point::distance_from(Point* p)
{
    // a^2 = (x1 - x2)^2
    double distance = pow((get_x() - p->get_x()),2);
    // b^2 = (y1 - y2)^2
    distance += pow((get_y() - p->get_y()),2);
    // a^2 + b^2 = c^2
    distance = sqrt(distance);
    return abs(distance);
}

double Point::get_slope(Point* p)
{
    double slope = 0;
    // if x1 = x2, denominator will be 0. Set slope to NAN (not a number) value
    if(get_x() == p->get_x())
        slope = std::nan("");
    else
    {
        slope = get_y() - p->get_y();
        slope /= get_x() - p->get_x();
    }
    return slope;
}

void Point::print()
{
    double x=get_x();
    double y=get_y();
    std::cout<<"("<< x <<", "<< y <<")"<<std::endl;
}
