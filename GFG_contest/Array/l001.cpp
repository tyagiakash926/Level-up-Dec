#include<bits/stdc++.h>
using namespace std;
// Q - 2
//https://practice.geeksforgeeks.org/problems/find-immediate-smaller-than-x/1/?track=sp-arrays-and-searching&batchId=152#
int immediateSmaller(int arr[], int n, int x)
{
    // your code here
    int smaller = 0;
    int imm=(int)1e9;
    for(int i=0;i<n;i++){
        if(x-arr[i]>0 && x-arr[i]<imm){
            imm = x-arr[i];
            smaller = arr[i];
        }   
    }
    return smaller==0?-1:smaller;
}
// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/?track=sp-arrays-and-searching&batchId=152#

int main(){
    return 0;
}