#include <stdio.h>
#include <float.h>
#include <limits.h>

int main()
{
    int i;
    int j;
    int k;
    int n;
    printf("Please specify n: ");
    scanf("%d", &n);
    printf("This is n: %d", n);
    for(i = 0; i<n; i = i+1){
        for(j = 0; j <n-1; j = j+1){
            if(j>=n-1-i){
                printf("*");
            }
        }
        printf("*");
        for(k = n+1; k <2*n-1; k = j+1){
            if(k<n+i){
                printf("*");
            }
        }
        printf("\n");
    }
}
