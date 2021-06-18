#include <bits/stdc++.h>
#include <iostream>
#define MAX 304
typedef long long ll;
using namespace std;

vector<ll> vinhos;
ll DP[MAX][MAX][MAX];
int n=0;
void initial(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            for(int k=0;k<MAX;k++){
                DP[i][j][k] = -1;
            }
        }
    }
}
ll preco(int ano , int i){
    return ano*vinhos[i];
}

ll adega(int i , int j , int a){
    //pegar o da direita ou o da esquerda
    if(a>n) return 0;
    //tenho tres estados: index da esquerda , index da direita e ano 
    if(DP[i][j][a] != -1) return DP[i][j][a];
    //recursao: 
    else{
        DP[i][j][a] = max(preco(a , i) + adega( i+1 , j  , a + 1 ) , preco(a , j) + adega(i , j-1 , a + 1));
        return DP[i][j][a];
    }
}

int main(){
    ll aux;
    cin >> n;
    initial();
    for(int i=0;i<n;i++){
        cin >> aux;
        vinhos.push_back(aux);
    }
    cout << adega(0 , n-1 , 1) << endl;

    
    return 0;
}