//float
float sumF(int u, int N, float x)
{
  float sum;
  for (int i = 1; i <= N, i++)
  {
    x = u*x*(1-x);
    sum = sum + x;
  }
  return 1/N * sum;
}

//double
double sumD(int u, int N, double x)
{
  double sum;
  for (int i = 1; i <= N, i++)
  {
    x = u*x*(1-x);
    sum = sum + x;
  }
  return 1/N * sum;
}


int main()
{
  //float results
  printf("[0.20:>");printf("%12,10f", sumF(u, N, 0.2);printf("]");
  printf("[0.40:>");printf("%12,10f", sumF(u, N, 0.4);printf("]");
  printf("[0.60:>");printf("%12,10f", sumF(u, N, 0.6);printf("]");
  
  //double results
  printf("[0.20:>");printf("%12,10f", sumD(u, N, 0.2);printf("]");
  printf("[0.40:>");printf("%12,10f", sumD(u, N, 0.4);printf("]");
  printf("[0.60:>");printf("%12,10f", sumD(u, N, 0.6);printf("]");
                           
}
