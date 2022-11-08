#include <math.h>
#include <stdio.h>
#include <omp.h>

int main()
{

float *x;
int *y;
int i, b, c, n;
float a, d;
a = 0.0;
b = 0;
c = y[0];
d = x[0];

#pragma omp parallel for private(i) shared(x, y, n) reduction(+:a) reduction(^:b) reduction(min:c) reduction(max:d)
  for (i=0; i<n; i++) {
    a += x[i];
    b ^= y[i];
    if (c > y[i])
      c = y[i];
      d = fmaxf(d, x[i]);
}
printf("\na = %f", a);
printf("\nb = %d", b);
printf("\nc = %d", c);
printf("\nd = %f", d);
return 0;
}
