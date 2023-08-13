#include<iostream>
#include<vector>
using namespace std;
int CountPrime( int num )
{   
    int count = 0 ;
    vector<bool> prime( num+1 ,true);
    prime[0] = prime[1] = false;
    for( int idx = 2 ; idx < num ; idx++)
    {   
        if(prime[idx])
        {
            count++;
            for(int number =  2*idx ; number < num; number = number + idx )
            {
                prime[number] = 0;
            }
        }
    }    
    return count;
}
int main()
{
    int number;
    cin>>number;
    cout<<"The number of prime number before number is "<<CountPrime(number);
    return 0;
}