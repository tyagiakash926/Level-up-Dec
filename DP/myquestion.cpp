#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
//leetcode 392 //memo
int sub(string &s,string &p,int n,int m,vector<vector<int>>& dp){
    if(n==0 || m==0){
        if(n == 0) return dp[n][m] = 1;
        if(m == 0 && n!=0) return dp[n][m]=0;
    }
    if(dp[n][m] != -1) return dp[n][m];
    if(s[n-1]==p[m-1]) return sub(s,p,n-1,m-1,dp);
    else{
        int res = 0;
        res = res || sub(s,p,n,m-1,dp);
        dp[n][m] = res;
    }
    return dp[n][m];
}
bool isSubsequence(string s, string p) {
    int n = s.length();
    int m = p.length();
    if(n>m) return false;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return sub(s,p,n,m,dp);
}
// space optimize two pointer
bool isSubsequence(string s, string p) {
    int n = s.length();
    int m = p.length();
    if(n>m) return false;
    int i=0;
    int j=0;
    while(j<m && i<n){
        if(p[j]==s[i]){
            i++;
            j++;
        }else{
            j++;
        }
    }
    return (i==n);
}




int main(){
    return 0;
}