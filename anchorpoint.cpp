/**
File: anchorpoint.cpp
Description: Implementation for the AnchorPoint class
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
Date created: 4/23/2019
*/

#include<cmath>
#include<ctgmath>
#include "point.h"
#include "anchorpoint.h"

AnchorPoint::AnchorPoint(double x, double y) : Point(x,y)
{
    set_to_default();
}

Point* AnchorPoint::get_handle(char LR)
{
    assert(LR=='l' || LR=='r');
    Point* ptr=NULL;

    if(LR=='l')
        Point* ptr=m_handleL;
    else if(LR=='r')
        Point* ptr=m_handleR;

    return ptr;
}

Point* AnchorPoint::get_other_handle(Point* p)
{
    Point* other_handle;
    if(p==m_handleL)
        other_handle=m_handleR;
    else if(p==m_handleR)
        other_handle=m_handleL;
    else
    {   // Throw invalid point reference
    }
    return other_handle;
}

bool AnchorPoint::is_smooth()
{
    return m_smooth;
}

void AnchorPoint::set_smooth(bool tf)
{
    m_smooth=tf;
}

void AnchorPoint::set_left_handle(double x, double y)
{
    if(m_handleL==NULL)
        new_handle(x,y);
    else
    {
        m_handleL->Point::set_xy(x,y);
        if(is_smooth())
            sync_handle(m_handleR);
    }
}

void AnchorPoint::set_right_handle(double x, double y)
{
    m_handleR->Point::set_xy(x,y);
}

void AnchorPoint::new_handle(double x, double y)
{
    m_handleL->Point::set_xy(x,y);
    sync_handle(m_handleR);
}

void AnchorPoint::set_to_default()
{
    m_smooth=false;
    m_handleL=NULL;
    m_handleR=NULL;
}

void AnchorPoint::sync_handle(Point* p)
{
    Point* ref=get_other_handle(p);   // Handle that is already set
    
    double slope = get_slope(ref);  // Desired slope based on ref handle
    double length;  // Desired length of handl p
    // If handle p doesn't exist yet, get length from ref handle
    if(p==NULL)
        length = distance_from(ref);    // Distance from anchor to ref
    else length = distance_from(p);   // Distance from anchor to p 

    double rise=0;  // Vertical shift from anchor to p; to be determined
    double run=0;   // Horizontal shift from anchor to p; to be dertermined

    // if slope is undefined (handles are flat)
    if(std::isnan(slope)==0)
        run=length;
    else
    {
        run = sqrt(length*length/(slope*slope+1));
        rise = slope*run;
    }

    // Set rise/run of p handle to opposite direction from ref handle
    if(get_x() < ref->get_x())
        run*= -1;
    if(get_y() < ref->get_y())
        rise*= -1;

    // Add x and y shift to anchor coordinates to get p handle coordinates
    run+=get_x();
    rise+=get_y();

    // Set new coordinates
    p->set_xy(run,rise);
}
