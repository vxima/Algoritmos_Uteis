#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int Binary_Search(int arr[] , int x , int l , int r){
    int m = (l + r)/2;
    if( x < arr[m]){
        return Binary_Search(arr , x , l , m - 1);
    }
    else if(x > arr[m]){
        return Binary_Search(arr, x , m +1 , r);
    }
    else if(x==arr[m]){
        return m;
    }
    else{
        return -1;
    }
}
int main(){
    //test branch
    int arr[] = {1 ,2 ,3 , 4 , 5 , 6 , 7 , 8 , 9 , 10} ;
    int index = Binary_Search(arr , 1 , 0 , 9);
    cout << index << endl;
    

    return 0;
}