/**
File: point.h
Description: Header file for Point class.  Each Point object contains two fields to represent its location on an xy coordinate plane.
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
*/

#include<iostream>
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
    // Mutator.  Sets values of x and y coordinates
    void set_xy(double x, double y);

    // Returns distance between two points
    double distance_from(Point* p);
    // Calculates the slope of a line made up of two points
    double get_slope(Point* p);

    // prints point coordinates
    void print();

private:
    double m_x;    // x coordinate
    double m_y;    // y coordinate
};
#endif
