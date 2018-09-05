#include<stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++){
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1]){
              swap(&arr[j], &arr[j+1]);
           }
       }
   }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++){
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[] = {7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}