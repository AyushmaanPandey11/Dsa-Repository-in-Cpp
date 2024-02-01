#include<bits/stdc++.h>
using namespace std;
long double LinearSearch(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> howmany(n-1,0);
	for( int idx =1 ; idx <= k; idx++ )
	{
		/*
		loops for placing and find the maxvalue and idx for placing the idxth gas station
		and then for next iteration, maxvalue and maxidx will again be -1 for get new \
		maxvalue and maxidx as after putting one station in previous loop, section lengths 
		change. 
		*/
		long double maxVal = -1;
		int maxIdx = -1;
		for( int stations = 0 ; stations <n-1; stations++ )
		{
			long double diff = arr[stations+1]-arr[stations];
			long double sectionLen = diff/(long double)(howmany[stations]+1);
			if( maxVal < sectionLen )
			{   
				maxVal = sectionLen;
				maxIdx = stations;
			}
		}
		howmany[maxIdx]++;
	}	
	long double ans = -1;
	for( int idx=0;idx<n-1;idx++ )
	{
		long double sectionLen = (long double)(arr[idx+1]-arr[idx])/(long double)(howmany[idx]+1);
		ans = max(ans,sectionLen);
	}
	return ans;
}
long double priorityQueue(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> howmany(n-1,0);
	priority_queue<pair<long double,int>> pq;
	for( int idx =0 ; idx < n-1; idx++ )
	{
		pq.push({arr[idx+1]-arr[idx],idx});
	}	
	for( int station=1; station <=k;station++ )
	{
		auto tp = pq.top();
		pq.pop();
		int secIdx =tp.second;
		howmany[secIdx]++;
		long double diff = arr[secIdx+1]-arr[secIdx];
		long double secLen = diff/(long double)(howmany[secIdx]+1);
		pq.push({secLen,secIdx});
	}
	return pq.top().first;
}

long double gasStationreq(vector<int> &arr, long double dist)
{
	int cnt=0;
	for( int idx=1;idx<arr.size();idx++ )
	{
		int numberinbetween = (arr[idx]-arr[idx-1])/dist;
		if( (arr[idx]-arr[idx-1])/dist == numberinbetween*dist )
		{
			numberinbetween--;
		}
		cnt+=numberinbetween;
	}
	return cnt;
}
long double BinarySearch(vector<int> &arr, int k){
	int n = arr.size();
	long double low =0;
	long double high =0;
	for( int idx=1; idx<n;idx++ )
	{
		high = max(high,(long double)arr[idx]-arr[idx-1]);
	}
	long double diff = 1e-6;
	while( high - low > diff)
	{
		long double mid = (low+high)/2.0;
		int cnt = gasStationreq(arr,mid);
		if(cnt>k)	low = mid;
		else	high = mid;
	}
	return high;
}
int main()
{
    vector<int> arr{1,2,3,4,5,6,7};
    int k =6;
    cout<<"Using for loop "<<endl;
    cout<<LinearSearch(arr,k)<<endl;
    cout<<"Using Priority Queue: "<<endl;
    cout<<priorityQueue(arr,k)<<endl;
    cout<<"Using Binary Search "<<endl;
    cout<<BinarySearch(arr,k)<<endl;
    return 0;
}