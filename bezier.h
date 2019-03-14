/**
File: bezier.h
Description: Experimental class Bezier will create a bezier curve from a set of AnchorPoints and ControlPoints, using the formula from https://medium.freecodecamp.org/nerding-out-with-bezier-curves-6e3c0bc48e2f
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
*/

#include "point.h"
#include <vector>
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
};

Bezier::Bezier(Point* p)
{
    add_point(p);
}

Point* Bezier::get_point(int index)
{
    return m_points[index];
}

void Bezier::add_point(Point* p)
{
    m_points.push_back(p);
}

void Bezier::curve_from_pts()
{
   double pos, x, y;    // Position on curve, x coordinate, y coordinate
   int max=10;    // number of points to calculate
   Point* p=NULL;   // Pointer to be assigned later 

   for(int i=1; i<max; i++)
   {
       pos=static_cast<double>(i/max);       // increment position from 0 to 1
       x = calc_coord(pos,'x');    // calculate x coordinate
       y = calc_coord(pos,'y');    // calculate y coordinate
       p = new Point(x,y);    // create new Point from coords and assign pointer
       m_curve.push_back(p);    // add new Point* to curve
   }
}

double Bezier::calc_coord(double t, char axis)
{
    int n = m_points.size()-1;  // number of the last point on the curve
    int temp;
    double coord=0;    // coordinate value, to be calculated

    // Complete formula for Bezier curve. Traverses all Points* in m_points
    for(int i=0; i<=n; i++)
        temp = combin(n,i)*pwr(1-t, n-i)*pwr(t, i);
        coord += static_cast<double>(temp)*m_points[i]->get_coord(axis);

    return coord;
}
 
int Bezier::combin(int n, int i)
{
    if(i==0 || i==1 || n==0 || n==1 || n==i)
        int result=1;
    else
    int result=(factorial(n))/(i*factorial(n-i));
    
    return result;
}

int Bezier::pwr(int base, int exp)
{
    int result=1;

    for(int i=exp; i>0; i--)
        result*=base;

    return result;
}

int Bezier::factorial(int x)
{
    int result = x;
    
    for(int i=x-1; i>1; i--)
        result*=i;

    return result;
}

#endif
