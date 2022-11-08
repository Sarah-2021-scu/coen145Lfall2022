#include <stdio.h>
#include <omp.h>
#define N 100
int main(void)
{
  float a[N], b[N/2];
  int i, j, nthreads;
  double itime, ftime, exec_time;

  for (i=0; i<N; i++)
    a[i] = i + 1;
  j = 0;

  omp_set_dynamic(0);
  omp_set_num_threads(4);
  
  itime = omp_get_wtime();
  
  #pragma omp parallel for 
  #pragma omp linear(j:1)
  for(i=0; i<N; i+=2) {
    b[j] = a[i] * 2.0f;
    j++;
  nthreads = omp_get_thread_num();
} 

  ftime  = omp_get_wtime();
  exec_time = ftime - itime;
  printf("Threads %d\n", nthreads);
  printf("\n Time taken %f", exec_time);
  printf("output pattern %d %f %f\n", j, b[0], b[j-1]); /*print out: 50 2.0 198.0*/
  return 0;
}
