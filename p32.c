#include<stdio.h>

void swap(int *x,int*y)
{
        int temp=*x;
        *x=*y;
        *y= temp;
}
void selectionsort(int arr[],int n)
{
    int i,j,minindex;
    for(i=0;i<n-1;i++)
    {
        minindex=i;
        for(j=i+1;j<n;j++)
        
            if(arr[j]<arr[minindex])
        
        minindex=j;
        if(minindex!=i)
        swap(&arr[minindex],&arr[i]);
    }
}
void print(int arr[], int size){
    int i;
    for(i=0;i<size;i++)
    printf("%d\t", arr[i]);
}
int main(){
    int arr[]={64,25,12,23,77,80};
    int n= sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr, n);
    print(arr,n);
}