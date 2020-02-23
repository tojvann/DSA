#include <iostream>
using namespace std;
bool isPrime(int n){
    if(n == 1)
        return false;
    if(n == 2)
        return true;
    for(int i = 3; i*i <= n; i++)
    {
        if(n % i == 0)
        return false;
    }
    return true;
}
int main(){
    cout<< isPrime(20);
    return 0;
}
// The time complexity of the above algorithm would be O(sqrtN) for 1 Number
    