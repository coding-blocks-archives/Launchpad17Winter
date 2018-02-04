// C program to sort an array with 0,1 and 2
// in a single pass
#include<stdio.h>
 
/* Function to swap *a and *b */
void swap(int *a, int *b);
 
// Sort the input array, the array is assumed to
// have values in {0, 1, 2}
void sort012(int arr[], int arr_size)
{
    int cur = 0;
    int be = 0;
    int en = arr_size - 1;
    while(cur != en){
        while(be < arr_size && arr[be] == 0){
            ++be; ++cur;
        }
        if (arr[cur] == 0){
            swap(&arr[cur], &arr[be]);
            ++be;
        }

        while(en >=0 && arr[en] == 2){
            --en;
        }
        if (arr[cur] == 2){
            swap(&arr[cur], &arr[en]);
            --en;
        }
        ++cur;
    }
}
 
/* UTILITY FUNCTIONS */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
/* Utility function to print array arr[] */
void printArray(int arr[], int arr_size)
{
    int i;
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("n");
}
 
/* driver program to test */
int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int i;
 
    sort012(arr, arr_size);
 
    printf("array after segregation ");
    printArray(arr, arr_size);
 
    getchar();
    return 0;
}