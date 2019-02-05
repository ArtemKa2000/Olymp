#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    bool isFound = false;
    bool isPrime;
    vector<int> primes;
    for(int i=2;i*i<=n;i++){
        isPrime = true;
        for(int j = 0; j<primes.size();j++)
            if(i%primes[j]==0)
                isPrime = false;
        if(isPrime){
            primes.push_back(i);
        }
    }

    for(;m<=n;m++){
        isPrime=true;
        for(int j = 0; j<primes.size();j++)
            if(m%primes[j]==0)
                isPrime = false;
        if(isPrime){
            isFound = true;
            //primes.push_back(m);
            cout<<m<<'\n';
        }
    }
    if(!isFound)
        cout<<"Absent";
    return 0;
}
