#include <stdio.h>
#include <omp.h>
#define SIZE 1000000

int istart = 0;
int iend = 1000;
int array1[SIZE];
int array2[SIZE]; 
int array3[SIZE];

int array_init(int, int)
{
  int i;
  for (i=istart; i<iend; i++)
{
    array1[i] = i;
    array2[i] = iend - i;
}
}

int main()
{
  int value, i;
  #pragma omp parallel private(istart, iend)
  array_init(istart, iend);
  for (i=istart; i<=iend; i++)
  {
    array3[i] = array2[i] - array1[i];
  }
  
  #pragma omp barrier
  value = array3[istart] + array3[0];
  printf("%d", value);
}     
