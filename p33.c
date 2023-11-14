#include<stdio.h>
void insertionsort(int arr[], int size)
{int i, j ,temp;
for(i=1;i<size;i++)
{
    temp=arr[i];
    j=i-1;
    while(j>=0&&arr[j]>temp)
    {
        arr[j+1]=arr[j];
        j= j-1;
    }
    arr[j+1]=temp;

}

}
void display(int arr[], int size){
    for (int i=0; i<size;i++)
    printf("%d\t", arr[i]);

}
int main(){
    int arr[]={40,20,50,10,30};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionsort( arr,size);
    display(arr,size);
}