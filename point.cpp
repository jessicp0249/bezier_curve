/**
File: point.cpp
Description: Implementation for Point class.  Each Point object contains two fields to represent its location on an xy coordinate plane.
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
*/

#include<iostream>
#include<cassert>
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

void Point::print()
{
    double x=get_x();
    double y=get_y();
    std::cout<<"("<< x <<", "<< y <<")"<<std::endl;
}
