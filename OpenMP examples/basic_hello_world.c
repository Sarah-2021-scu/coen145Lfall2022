#include <stdio.h>
#include <time.h>

int main()
{

clock_t start, end;
double cpu_time_used;

start = clock();

int ID = 0;
printf("hello(%d)", ID);
printf("world(%d)\n", ID);

end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
//printf("%lf", &cpu_time_used);

}
