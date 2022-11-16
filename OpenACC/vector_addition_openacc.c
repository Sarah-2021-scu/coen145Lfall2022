#include <stdio.h>
#include <stdlib.h>
float * r; /* output vector */
float * e; /*expected output values */
int n; /*vector length 1 */

void vecaddgpu (float *restrict r, float *a, float *b, int n) {
  int i = 0;
  #pragma acc kernels loop copyin(a[0:n], b[0:n]) copyout(r[0:n])
  for (i = 0; i < n; ++i)
  r[i] = a[i] + b[i];
}

void save_to_file(char * filename, int n)
{
  int i;
  FILE *fp;
  if ((fp = fopen (filename, "w")) == NULL)
{
    printf("could not open file %s\n", filename);
    return;
}
  fprintf(fp, "host\tGPU\n");
  for (i = 0; i < n; i++)
{
    fprintf(fp, "%d\t%d\n", r[i], e[i]);
}
  fclose (fp);
}

int main (int argc, char* argv[]) {
//  int n; /*vector length 1 */
  float * a; /* input vector 1 */
  float * b; /* input vector 2 */
//  float * r; /* output vector */
//  float * e; /* expected output values */
  int i, errs;
  if (argc > 1)
  n = atoi ( argv[1] );
  //char* filename = atoi (argv[2]);
  else
  n = 100000;
  a = (float*)malloc(n * sizeof(float));
  b = (float*)malloc(n * sizeof(float));
  r = (float*)malloc(n * sizeof(float));
  e = (float*)malloc(n * sizeof(float));
  for(i = 0; i < n; ++i) {
    a[i] = (float) (i+1);
    b[i] = (float) (1000*i);
}  
/* compute on the GPU */
vecaddgpu(r, a, b, n);
/* compute on the host to compare */
for (i = 0; i < n; ++i)
  e[i] = a[i] + b[i];
/* compare results */
  errs = 0;
  for (i = 0; i < n; ++i){
    if(r[i] != e[i]) 
{
      ++errs;
}
}
  save_to_file(argv[2], n);
  printf("%d errors found \n", errs);
  return errs;
}     
