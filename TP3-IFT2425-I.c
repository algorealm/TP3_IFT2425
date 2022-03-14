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
    vector[nbIntervals] = piIntFunct(1);

    float x_i = 0.0 + width;

    for (int i=1; i <= nbIntervals - 1; i++)
    {
        vector[i] = piIntFunct(x);
        x = x + width;
    }
    return vector;
}

float pairSum(float[] vector, int first, int last)
{
    if (first == last)
    {
        return vector[start];
    }
    else if (abs(start - end) == 1)
    {
        return vector[first] + vector[last];
    }
    else
    {
        int middle = (int)(abs(start-end)/2);
        return pairSum(vector, first, last) + pairSum(vector, middle+1, last);
    }
}

float PairwiseSum(int nbIterations)
{
    float[] vector = genVector(nbIterations);
    return pairSum(vector, 0, nbIterations);
}


//2-b
float sumKahan(float[] vector)
{
     float x,y,e,temp,sum = 0;

    float x_i = 0.0 + width;

    for (int i=0; i <= nbIntervals; i++)
    {
        x = vector[i]
        y = x + e
        temp = sum
        sum = temp + y
        e = (temp - sum) + y;
    }
    return sum;
}

float KahanSummat()
{
    float[] vector = genVector[5000000];
    return sumKahan(vector);
}



int main()
{
    float realPi = 3.14159265358979323846264338;
    float pi;
    //add log error !?
    //1-a
    printf("[1>Given_Order:]  Pi=");
    pi = trapezApprox(5000000);
    printf("%22.20f", pi);
    //print error of approx. of pi
    float error = realPi - pi;
    printf("  Er=");
    printf("%12.10f", error);
    printf("/n");
    
    //2-a
    printf("[2>PairwiseSum]  Pi=");
    pi = PairwiseSum(5000000);
    printf("%22.20f", pi);
    //print error of approx. of pi
    float error = realPi - pi;
    printf("  Er=");
    printf("%12.10f", error);
    printf("/n");
    
    //2-b
    printf("[3>KahanSummat]  Pi=");
    pi = KahanSummat(5000000);
    printf("%22.20f", pi);
    //print error of approx. of pi
    float error = realPi - pi;
    printf("  Er=");
    printf("%12.10f", error);
    printf("/n");

    return 0;
}
