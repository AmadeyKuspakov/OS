#include <stdio.h>
#include <float.h>
#include <limits.h>

int main()
{
    int i = INT_MAX;
    printf("Max int is %d", i);
    printf(", its size is %d\n", sizeof(i));
    float f = FLT_MAX;
    printf("Max int is %f", f);
    printf(", its size is %d\n", sizeof(f));
    double d = DBL_MAX;
    printf("Max int is %f", d);
    printf(", its size is %d\n", sizeof(d));
    return 0;
}
