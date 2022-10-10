#include <stdio.h>
#include <omp.h>
#define N 100000

int main()
{
	int i;
	float a[N] = { 2 };
	float b[N] = { 4 };
	double itime, ftime, exec_time;
	itime = omp_get_wtime();

#pragma omp parallel for 
	for (i = 0; i < N; i++)		/* i is private by default */
		b[i] = (a[i] + a[i-1]) / 2.0;
	
	ftime  = omp_get_wtime();
	exec_time = ftime - itime;
	printf("\n\nTime taken is %f", exec_time);

}
