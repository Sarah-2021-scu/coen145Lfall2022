#include <omp.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>
#define jstart 122 

int main()
{
int j = jstart;
int n = 1000;
int a[n];
#pragma omp parallel for firstprivate(j)

  for(int i=1; i<=n; i++) {
    if(i == 1 || i == n)
	j = j + 1;
    a[i] = a[i] + j;
    printf("%d\n", a[i]);
}

return 0;
}

