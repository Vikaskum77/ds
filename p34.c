#include<stdio.h>
 
int binaryserach(int arr[], int search,int low, int high)
{
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==search)
        return mid;
        else if(arr[mid]>search)
        high = mid-1;
        else 
        low=mid+1;
    }
    return -1;
}
int main(){
    int arr[]={9,13,16,21,32,69,82,97};
     int size= sizeof(arr)/sizeof(arr[0]);
     int search= 82;
     int result = binaryserach(arr,search,0,size-1);
     if(result==-1)
     {
        printf("elelment not present");

     }
     else
     printf("elelment is at index : %d", result);

}