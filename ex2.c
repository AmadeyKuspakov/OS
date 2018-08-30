#include <stdio.h>
#include <float.h>
#include <limits.h>

int main()
{
    char str[20];
    int i;
    scanf("%[^\t\n]s", str);
    printf("This is ur string %s\n", str);
    int len = strlen(str);
    printf("Length is %d\n", len);
    for(i=0; i<len; i = i + 1){
        printf("%c", str[len - 1 - i]);
    }
    return 0;
}

int strlen(char str[]){
    return sizeof(str);
}
