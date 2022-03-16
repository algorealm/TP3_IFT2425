//------------------------------------------------------
// module  : Tp-IFT2425-I.c
// author  : Dereck Piche et Louis Thibault
// date    : 
// version : 1.0
// language: C++
// note    :
//------------------------------------------------------


#include <math.h>
#include <stdio.h>

//1
//returns output of integrated function 
float piIntFunct(float x)
{
    return (float)4*sqrt(1-x*x);
}

float trapezApprox(int nbIntervals)
{
    //width is h (width of intervals on the x axis)
    float width = (float)1.0 / nbIntervals;

    float piApprox = width / 2 * (piIntFunct(0.0) + piIntFunct(1.0));
	float x1, x2 = 0.0;

	for (int i=1; i <= nbIntervals-1; i++)
    {
		x1 = i/(float)nbIntervals;
		x2 = (i+1)/(float)nbIntervals;
		piApprox += width / 2 * (piIntFunct(x1) + piIntFunct(x2));
    }
    return piApprox;
}

//2

float* f_matrix_allocate_1d(int hsize)
{
    float* matrix;
    matrix = new float[hsize]; return matrix;
}

//generate a vector containing function evalutaions 
//at respective intervals
float* genVector(float* vector, int nbIntervals)
{   
    float width = (float) 1.0 / nbIntervals;

    //set halves of the first and last element of sum in vector
    vector[0] = width * piIntFunct(0.0)/2.0;
    vector[nbIntervals] = width * piIntFunct(1.0)/2.0;

	float x = 0.0;

	for (int i=1; i <= nbIntervals-1; i++)
    {
		x = i/(float)nbIntervals;
		vector[i] = width * piIntFunct(x);
    }
//    for (int i=1; i <= nbIntervals - 1; i++)
//    {
//        vector[i] = width * piIntFunct(x);
//        x = x + width;
//    }
    return vector;
}

//2-a

//recursive function takes vector as input and return 
//pairwise sum of it's elements
float pairSum(float* p, int first, int last)
{
    if (first == last)
    {
        return p[first];
    }
    else if (abs(last - first) == 1)
    {
        return p[first] + p[last];
    }
    else
    {
        int middle = abs(last-first)/2 + first;
        return pairSum(p, first, middle) + pairSum(p, middle + 1, last);
    }
}


//2-b

//function takes vector as input and returns
//Kahan sum of it's elements
float sumKahan(float* vector, int nbIntervals)
{
    float x,y,e,temp,sum; x = 0.0, y=x, e=x, temp=x, sum=x;


    for (int i=0; i <= nbIntervals; i++)
    {
        x = vector[i];
        y = x + e;
        temp = sum;
        sum = temp + y;
        e = (temp - sum) + y;
    }
    return sum;
}



int main()
{

    int nbIntervals = 5000000;
    float realPi = 3.14159265358979323846264338;
    float pi, error;

    //allocate memory for vector
    float* vector;
    vector = f_matrix_allocate_1d(nbIntervals+1);
    
    //generate vector with terms for sums
    genVector(vector, nbIntervals);


    //1
    printf("[1>Given_Order:]  Pi=");
    pi = trapezApprox(nbIntervals);
    printf("%22.20f", pi);
    //print error of approx. of pi
    error = abs(realPi - pi);
    printf("  Er=");
    printf("%12.10f", error);
    printf("\n");
    
    //2-a
    printf("[2>PairwiseSum]  Pi=");
    pi = pairSum(vector, 0, 5000000);
    printf("%22.20f", pi);
    //print error of approx. of pi
    error = abs(realPi - pi);
    printf("  Er=");
    printf("%12.10f", error);
    printf("\n");
    
    //2-b
    printf("[3>KahanSummat]  Pi=");
    pi = sumKahan(vector, nbIntervals);
    printf("%22.20f", pi);
    //print error of approx. of pi
    error = abs(realPi - pi);
    printf("  Er=");
    printf("%12.10f\n", error);
	


    return 0;
}
