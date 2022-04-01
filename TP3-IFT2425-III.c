//------------------------------------------------------
// module  : Tp-IFT2425-III.c
// author  : Dereck Piche et Louis Thibault
// date    : 
// version : 1.0
// language: C++
// note    :
//------------------------------------------------------


#include <math.h>
#include <stdio.h>


//float
void sumF(float* vector, float u, int N, float x)
{
  for (int i = 0; i <= N; i++)
  {
    x = u*(sqrtf(x)+x)*(sqrtf(x)-x);
    vector[i] = sqrtf(x);
  }
}

float* f_matrix_allocate_1d(int hsize)
{
    float* matrix;
    matrix = new float[hsize]; return matrix;
}


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

//double
void sumD(double* vector, float u, int N, double x)
{
  for (int i = 1; i <= N; i++)
  {
    x = u*(x-x*x);
    vector[i] = sqrt(x);
  }
}


double* d_matrix_allocate_1d(int hsize)
{
    double* matrix;
    matrix = new double[hsize]; return matrix;
}

double pairSum(double* p, int first, int last)
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


int main()
{
  float u = 4.0; int N = 10000000;

  float* Fvector;
  Fvector = f_matrix_allocate_1d(N);
  sumF(Fvector, u, N, 0.2);
  float f0_2 = 2/(pairSum(Fvector, 0, N)/N);
  sumF(Fvector, u, N, 0.4);
  float f0_4 = 2/(pairSum(Fvector, 0, N)/N);
  sumF(Fvector, u, N, 0.6);
  float f0_6 = 2/(pairSum(Fvector, 0, N)/N);
  
  double* Dvector;
  Dvector = d_matrix_allocate_1d(N);
  sumD(Dvector, u, N, 0.2);
  double d0_2 = 2/(pairSum(Dvector, 0, N)/N);
  sumD(Dvector, u, N, 0.4);
  double d0_4 = 2/(pairSum(Dvector, 0, N)/N);
  sumD(Dvector, u, N, 0.6);
  double d0_6 = 2/(pairSum(Dvector, 0, N)/N);
  
  //float results
  printf("[0.20:>");printf("%12.10f", f0_2);printf("]\n");
  printf("[0.40:>");printf("%12.10f", f0_4);printf("]\n");
  printf("[0.60:>");printf("%12.10f", f0_6);printf("]\n");

  //double results
  printf("[0.20:>");printf("%12.10f", d0_2);printf("]\n");
  printf("[0.40:>");printf("%12.10f", d0_4);printf("]\n");
  printf("[0.60:>");printf("%12.10f", d0_6);printf("]\n");
                           
}
