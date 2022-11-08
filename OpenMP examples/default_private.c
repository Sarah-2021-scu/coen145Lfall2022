#include <stdio.h>
#include <omp.h>

int x, y, z[1000];

#pragma omp threadprivate(x)
  int main(int a) 
  {
    int c = 1;
    int i = 0;
    #pragma omp parallel default(none) private(a,i) shared(z,c)
    {
      int j = omp_get_num_threads();	/* O.K. - j is declared within parallel region */
      a = z[j]; 			/*O.K. - a is listed in private clause * /
      /* -s is listed is shared clause */
      x = c;	/* O.K. - x is threadprivate */
      /* -c had const-qualified type and is listed in shared clause */
     
      /* Error - Cannot refernce y in the firstprivate clause */
        for (i=0; i<10; i++)
        {
          z[i] = i;	/* O.K. -i is the lop iteration variable */
          printf("%d\n", z[i]);
        }
       }
}
