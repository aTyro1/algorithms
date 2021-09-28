#include<bits/stdc++.h>
using namespace std;
void merge(int*,int*,int,int,int);
int partition(int*,int,int);
void heapify(int arr[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[largest])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(largest!=i)
	{
		int temp=arr[largest];
		arr[largest]=arr[i];
		arr[i]=temp;
		heapify(arr,n,largest);
	}
}
void heapsort(int arr[],int n)
{
	int i=n/2-1,temp;
	while(i>=0)
	{
		heapify(arr,n,i);
		i--;
	}
	i=n-1;
	while(i>0)
	{
		temp=arr[i];
		arr[i]=arr[0];
		arr[0]=temp;
		heapify(arr,i,0);
		i--;
	}
}

void bubbleSort(int arr[],int size)
{
	int i=size-1,j,temp,swapped=1;
	while(i>=0 && swapped)
	{
		swapped=0;
		j=0;
		while(j<=i-1)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapped=1;
			}
			j++;
		}
		i--;
	}
}
void selectionSort(int arr[],int size)
{
	int i,j,temp,min_key;
	i=0;
	while(i<size-1)
	{
		min_key=i;
		j=i+1;
		while(j<size)
		{
			if(arr[j]<arr[min_key])
				min_key=j;
			j++;
		}
		temp=arr[i];
		arr[i]=arr[min_key];
		arr[min_key]=temp;
		i++;
	}
}
void insertionSort(int arr[],int size)
{
	int i,j,key;
	i=1;
	while(i<size)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
		i++;
	}
}
void mergeSort(int arr[],int temp[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergeSort(arr,temp,low,mid);
		mergeSort(arr,temp,mid+1,high);
		merge(arr,temp,low,mid,high);
	}
}
void merge(int arr[],int temp[],int low,int mid,int high)
{
	int left_end,size,i,j;
	left_end=mid;
	i=low;
	size=high-low+1;
	mid=mid+1;
	while((low<=left_end) && (mid<=high))
	{
		cout<<arr[low]<<endl;
		cout<<arr[mid]<<endl;
		if(arr[low]<=arr[mid])
		{
			temp[i]=arr[low];
			i=i+1;
			low=low+1;
		}
		else
		{
			temp[i]=arr[mid];
			i=i+1;
			mid=mid+1;
		}
	}
	while(low<=left_end)
	{
		temp[i]=arr[low];
		low=low+1;
		i=i+1;
	}
	while(mid<=high)
	{
		temp[i]=arr[mid];
		mid=mid+1;
		i=i+1;
	}
	i=0;
	while(i<=size)
	{
		arr[high]=temp[high];
		high--;
		i++;
	}
}
void display(int arr[],int size)
{
	int i=0;
	while(i<size)
	{
		cout<<arr[i++]<<" ";
	}
	cout<<"\n";
}
void quickSort(int arr[],int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot=partition(arr,low,high);
		quickSort(arr,low,pivot-1);
		quickSort(arr,pivot+1,high);
	}
}
int partition(int arr[],int low,int high)
{
	int pivot,left,right,temp;
	left=low;
	right=high;
	pivot=arr[low];
	while(left<right)
	{
		while(arr[left]<=pivot)
			left++;
		while(arr[right]>pivot)
			right--;
		if(left<right)
		{
			temp=arr[left];
			arr[left]=arr[right];
			arr[right]=temp;
		}
	}
	arr[low]=arr[right];
	arr[right]=pivot;
	return right; 
}
int main()
{
	int arr[]={5,3,6,10,6,1,4,8};
	int *temp=new int[8];
	heapsort(arr,8);
	display(arr,8);
	return 0;
}
