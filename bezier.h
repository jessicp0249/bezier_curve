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
   double factorial(int x);    
   // Returns base with an exponent of exp
   double pwr(double base, int exp);    
   // Given n available objects, calculates how many possible combinations of i objects can be selected
   double combin(int n, int i);

   // calculates coordinate value for the given axis (x or y) at position t on the curve
   double calc_coord(double t, char axis);    

   // uses control points in m_points to plot a set of points in m_curve
   void curve_from_pts();   

   // Deletes all Point* pointers and assigns NULL to them
   void reclaim();
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
   double pos,x,y;    // Position on curve, x coordinate, y coordinate
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
    int n = m_points.size()-1;  // degree of the curve, based on number of Points
    double coord=0;    // coordinate value, to be calculated
    // Complete formula for Bezier curve. Traverses all Points* in m_points
    for(int i=0; i<=n; i++)
        coord += combin(n,i)*pwr(1-t,n-i)*pwr(t,i)*m_points[i]->get_coord(axis);

    return coord;
}
 
double Bezier::combin(int n, int i)
{
    double result;
    if(i==0 || i==1) result=1;
    else
    {
        i=static_cast<double>(i);   // Make i a double
        result = (factorial(n))/(i*factorial(n-1));
    }
    return result;
}

double Bezier::pwr(double base, int exp)
{
    double result=1.0;
    for(int i=exp; i>0; i--)
        result*=base;

    return result;
}

double Bezier::factorial(int x)
{
    // make result a double version of x
    double result = static_cast<double>(x);
    for(int i=x-1; i>1; i--)
        result*=i;

    return result;
}

void Bezier::reclaim()
{
    for(int i=0; i<m_points.size(); i++)
    {
        delete m_points[i];
        m_points[i]=NULL;
    }

    for(int i=0; i<m_curve.size(); i++)
    {
        delete m_curve[i];
        m_curve[i]=NULL;
    }
}

#endif
