/**
File: bezier.cpp
Description: Implementation for experimental class Bezier. Will create a bezier curve from a set of AnchorPoints and ControlPoints, using the formula from https://medium.freecodecamp.org/nerding-out-with-bezier-curves-6e3c0bc48e2f
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
*/

#include "point.h"
#include "bezier.h"
#include<vector>
#include<iostream>

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
    if(m_points.size()%2!=0)
    {
	add_point();
    }

    m_points.push_back(p);
}

void Bezier::add_point()
{
    int last_pt = m_points.size()-1;
    m_points.push_back(m_points[last_pt]);
}

void Bezier::curve_from_pts()
{
   double pos,x,y;    // Position on curve, x coordinate, y coordinate
   int n=3;
   double max=10;    // number of points to calculate +1

    // make curve cubic
    if(m_points.size()<n+1)
    {
    	for(int i=m_points.size()-1; i<n; i++)
            add_point();
    }


   for(int i=1; i<max; i++)
   {
       pos=static_cast<double>(i)/max;       // increment position from 0 to 1
       x = calc_coord(pos,'x');    // calculate x coordinate
       y = calc_coord(pos,'y');    // calculate y coordinate

        		//value check
		       std::cout<<"Point["<<i<<"] ("<<x<<", "<<y<<std::endl;
		       // value check

       Point* p = new Point(x,y);    // create new Point from coords and assign pointer
       m_curve.push_back(p);    // add new Point* to curve
   }
}

double Bezier::calc_coord(double pos, char axis)
{
    int n = 3;  // number of the last point on the curve
    int temp;	// container for integer values
    double coord=0;    // coordinate value, to be determined 

    // Complete formula for Bezier curve. Traverses all Points* in m_points
    for(int i=0; i<=n; i++)
    {
        temp = combin(n,i);
        coord += static_cast<double>(temp)*pwr(pos, i)*pwr(1-pos, n-i)*m_points[i]->get_coord(axis);
    }

    return coord;
}
 
int Bezier::combin(int n, int i)
{
    int result;
    if(i==0 || n==0 || n==1 || n==i)
        result=1;
    else
        result=(factorial(n))/(i*factorial(n-i));
    
    return result;
}

double Bezier::pwr(double base, int exp)
{
    double result=1;
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


void Bezier::print()
{
    std::cout<<"Points:"<<std::endl;
    for(int i=0; i<m_points.size(); i++)
    {
	std::cout<<"P["<<i<<"] ";
	m_points[i]->print();
    }

    std::cout<<std::endl<<"Curve points:"<<std::endl;
    for(int i=0; i< m_curve.size(); i++)
    {
	std::cout<<"P"<<i<<" ";
	m_curve[i]->print();
    }


}

