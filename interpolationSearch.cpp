#include<bits/stdc++.h>
using namespace std;
int interpolationSearch(int arr[],int data,int size)
{
    int low=0,high=size-1,mid;
    while(low<=high)
    {
        mid=low+(((data-arr[low])*(high-low))/(arr[high]-arr[low]));
        //linear interpolation is used to find mid value
        if(data==arr[mid])
        return mid+1;
        if(data<arr[mid])
        high=mid=1;
        else
        low=mid+1;
    }
    return -1;
}
int main()
{
    int test_arr[]={6,3,7,1,9,2,5,4};
    //first we sort the array
    sort(test_arr,test_arr+8);
    //we find the position of 7
    cout<<interpolationSearch(test_arr,7,8)<<endl;
    return 0;
}