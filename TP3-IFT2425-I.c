//------------------------------------------------------
// module  : Tp-IFT2425-I.c
// author  : Dereck Piche
// date    : 
// version : 1.0
// language: C++
// note    :
//------------------------------------------------------
//  

#include <math.h>
#include <stdio.h>

//1
float piIntFunct(float x)
{
    return 4*sqrt(1-x*x);
}

float trapezApprox(float nbIntervals)
{
    float width = 1 / nbIntervals;
    float x = 0.0 + width;
    float piApprox = piIntFunct(0) + piIntFunct(nbIntervals * width);
    for (int i=1; i <= nbIntervals-1; i++)
    {
        piApprox = piApprox + width * piIntFunct(x);
        x = x + width;
    }
    return piApprox;
}

//2-a
float[] genVector(float nbIntervals)
{
    float width = 1 / nbIntervals;
    float vector[nbIntervals];
    vector[0] = piIntFunct(0);
    vector[nbIntervals-1] = piIntFunct(1);

    float x_i = 0.0 + width;

    for (int i=1; i <= nbIntervals - 1; i++)
    {
        vector[i] = piIntFunct(x);
        x = x + width;
    }
    return vector;
}



//2-b

int main()
{
    //print approximate of pi
    printf("Pi ~= ");
    printf("%22.20f", trapezApprox(5000000));
    //print error of approx. of pi
    float error = fabs(3.14159265358979323846264338 - trapezApprox(5000000));
    printf(" Approx error is = ");
    printf("%12.10f", error);

    return 0;
}
