/**
File: main.cpp
Description: Program will apply the Bezier class to create a curve from a given set of control points.
Author: Jessica Priester
Date Created: 3/7/2019
Email: jessicp0249@student.vvc.edu
*/

#include "point.h"
#include "bezier.h"
#include<vector>
#include<iostream>

int factorial(int x)
{
    int result = x;
    for(int i=x-1; i>1; i--)
        result*=i;

    return result;
}

int pwr(int base, int exp)
{
    int result=1;
    for(int i=exp; i>0; i--)
        result*=base;

    return result;
}

int combin(int n, int i)
{
    return (factorial(n))/(i*factorial(n-1));
}

double calc_coord(double t, char axis, const std::vector<Point*> &m_points)
{
    int n = m_points.size()-1;  // degree of the curve, based on number of Points

    double coord=0;    // coordinate value, to be calculated
    // Complete formula for Bezier curve. Traverses all Points* in m_points
    for(int i=0; i<=n; i++)
    {
        coord += combin(n,i)*pwr(1-t, n-i)*pwr(t, i)*m_points[i]->get_coord(axis);
    }

    return coord;
}
 

int main()
{
//    Point* anchor1= new Point(0,0);
//    Bezier path(anchor1);
    std::vector<Point*> m_points;
    
    Point* p;

    for(int i=0; i<10; i++)
    {
        p = new Point(i+1, i);
        m_points.push_back(p);
    }

    // Print point coordinates
    double x,y;
    for(int i=0; i<m_points.size(); i++)
    {
        x=m_points[i]->get_x();
        y=m_points[i]->get_y();
        std::cout << "Point[" << i << "] (" << x << "," << y << ")" << std::endl;
    }

    double t = 0.5;
    x= calc_coord(t,'x',m_points);
/*
    y= calc_coord(t,'y',m_points);
    std::cout << "t_point: ("<< x << y << ")" << std::endl;
*/

    for(int i=0; i<m_points.size(); i++)
    {
        delete m_points[i];
        m_points[i] = NULL;
    }
    return 0;
}
