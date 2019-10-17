#include <iostream>
using namespace std;

int Partition(int *arr, int low, int high){
	int pivot = arr[low];
	int i = low+1;
	int j = high;
	while(1){
		while(arr[i]<=pivot && i<=high) i++;
		while(arr[j]>pivot && j>=low) j--;
		if(i<j){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}//end of if
		else{
			arr[low] = arr[j];
			arr[j] = pivot;
			return j;
		}//end of else
	}//end of loop
}//end of method

void quickSort(int *arr, int low, int high){
	if(low<high){
		int pivot_pos = Partition(arr,low,high);
		quickSort(arr,low,pivot_pos-1);
		quickSort(arr, pivot_pos+1, high);
	}//end of if
}//end of method

void kthSmallest(int *arr, int start, int end, int k){
	quickSort(arr, start, end);
	cout<<arr[start+k]<<endl;
}//end of method

int main(){
	int *arr, *arr1, n, i, start, end ,k;
	cout<<"Enter number of elements :";
	cin>>n;
	arr = new int[n];
	arr1 = new int[n];
	cout<<"Enter array elements :\n";
	for(i = 0; i<n;i++)
		cin>>arr[i];
	i = 1;
	while(1){
		cout<<"Query "<<i<<" : start, end, k :";
		cin>>start>>end>>k;
		if(start == -1 || end == -1 || k == -1) break;
		for(int j=0; j<n; j++)
			arr1[j] = arr[j];
		kthSmallest(arr1, start-1,end-1, k-1);
		i++;
	}//end of while
	return 0;
}