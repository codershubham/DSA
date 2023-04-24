#include <iostream>
using namespace std;

int Factorial(int n) {  // only positive number should be input
    
    if(n == 1 || n == 0) {
        return 1;
    }
    return n*Factorial(n-1);
}

int main()
{
    cout << Factorial(5) << endl;
    return 0;
}
