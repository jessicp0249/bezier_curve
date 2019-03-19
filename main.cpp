/**
File: main.cpp
Description: Program will apply the Bezier class to create a curve from a given set of control points.
Author: Jessica Priester
Date Created: 3/7/2019
Email: jessicp0249@student.vvc.edu
*/

#include "point.h"
#include "bezier.h"
#include<iostream>

int main()
{

    Point* p1 = new Point(0,0);
    Bezier b(p1);
    Point* p2 = new Point(10,10);
    b.add_point(p2);
    b.curve_from_pts();

    b.print();

    b.reclaim();

    return 0;
}
