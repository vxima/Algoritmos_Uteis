#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
#define MOD ll(1e9 + 7)
using namespace std;

vector<ll> dp(1e4 , -1);
ll muro(int n){
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 5;

    if(dp[n] != -1) return dp[n];//se ja calculou entao retorna o valor 

    else{
        dp[n] = ((muro(n-1))%MOD + (ll(4)*muro(n-2))%MOD + (ll(2)*muro(n-3))%MOD)%MOD;
        return dp[n];
    }
}
int main(){
    int n;
    cin >> n;
    cout << muro(n) << endl;


    return 0;
}