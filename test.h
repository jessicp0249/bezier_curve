/**
File: test.cpp
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
    int result;
    if(i==0 || i==1 || n==i) result=1;
    else result=(factorial(n))/(i*factorial(n-i));

    return result;
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

void print_points(const std::vector<Point*>& m_points)
{
    // Print point coordinates
    double x,y;
    for(int i=0; i<m_points.size(); i++)
    {
        x=m_points[i]->get_x();
        y=m_points[i]->get_y();
        std::cout << "Point[" << i << "] (" << x << "," << y << ")" << std::endl;
    }
}

void fill_vector(std::vector<Point*>& m_points)
{
    Point* p;

    for(int i=0; i<2; i++)
    {
        p = new Point(i+5, i+10);
        m_points.push_back(p);
    }
}

void reclaim(std::vector<Point*>& m_points)
{
    for(int i=0; i<m_points.size(); i++)
    {
        delete m_points[i];
        m_points[i] = NULL;
    }
}

int main_old()
{
    std::vector<Point*> m_points;
    fill_vector(m_points);
    print_points(m_points);

    double t = 0.5;
    double x= calc_coord(t,'x',m_points);
    double y= calc_coord(t,'y',m_points);
    std::cout<< "t_point: ("<<x<< ", " <<y<< ")" << std::endl;

    return 0;
}
