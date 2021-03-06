#include<iostream>
using namespace std;

void display(int arr[],int n){
	for(int k=0;k<n;k++)
		cout<<arr[k]<<" ";
	cout<<endl;
}

void bubbleSort(int arr[],int n){
	cout<<"bubble sort:"<<endl;
	int temp,f=0;
	for(int i=0;i<n-1;i++){
		display(arr,n);
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				f=1;
			}
		}
		if(f==0)
		break;
	}
}

void merge(int arr[],int l,int mid,int h){
	int i=l,j=mid+1,k=l;
	int a[h+1];
	while(i<=mid && j<=h){
		if(arr[i]<arr[j]){
			a[k++]=arr[i];
			i++;
		}
		else if(arr[i]>arr[j]){
			a[k++]=arr[j];
			j++;
		}
	}
	
	while(i<=mid){
		a[k++]=arr[i];
		i++;
	}
	
	
	while(j<=h){
		a[k++]=arr[j];
		j++;
	}
	
	for(int m=l;m<=h;m++)
		arr[m]=a[m];
}

void mergesort(int arr[],int l,int h){
	if(l<h){
		int mid = (l+h)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,h);
		merge(arr,l,mid,h);
	}
}

//insertion sort
void insertionSort(int arr[], int n){
	cout<<"insertion sort"<<endl;
	for(int i=1;i<n;i++){
		int ele = arr[i];
		for(int j=i-1;j>=0;j--){
			if(arr[j]>ele){
				arr[j+1]=arr[j];
				arr[j] = ele;
			}
			else{
				arr[j+1]=ele;
				break;
			}
		}
	}
	display(arr,n);
}

//selection sort
void selectionSort(int arr[], int n){
	int i, j, k;
	for( i=0;i<n;i++){
		for( j=i, k=i;j<n;j++){
			if(arr[k]>arr[j]){
				k=j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
	cout<<"selection sort"<<endl;
	display(arr,n);
}

int main(){
	int arr[5] = {4,6,2,1,3};
	bubbleSort(arr,5);
	cout<<"merge sort:"<<endl;
	mergesort(arr,0,4);
	display(arr,5);
	return 0;
}
