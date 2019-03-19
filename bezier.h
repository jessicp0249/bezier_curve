/**
File: bezier.h
Description: Experimental class Bezier will create a bezier curve from a set of AnchorPoints and ControlPoints, using the formula from https://medium.freecodecamp.org/nerding-out-with-bezier-curves-6e3c0bc48e2f
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
*/

#include "point.h"
#include<vector>
#include<iostream>

#ifndef BEZIER_H
#define BEZIER_H

class Bezier
{
private:
    std::vector<Point*> m_points;
    std::vector<Point*> m_curve;

public:
   // Constructs a Bezier object with one Point object pointer in the vector
   Bezier(Point* p);    

   // returns a Point* from the given position in vector m_points
   Point* get_point(int index);
   // adds the given Point* to m_points vector
   void add_point(Point* p);
   // duplicates the last Point* on m_points vector (simulates non-bezier anchor point)
   void add_point();

   // Returns x! (x factorial)
    int factorial(int x);    
   // Returns base with an exponent of exp
   int pwr(int base, int exp);    
   // Given n available objects, calculates how many possible combinations of i objects can be selected
   int combin(int n, int i);

   // calculates coordinate value for the given axis (x or y) at position t on the curve
   double calc_coord(double t, char axis);    
   // uses control points in m_points to plot a set of points in m_curve
   void curve_from_pts();   

   // prints coords of Points* in m_points and m_curve
   void print();

   // Deletes all Point* pointers and assigns them to NULL 
   void reclaim();
};
#endif
