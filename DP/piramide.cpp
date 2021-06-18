#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;

using namespace std;
vector<vector<int>> mat(101 , vector<int>(101));
vector<vector<ll>> dp(101 , vector<ll>(101));

void initial(){
    for(int i = 0 ; i<101;i++){
        for(int j=0; j<101; j++){
            dp[i][j] = -1;
        }
    }
}
int custo(int l , int c){
    int sum=0;
    for(int i = c ; i < c+l ; i++){
        sum = sum +  mat[l-1][i];
    }
    return sum;
}
int piramide(int n,  int c){
    //de baixo para cima
    if(n==1){
        dp[n][c] =mat[n-1][c];
        return dp[n][c];
    }   
    else if(dp[n][c] != -1){
        return dp[n][c];
    }
    else{
        dp[n][c] = custo(n , c) + min(piramide(n-1 , c) , piramide(n-1 , c+1));
        return dp[n][c];
    }
}
int main(){
    int n, aux;
    cin >> n;
    initial();
    for(int i = 0 ; i<n;i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    cout << piramide(n , 0) << endl;


    return 0;
}