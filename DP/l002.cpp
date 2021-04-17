#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
// leetcode 516
int longestPalindromeSubseq_rec(string &s,int i,int j){
    if(i>=j) return (i>j)?0:1;
    if(s[i]==s[j]) return longestPalindromeSubseq_rec(s,i+1,j-1) + 2;
    else return max(longestPalindromeSubseq_rec(s,i,j-1),longestPalindromeSubseq_rec(s,i+1,j));
}

int longestPalindromeSubseq_memo(string &s,int i,int j,vector<vector<int>>& dp){
    if(i>=j) return dp[i][j] = (i==j)?1:0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) return dp[i][j] = longestPalindromeSubseq_memo(s,i+1,j-1,dp) + 2;
    else return dp[i][j] = max(longestPalindromeSubseq_memo(s,i,j-1,dp),longestPalindromeSubseq_memo(s,i+1,j,dp));
}

int longestPalindromeSubseq_dp(string &s,int I,int J,vector<vector<int>>& dp){
    int n = s.length();
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            if(i==j){
                dp[i][j]=1;
                continue;
            }
            if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
            else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return dp[I][J];
}

// Longest Palindromic String
string longestPalindromeSubseq_String(string& s) {
    int n = s.length();
    vector<vector<string>> dp(n,vector<string>(n,""));
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            if(i==j){
                dp[i][j] = string(1,s[i]);
                continue;
            }
            if(s[i]==s[j]){
                dp[i][j] = string(1,s[i]) + dp[i+1][j-1] + string(1,s[i]);
            }else{
                dp[i][j] = (dp[i + 1][j].length() > dp[i][j - 1].length()) ? dp[i + 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[0][n-1];
}

// Through Back Engineering
string longestPalindromeSubseq_String(string& s,int i,int j,vector<vector<int>>& dp){
    if(i>=j) return (i>j)?"":string(1,s[i]);

    string ans ="";
    if(s[i]==s[j]){
        string rr = longestPalindromeSubseq_String(s,i+1,j-1,dp);
        ans = string(1,s[i]) + rr + string(1,s[i]);
    }else{
        if(dp[i + 1][j] > dp[i][j - 1]){
            string rr = longestPalindromeSubseq_String(s,i+1,j,dp);
            ans=rr;
        }else{
            string rr =longestPalindromeSubseq_String(s,i,j-1,dp);
            ans=rr;
        }
    }
    return ans;
}

// leetcode 115
int numDistinct_rec(string &s,string &t,int n,int m){
    if(m==0) return 1;
    if(n<m) return 0;
    int count=0;
    if(s[n-1]==t[m-1]){
        count += numDistinct_rec(s,t,n-1,m-1);
        count += numDistinct_rec(s,t,n-1,m);
    }else{
        count += numDistinct_rec(s,t,n-1,m);
    }
    return count;
}

int numDistinct_memo(string &s,string &t,int n,int m,vector<vector<int>> &dp){
    if(m==0) return dp[n][m] = 1;
    if(n<m) return dp[n][m] = 0;
    if(dp[n][m] != -1) return dp[n][m]; 
    if(s[n-1]==t[m-1]){
        int single = numDistinct_memo(s,t,n-1,m-1,dp);
        int pairup = numDistinct_memo(s,t,n-1,m,dp);
        dp[n][m] = single + pairup;
    }else{
        dp[n][m] = numDistinct_memo(s,t,n-1,m,dp);
    }
    return dp[n][m];
}

int numDistinct_dp(string &s,string &t,int N,int M,vector<vector<int>> &dp){
    cout<<"HIII"<<N<<M;
    for(int n=0;n<=N;n++){
        for(int m=0;m<=M;m++){
            if(m==0){
                dp[n][m] = 1;
                continue;
            }
            if(n<m){                   
                dp[n][m] = 0;
                continue; 
            }
            if(s[n-1]==t[m-1]){  // n==0 toh handle n-1 = 0-1 => -1
                int single = dp[n-1][m-1];
                int pairup = dp[n-1][m];
                dp[n][m] = single + pairup;
            }else{
                dp[n][m] = dp[n-1][m];
            }
        }
    }
    return dp[N][M];
}

// longest common subsequence 

int longestCommonSubsequence(string &text1, string &text2, int n, int m, vector<vector<int>>& dp) {
    if (n == 0 || m == 0) {
        return dp[n][m] = 0;
    }

    if (dp[n][m] != -1)
        return dp[n][m];

    if (text1[n - 1] == text2[m - 1])
        dp[n][m] = 1 + longestCommonSubsequence(text1, text2, n - 1, m - 1, dp);
    else
        dp[n][m] = max(longestCommonSubsequence(text1, text2, n, m - 1, dp),
                longestCommonSubsequence(text1, text2, n - 1, m, dp));

    return dp[n][m];
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return longestCommonSubsequence(text1, text2, n, m, dp);
}

// max uncroessed bridge
int uncross(vector<int> &s,vector<int> &p){
    int N = s.size();
    int M = p.size();
    vector<vector<int>> dp(N+1,vector<int>(M+1,-1));
    for(int n=0;n<=N;n++){
        for(int m =0;m<=M;m++){
            if(m==0 || n==0){
                dp[n][m] = 0;
                continue;
            }
            if(s[n-1]==p[m-1]) dp[n][m] = 1 + dp[n-1][m-1];
            else dp[n][m] = max(dp[n-1][m],dp[n][m-1]);
        }
    }
    return dp[N][M];
}

// max dotproduct of subsequence
int dotproduct(vector<int>& s, vector<int>& p){
    int N = s.size();
    int M = p.size();
    vector<vector<int>> dp(N+1,vector<int>(M+1,0));
    for(int n=0;n<=N;n++){
        for(int m =0;m<=M;m++){
            if(n==0 || m==0){
                dp[n][m] = -(int)1e7;
                continue;
            }
            int val = s[n-1]*p[m-1];
            dp[n][m] = max(max(val,dp[n-1][m-1]+val),max(dp[n-1][m],dp[n][m-1]));
        }
    }
    return dp[N][M];
}

// Edit distance
int mindistance(string &s,string &p,int n,int m,vector<vector<int>>& dp){
    // cout<<s<<p;
    if(n==0 || m==0)   return dp[n][m] = (n != 0) ? n : m;
    if (dp[n][m] != -1)
        return dp[n][m];

    if(s[n-1]==p[m-1]) dp[n][m] = mindistance(s,p,n-1,m-1,dp);
    else{
        int insert  =  mindistance(s,p,n,m-1,dp);
        int deleted =  mindistance(s,p,n-1,m,dp);
        int replace =  mindistance(s,p,n-1,m-1,dp);
        dp[n][m] = min(insert,min(deleted,replace))+1;
    }
    return dp[n][m];
} 

// follow up
// cost {inserCost,deleteCost,replaceCost}
int minDistanceWithCost(string &word1, string &word2, vector<int>& cost, int n, int m, vector<vector<int>>& dp) {
    if (n == 0 || m == 0) {
        return dp[n][m] = (n != 0) ? n * cost[1] : m * cost[0];
    }

    if (dp[n][m] != -1)
        return dp[n][m];

    int insert = minDistanceWithCost(word1, word2, cost, n, m - 1, dp);
    int delete = minDistanceWithCost(word1, word2, cost, n - 1, m, dp);
    int replace = minDistanceWithCost(word1, word2, cost, n - 1, m - 1, dp);

    if (word1[n - 1] == word2[m - 1])
        return dp[n][m] = replace + 0;
    else
        return dp[n][m] = Math.min(Math.min(insert + cost[0], delete + cost[1]), replace + cost[2]);
}

// wildcard matching
int match(string &s,string &p,int n,int m,vector<vector<int>>& dp){
    if(n==0 && m==0) return dp[n][m] = 1;
    if(m!=0 && n==0){
        if(m==1 && p[m-1]=='*') return dp[n][m] = 1;
        dp[n][m] = 0;
    }
    if(m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n-1]==p[m-1]) dp[n][m] = match(s,p,n-1,m-1,dp);
    else{
        if(p[m-1]=='?') dp[n][m] = match(s,p,n-1,m-1,dp);
        else if(p[m-1]=='*'){
            // dp[n][m] = match(s,p,n-1,m,dp) || match(s,p,n,m-1,dp);           // simple subsequence se
            int res = 0;          // for loop se
            for(int i=n;i>=0;i--){
                res = res || match(s,p,n-i,m-1,dp);
            }
            dp[n][m] = res;
        }else{
            dp[n][m] = 0;
        }
    }
    return dp[n][m];
}
bool isMatch(string s, string p) {
    int m = p.length();
    string ans = "";
    int i=0;
    while(i<m){
        if(p[i+1] && p[i]=='*' && p[i]==p[i+1]){
            ans+=p[i];
            while(p[i+1] && p[i]=='*' && p[i]==p[i+1]){
                ans+="";
                i++;
            }
        }
        else ans += p[i];
        i++;
    }
    // cout<<ans<<endl;
    m = ans.length();
    int n = s.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return match(s,ans,n,m,dp);
}




int main(){
    // string s = "gashjsjkdljsklnddjhjwkndjnwwhdnjwe";
    // string ans = longestPalindromeSubseq_String(s);
    // cout<<ans<<"    "<<ans.length()<<endl;
    //===================================================================>
    string s = "rabbbit";
    string t = "rabbit";
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // cout<<"HII"<<n<<m<<"main"<<endl;
    // for(vector<int>& a:dp){
    //     for(int ele : a)
    //         cout<<ele<<endl;
    // }
    
    int a = numDistinct_dp(s,t,n,m,dp);
    cout<<a;

    return 0;
}