
#include <iostream>

using namespace std;
int fatorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n * fatorial(n - 1);
    }
}
int main()
{   
    //exemplo da funcao fatorial
    cout << fatorial(10) << endl;

    return 0;
}
