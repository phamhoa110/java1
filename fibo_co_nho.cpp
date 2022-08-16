#include <iostream>

using namespace std;

int *k;
long fiBo(int n){
    if(n == 1 || n == 2) k[n] = 1;
    else k[n] = fiBo(n - 1) + fiBo(n - 2);
    return k[n];
}
int main()
{
    int n = 7;
    k = new int[n];
    cout <<fiBo(n)<< endl;
    return 0;
}
