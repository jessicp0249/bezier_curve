/**
File: anchorpoint.h
Description: Header file for the AnchorPoint class
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
Date created: 4/23/2019
*/

#include<cmath>
#include "point.h"

#ifndef ANCHORPOINT_H
#define ANCHORPOINT_H
class AnchorPoint : public Point
{
private:
    bool m_smooth;
    Point* m_handleL;
    Point* m_handleR;

public:
    AnchorPoint(double x, double y);
    Point* get_handle(char LR);
    Point* get_other_handle(Point* p);
    bool is_smooth();

    void set_smooth(bool tf);
    void set_left_handle(double x, double y);
    void set_right_handle(double x, double y);

    void new_handle(double x, double y);    // Initializes handles
    void set_to_default();   // Reset handles and m_smooth to default values
    void sync_handle(Point* p);    // Sync given handle to the other

};
#endif
