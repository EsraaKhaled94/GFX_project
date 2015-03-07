#ifndef LINEALGORITHMS_H
#define LINEALGORITHMS_H
#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <math.h>

class LineAlgorithms
{
    public:
        LineAlgorithms();
        virtual ~LineAlgorithms();
        static void DrawLineParametric(HDC hdc,int xx1,int yy1,int xx2,int yy2);
        static void DrawLineMidpoint(HDC hdc,int xs,int ys,int xe,int ye);
        static void DrawLineCartesian (HDC hdc,int xs,int ys,int xe,int ye);
    protected:
    private:
};

#endif // LINEALGORITHMS_H
