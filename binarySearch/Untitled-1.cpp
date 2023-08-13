

#include<bits/stdc++.h>
using namespace std;


bool isPossible(int arr[], int n, int m, int mid){
	int pageSum = 0;
    int studentCount = 1;
    
    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }else{
            studentCount++;
            if(studentCount>m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    
    return true;
}

int allocateBooks(int arr[], int n, int m, int s, int e, int *p){
	if(s>e){
		return *p;
	}
	
	int mid = s+(e-s)/2;
	if(isPossible(arr, n, m, mid)){
		*p = mid;
		allocateBooks(arr, n, m, s, mid-1, p);
	}else{
		allocateBooks(arr, n, m, mid+1, e, p);
	}
    return *p;
}

int main(){
	int arr[4] = {10,20,30,40};
	int n=4, m=2;
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += arr[i];
	}
	int ans = -1 ;
	ans = allocateBooks(arr, n, m, 0, sum, &ans);
	
	cout<<ans;
	return 0;
}

