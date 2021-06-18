#include <bits/stdc++.h>
#include <iostream>

using namespace std;


void merge(int arr[] , int l , int m , int r){
    int i , j , k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1] , R[n2];

    for(i=0 ; i<n1 ; i++){
        L[i] = arr[l+i];
    }
    for(i = 0 ; i<n2 ; i++){
        R[i]= arr[m+1 + i];
    }
    i = 0; 
    j = 0; 
    k = l;
    while(i < n1 && j <n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k]= R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k]= R[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[] , int l , int r){
    if(r > l){
        int m = (l+r)/2;
        MergeSort(arr , l , m); //left side
        MergeSort(arr , m+1 , r);//right side
        merge(arr , l  , m , r);
    }
}
int main(){
    //test branch
    int array[] = {6 , 1 , 3, 8 , 4};
    MergeSort(array , 0 , 4);
    for(int i = 0 ; i < 5 ; i++){
        cout << array[i] << " " ;
    }
    cout << endl;

    

    return 0;
}