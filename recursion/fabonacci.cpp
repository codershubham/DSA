#include <iostream>
using namespace std;
// recursion is not a good solution for this problem
int a = 0, b = 1;
int Fabonacci(int n) {  // n must be greater than 2
    
    if(n <= 1) {
        return n;
    }
    return Fabonacci(n-2) + Fabonacci(n-1);
}

int main()
{
    cout << Fabonacci(6) << endl;
    return 0;
}