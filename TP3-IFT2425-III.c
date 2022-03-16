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
float sumF(float u, int N, float x)
{
  float sum = 0.0;
  for (int i = 1; i <= N; i++)
  {
    x = u*x*(1.0-x);
    sum = sum + sqrtf(x);
  }
  return (float)2/(sum/N);
}

//double
double sumD(float u, int N, double x)
{
  double sum = 0.0;
  for (int i = 1; i <= N; i++)
  {
    x = u*x*(1.0-x);
    sum = sum + sqrt(x);
  }
  return (double)2/(sum/N);
}


int main()
{
  float u = 4.0; int N = 10000000;
  //float results
  printf("[0.20:>");printf("%12.10f", sumF(u, N, 0.2));printf("]\n");
  printf("[0.40:>");printf("%12.10f", sumF(u, N, 0.4));printf("]\n");
  printf("[0.60:>");printf("%12.10f", sumF(u, N, 0.6));printf("]\n");
  
  //double results
  printf("[0.20:>");printf("%12.10f", sumD(u, N, 0.2));printf("]\n");
  printf("[0.40:>");printf("%12.10f", sumD(u, N, 0.4));printf("]\n");
  printf("[0.60:>");printf("%12.10f", sumD(u, N, 0.6));printf("]\n");
                           
}
