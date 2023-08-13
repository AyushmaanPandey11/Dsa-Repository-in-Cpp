#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void sieve( int n )
{   
    vector<int> prime;
    vector<bool> isPrime(n+1, true);
    for( int idx = 2; idx <= n ; idx++)
    {
        if(isPrime[idx])
        {
            prime.push_back(idx);
            for( int nonprime = 2*idx; nonprime <= n ; nonprime+= idx)
            {
                isPrime[nonprime]=false;
            }
        }
    }
}
void SegmentedSieve( int low , int high )
{   
    vector<int> prime;
    long long sq = sqrt(high);
    sieve(sq);
    vector<bool> isPrime( high-low+1 , true );
    for( int p : prime)
    {
        int sm = (low/p)*p;
        if(sm<low)
        sm += p;
        for( int m = sm; sm<=high ; m+= p)
        {
            isPrime[m - low]=false;
        }
    }
    for(int idx=low; idx <= high ; idx++)
    {
        if( isPrime[idx - low] == true )
        cout<<idx<<" ";
    }
}
int main()
{
    
    int high , low;
    cin>> low;
    cin >> high;
    SegmentedSieve(low, high);
    
    return 0;
}