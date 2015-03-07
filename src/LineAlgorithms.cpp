#include "LineAlgorithms.h"


void LineAlgorithms :: DrawLineParametric(HDC hdc,int xx1,int yy1,int xx2,int yy2)
{
    COLORREF color =RGB(255,0,156);
    //xx1 < xx2
    int dx=xx2-xx1;
    int dy=yy2-yy1;
    float x=xx1;
    float y=yy1;
    SetPixel(hdc,round(x),round(y),color);
    float delta=1.0/max(dx,dy);
    for (float ro=0; ro<1; ro+=delta)
    {
        x=xx1+ro*dx;
        y=yy1+ro*dy;
        SetPixel(hdc,round(x),round(y),color);
    }
    SetPixel(hdc,xx2,yy2,color);
}
void LineAlgorithms::DrawLineMidpoint(HDC hdc,int xs,int ys,int xe,int ye)
{
    COLORREF color=RGB(255,0,0);
    SetPixel(hdc,xs,ys,color);
    int dx=xe-xs;
    int dy=ye-ys;
    int d = dx-(2*dy);
    int change1 = -(2*dy);
    int change2 = 2*(dx-dy);
    if(abs(dx)>=abs(dy))
    {
        int x=xs;
        double y=ys;
        while(x!=xe)
        {
            x++;
            if(d<=0)
            {
                y++;
                d+=change1;
            }
            else
            {
                d+=change2;
            }
            SetPixel(hdc,x,round(y),color);
        }
    }
    else
    {
        int y=ys;// as line may be increasing or decreasing
        double x=xs;
        while(y!=ye)
        {
            y++;
            if(d<=0)
            {
                x++;
                d+=change1;
            }
            else
            {
                d+=change2;
            }
            SetPixel(hdc,y,x,color);
        }
    }
}
void LineAlgorithms:: DrawLineCartesian (HDC hdc,int xs,int ys,int xe,int ye)
{
    COLORREF color =RGB (105,0,105);
    int dx=xe-xs;
    int dy=ye-ys;
    SetPixel(hdc,xs,ys,color);
    if(abs(dx)>=abs(dy))
    {
        int x=xs,xinc= dx>0?1:-1;// as line may be increasing or decreasing
        double y=ys,yinc=(double)dy/dx*xinc;
        while(x!=xe)
        {
            x+=xinc;
            y+=yinc;
            SetPixel(hdc,x,round(y),color);
        }
    }
    else
    {
        int y=ys,yinc= dy>0?1:-1;
        double x=xs,xinc=(double)dx/dy*yinc;
        while(y!=ye)
        {
            x+=xinc;
            y+=yinc;
            SetPixel(hdc,round(x),y,color);
        }
    }
}
LineAlgorithms::LineAlgorithms()
{
    //ctor
}

LineAlgorithms::~LineAlgorithms()
{
    //dtor
}
