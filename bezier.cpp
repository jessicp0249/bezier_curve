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
    // If last anchor point has no control points...
    if(m_points.size()%2!=0)
        dup_point();
    m_points.push_back(p);
}

void Bezier::dup_point()
{
    // Get index of last point
    int last_pt = m_points.size()-1;
    // Add copy of last point to vector
    m_points.push_back(m_points[last_pt]);
}

void Bezier::curve_from_pts()
{
   double pos,x,y;    // Position on curve, x coordinate, y coordinate
   int cubic=3;     // Minimum number of points
   double max=10;    // number of points to calculate +1

#if 0
    // If curve is not cubic, add points until it is
    for(int i=m_points.size(); i<=cubic; i++)
        dup_point();
#endif

    // If curve has 2 or fewer points, use linear equation
    if(m_points.size()<cubic)
       linear_curve_from_pts(); 

    // Use summation operator on equation
    for(int i=1; i<max; i++)
    {
        pos=static_cast<double>(i)/max;       // increment position from 0 to 1
        x = calc_coord(pos,'x');    // calculate x coordinate
        y = calc_coord(pos,'y');    // calculate y coordinate

        		// Debug. value check
		       std::cout<<"Point["<<i<<"] ("<<x<<", "<<y<<")"<<std::endl;
		       // Debug. value check

       Point* p = new Point(x,y);    // create new Point from coords and assign pointer
       m_curve.push_back(p);    // add new Point* to curve
   }
}

void Bezier::linear_curve_from_pts()
{
    // If Bezier only has one point, plot only that point
    if(m_points.size()==1)
        m_curve.push_back(m_points[0]);
    else
    {
        // y1 - y2 = m(x1 - x2)
        const int MAX=10;
        // Position on line (in percent), x coordinate, y coordinate
        double pos,x,y;    

        int slope = m_points[0]->get_coord('y') - m_points[1]->get_coord('y');
        slope = slope/(m_points[0]->get_coord('x') - m_points[1]->get_coord('x'));

        for(int i=1; i<MAX; i++)
        {
            pos=static_cast<double>(i)/static_cast<double>(MAX);
            x=calc_linear_coord(pos,'x');
            y=calc_linear_coord(pos,'y');

            Point* p = new Point(x,y);    // create new Point from coords and assign pointer
            m_curve.push_back(p);    // add new Point* to curve
        }
    }
}

double Bezier::calc_linear_coord(double pos, char axis)
{
    double result = m_points[1]->get_coord(axis)-m_points[0]->get_coord(axis);
    result*=pos;
    return result;
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

