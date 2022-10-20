#include <stdio.h>
#include <omp.h>

int lastpriv (int n)
{
  int i;
  int a[n], b[n]; 
  for (int k = 0; k<n-1; k++)
    b[k] = k;
  #pragma omp parallel
  {
    #pragma omp for lastprivate(i)
      for (i=0; i<n-1; i++)
        a[i] = b[i] + b[i+1];
  }
  
  a[i] = b[i];		/* i == n-1 here */
  printf("%f", a[i]); 
}

int main()
{
  int n = 100;
  lastpriv(n);
 
}
