#include <iostream>
using namespace std;
#define ll long long

void prime_sieve(int* p){
    for(int i = 3; i <= 1000000; i+=2)
    p[i] = 1;
    for(ll i = 3; i <= 1000000; i+=2)
    {
        if(p[i]==1)
        {
            for(ll j = i*i; j<= 1000000; j+=i)
            p[j] = 0;
        }
    }
    //Special Cases
    p[2] = 1;
    p[1] = p[0] = 0;
}
int main(){
    int n;
    cin >> n;
    int p[10000007] = {0};
    prime_sieve(p);
    for (int i = 0; i <= n; i++)
    {
        if(p[i] == 1)
        cout<< i << endl;
    }
    return 0;
}