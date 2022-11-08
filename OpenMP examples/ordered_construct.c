#include <stdio.h>
#include <omp.h>

void work(int k)
{
  #pragma omp ordered
    printf("%d\n", k);
}

void ordered_example(int lb, int ub, int stride)
{
  int i;
  #pragma omp parallel for ordered schedule(dynamic)
    for (i=lb; i<ub; i+=stride)
	    work(i);
}

int main()
{
	ordered_example(500, 200000, 500);
	return 0;
}
