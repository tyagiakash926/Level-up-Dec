#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

void print1D(vector<int> &arr)
{
    for (int ele : arr)
    {
        cout << ele<<" ";
    }
    cout << endl;
}

void print2D(vector<vector<int>> &arr)
{
    for (vector<int> &ar : arr)
    {
        print1D(ar);
    }
}

int fibbo_rec(int n){
    if(n<=1) return n;
    return fibbo_rec(n-2)+fibbo_rec(n-1);
}

int fib_memo(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return dp[n] = n;
    }

    if (dp[n] != -1)
        return dp[n];

    int ans = fib_memo(n - 1, dp) + fib_memo(n - 2, dp);
    return dp[n] = ans;
}

int fib_tab(int n,vector<int> &dp){
    int N = n;
    for (int n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = n;
            continue;
        }

        int ans = dp[n - 1] + dp[n - 2]; // fib_01(n - 1, dp) + fib_01(n - 2, dp);

        dp[n] = ans;
    }
    return dp[N];
}
int mazepath(int sr,int sc,int dr,int dc){
    if(sr==dr && sc==dc){
        return 1;
    }
    int count = 0;
    if(sc+1<=dc) count+=mazepath(sr,sc+1,dr,dc); // H
    if(sr+1<=dr && sc+1<=dc) count+=mazepath(sr+1,sc+1,dr,dc); //D
    if(sr+1<=dr) count+=mazepath(sr+1,sc,dr,dc); //V
    return count;
}
int mazepath_memo(int sr,int sc,int dr,int dc,vector<vector<int>> &dp){
    if(sr==dr && sc==dc){
        dp[sr][sc] =1;
        return dp[sr][sc];
    }
    if(dp[sr][sc]!=-1) return dp[sr][sc];
    int count = 0;
    if(sc+1<=dc) count+=mazepath_memo(sr,sc+1,dr,dc,dp); // H
    if(sr+1<=dr && sc+1<=dc) count+=mazepath_memo(sr+1,sc+1,dr,dc,dp); //D
    if(sr+1<=dr) count+=mazepath_memo(sr+1,sc,dr,dc,dp); //V
    dp[sr][sc]=count;
    return dp[sr][sc];
}

int mazePath_DP(int SR, int SC, int er, int ec, vector<vector<int>> &dp) {
        for (int sr = er; sr >= 0; sr--) {
            for (int sc = ec; sc >= 0; sc--) {

                if (sr == er && sc == ec) {
                    dp[sr][sc] = 1;
                    continue;
                }

                int count = 0;
                if (sc + 1 <= ec)
                    count += dp[sr][sc + 1];// mazePath_memo(sr, sc + 1, er, ec, dp);
                if (sr + 1 <= er)
                    count += dp[sr + 1][sc];// mazePath_memo(sr + 1, sc, er, ec, dp);
                if (sc + 1 <= ec && sr + 1 <= er)
                    count += dp[sr + 1][sc + 1]; // mazePath_memo(sr + 1, sc + 1, er, ec, dp);

                dp[sr][sc] = count;
            }
        }

        return dp[SR][SC];
    }
int mazepathjump_rec(int sr,int sc,int dr,int dc){
    if(sr==dr && sc==dc){
        return 1;
    }
    int count=0;
    for(int jump=1;sc+jump<=dc;jump++){
        count+=mazepathjump_rec(sr,sc+jump,dr,dc);
    }

    for(int jump=1;sr+jump<=dr;jump++){
        count+=mazepathjump_rec(sr+jump,sc,dr,dc);
    }

    for(int jump=1;sc+jump<=dc && sr+jump<=dr;jump++){
        count+=mazepathjump_rec(sr+jump,sc+jump,dr,dc);
    }

    return count;
}

int mazePathInfi_memo(int sr,int sc,int er,int ec,vector<vector<int>> &dp){
    if (sr == er && sc == ec) {
            return dp[sr][sc] = 1;
        }

        if (dp[sr][sc] != -1)
            return dp[sr][sc];

        int count = 0;
        for (int jump = 1; sc + jump <= ec; jump++)
            count += mazePathInfi_memo(sr, sc + jump, er, ec, dp);
        for (int jump = 1; sr + jump <= er; jump++)
            count += mazePathInfi_memo(sr + jump, sc, er, ec, dp);
        for (int jump = 1; sc + jump <= ec && sr + jump <= er; jump++)
            count += mazePathInfi_memo(sr + jump, sc + jump, er, ec, dp);

        return dp[sr][sc] = count;
}

int ways(int tar,int n){
    if(tar==0) return 1;
    int count=0;
    for(int i=1;i<=n;i++){
        if(tar-i>=0){
            count+=ways(tar-i,n);
        }
    }
    return count;
}

int ways_memo(int tar,int n,vector<int> &dp){
    if(tar==0){
        dp[tar]=1;
        return dp[tar];
    }
    if(dp[tar]!=-1) return dp[tar];
    int count=0;
    for(int i=1;i<=n;i++){
        if(tar-i>=0){
            count+=ways_memo(tar-i,n,dp);
        }
    }
    dp[tar]=count;
    return dp[tar];
}

int ways_DP(int Tar,int n,vector<int> &dp){

    for(int tar=0;tar<=Tar;tar++){
        if(tar==0){
            dp[tar]=1;
            continue;
        }
        // if(dp[tar]!=-1) return dp[tar];
        for(int i=1;i<=n;i++){
            if(tar-i>=0)
                dp[tar] += dp[tar-i]; // ways(tar-i,n,dp);
            else break;
        }
    }
    return dp[Tar];
}

// 
int waysarr_rec(int tar,vector<int> &arr){
    if(tar==0) return 1;
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(tar-arr[i] >= 0){
            count+=waysarr_rec(tar-arr[i],arr);
        }
    }
    return count;
}

int waysarr_memo(int tar,vector<int> &arr,vector<int> &dp){
    if(tar==0) return dp[tar] = 1;
    if(dp[tar]!=0) return dp[tar];
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(tar-arr[i] >= 0){
            count+=waysarr_memo(tar-arr[i],arr,dp);
        }
    }
    return dp[tar] = count;
}

int waysarr_tab(int Tar,vector<int> &arr,vector<int> &dp){
    for(int tar=0;tar<=Tar;tar++){
        if(tar==0){
            dp[tar] = 1;
            continue;
        }
        
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(tar-arr[i] >= 0){
                count+=dp[tar-arr[i]];
            }
        }
        dp[tar] = count;
    }
    return dp[Tar];
}

// leetcode 70
int climbrec_(int n){
    if(n<=1) return 1;
    int count=0;
    count+=climbrec_(n-1);
    count+=climbrec_(n-2);
    return count;
}
int climbmemo_(int n,vector<int> &dp){
    if(n<=1) return dp[n]=1;
    if(dp[n]!=-1) return dp[n];
    int count=0;
    count+=climbmemo_(n-1,dp);
    count+=climbmemo_(n-2,dp);
    return dp[n]=count;
}
int climbdp_(int N,vector<int> &dp){
    for(int n=0;n<=N;n++){
        if(n<=1){
            dp[n]=1;
            continue;
        } 
        // if(dp[n]!=-1) return dp[n];
        int count=0;
        count+=dp[n-1];
        count+=dp[n-2];
        dp[n]=count;
    }
    return dp[N];
}
int climbopti_(int n){
    long long int a = 1;
    long long int b = 1;
    for(int i=0;i<n;i++){
        long long int  sum = a+b;
        a=b;
        b=sum;
    }
    return (int)a;
}

// leetcode 746
// 1st approach
int mincost(vector<int>& cost,int idx,vector<int>& dp){
    if(idx==cost.size()){
        return dp[idx]=0;
    }
    if(dp[idx]!=-1) return dp[idx];
    int minimum = (int)1e9;
    if(idx+1<=cost.size()){
        minimum = min(minimum,mincost(cost,idx+1,dp));
    }
    if(idx+2<=cost.size()){
            minimum = min(minimum,mincost(cost,idx+2,dp));
    }
    return dp[idx]=minimum+cost[idx];
}
int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size()+1,-1);
    int a = mincost(cost,0,dp);
    for(int i=0;i<cost.size()+1;i++){
        dp[i]=-1;
    }
    int b = mincost(cost,1,dp);
    return min(a,b);
}

// 2nd Methode from backside
int mincost_rec(vector<int>& cost,int idx,vector<int>& dp){
    if(idx<=1){
        return cost[idx];
    }
    int mincost_ =min(mincost_rec(cost,idx-1,dp),mincost_rec(cost,idx-2,dp));
    return mincost_ + (idx == cost.size() ? 0 : cost[idx]);
}
int mincost_memo(vector<int>& cost,int idx,vector<int>& dp){
    if(idx<=1){
        return dp[idx] = cost[idx];
    }
    int mincost_ =min(mincost_memo(cost,idx-1,dp),mincost_memo(cost,idx-2,dp));
    return dp[idx] = mincost_ + (idx == cost.size() ? 0 : cost[idx]);
}
int mincost_dp(vector<int>& cost,int N,vector<int>& dp){
    for(int n=0;n<=N;n++){
        if(n<=1){
            dp[n] = cost[n];
            continue;
        }
        int mincost_ =min(dp[n-1],dp[n-2]);
        dp[n] = mincost_ + (n == cost.size() ? 0 : cost[n]);
    }
    return dp[N];
}

vector<vector<int>> dirA={{-1,1},{0,1},{1,1}};
int path_memo(int sr,int sc,int n,int m ,vector<vector<int>> &grid,vector<vector<int>> &dp){
    if(dp[sr][sc]!=0) return dp[sr][sc];
    int max_gold = 0;
    grid[sr][sc]=-grid[sr][sc];
    for(int i=0;i<dirA.size();i++){
        int r = sr+dirA[i][0];
        int c = sc+dirA[i][1];
        if(r>=0 && c>=0 && r<n && c<m && grid[r][c]>0){
            max_gold=max(max_gold,path_memo(r,c,n,m,grid,dp));
        }
    }
    grid[sr][sc]=-grid[sr][sc];
    return dp[sr][sc] = max_gold+grid[sr][sc];
}

int path_dp(int SR,int SC,int n,int m ,vector<vector<int>> &grid,vector<vector<int>> &dp){
    for(int sc=m-1;sc>=0;sc--){
        for(int sr=n-1;sr>=0;sr--){
            int max_gold = 0;
            grid[sr][sc]=-grid[sr][sc];
            for(int i=0;i<dirA.size();i++){
                int r = sr+dirA[i][0];
                int c = sc+dirA[i][1];
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]>0){
                    max_gold=max(max_gold,dp[r][c]);
                }
            }
            grid[sr][sc]=-grid[sr][sc];
            dp[sr][sc] = max_gold+grid[sr][sc];
        }
    }
    return dp[SR][SC];
}

int maxGold(int n, int m, vector<vector<int>> grid)
{
    int maximum = 0;
    vector<vector<int>> dp;
    for(int i=0;i<n;i++){
        dp.resize(n,vector<int>(m,0));
        maximum = max(maximum,path_memo(i,0,n,m,grid,dp));
    }
    return maximum;
}

int mincost_opti(vector<int>& cost){
    int a = cost[0];
    int b =cost[1];
    for(int i=2;i<cost.size();i++){
        int min_ = min(a,b)+cost[i];
        a = b;
        b = min_; 
    }
    return min(a,b);
}
int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size()+1,-1);
    // int a = mincost(cost,0,dp);
    // for(int i=0;i<cost.size()+1;i++){
    //     dp[i]=-1;
    // }
    // int b = mincost(cost,1,dp);
    // return mincost_dp(cost,cost.size(),dp);
}

// friend pairing rec
long long int mod=1e9 + 7;
long long int friend_rec(int n){
    if(n<=1) return 1;
    long long int count=0;
    count += friend_rec(n-1)%mod + (friend_rec(n-2)*(n-1))%mod;
    return count%mod;
}

long long int friend_memo(int n,vector<long long int> &dp){
    if(n<=1) return dp[n] = 1;
    if(dp[n]!=-1) return dp[n];
    long long int count=0;
    count += friend_memo(n-1,dp)%mod + (friend_memo(n-2,dp)*(n-1))%mod;
    return dp[n]=count%mod;
}
long long int friend_dp(int N,vector<long long int> &dp){
    for(int n=0;n<=N;n++){

        if(n<=1){
            dp[n] = 1;
            continue;
        }
        // if(dp[n]!=-1) return dp[n];
        long long int count=0;
        count += dp[n-1]%mod + ((dp[n-2]%mod)*(n-1))%mod;
        dp[n]=count%mod;
    }
    return dp[N];
}

int friend_opt(int n){
    if(n<=1) return 1;
    long long int a = 1;
    long long int b =1;
    for(int i=2;i<=n;i++){
        long long int sum = (a*(i-1) + b )%mod;
        a = b % mod;
        b = sum % mod;
    }
    return b%mod;
}
long long int printFriendsPairing(string friends, string ans) {
        if (friends.length() == 0) {
            cout<<ans<<endl;
            return 1;
        }

        char ch = friends[0];
        long long int count = 0;
        count += printFriendsPairing(friends.substr(1,friends.length()-1), ans + ch + " ");
        for (int i = 1; i < friends.length(); i++) {
            string rstr = friends.substr(1, i-1) + friends.substr(i + 1);
            
            count += printFriendsPairing(rstr, ans + ch + friends[i] + " ");
        }

        return count;
    }

vector<string> small;
vector<vector<string>> res;

int friends(string s){
    if(s.length()==0){
        res.push_back(small);
        return 1;
    }
    int n = s.length();
    int count=0;
    // single 
    string pp="";
    pp+=s[0];
    small.push_back(pp);
    count += friends(s.substr(1,s.length()-1));
    small.pop_back();
    // pair 
    for(int i=0;i<n-1;i++){
        string ns ="";
        string nans="";
        nans+=s[i];
        nans+=s[i+1];
        ns += s.substr(0,i);
        if(i+2<n){
            ns += s.substr(i+2,n-(i+1));
        }
        small.push_back(nans);
        count += friends(ns);
        small.pop_back();
    }
    return count;
}

// leetcode 91
int numdecode_rec(string s,int idx){
    if(idx==s.length()) return 1;
    char ch = s[idx];
    if(ch=='0') return 0;
    int count=0;
    count += numdecode_rec(s,idx+1);
    if(idx < s.length()-1){
        char ch2 = s[idx+1];
        int num = (ch-'0')*10 + (ch2-'0');
        if(num<=26) count+=numdecode_rec(s,idx+2);
    }
    return count;
}

int numdecode_memo(string s,int idx,vector<int>& dp){
    if(idx==s.length()) return dp[idx] = 1;
    if(dp[idx]!=-1) return dp[idx];
    char ch = s[idx];
    if(ch=='0') return dp[idx] = 0;
    int count=0;
    count += numdecode_memo(s,idx+1,dp);
    if(idx < s.length()-1){
        char ch2 = s[idx+1];
        int num = (ch-'0')*10 + (ch2-'0');
        if(num<=26) count+=numdecode_memo(s,idx+2,dp);
    }
    return dp[idx] = count;
}

int numdecode_dp(string s,int IDX,vector<int>& dp){
    for(int idx=s.length();idx>=0;idx--){
        if(idx==s.length()){
            dp[idx] = 1;
            continue;
        }
        // if(dp[idx]!=-1) return dp[idx];
        char ch = s[idx];
        if(ch=='0'){
            dp[idx] = 0;
            continue;
        } 
        int count=0;
        count += dp[idx+1]; // numdecode_memo(s,idx+1,dp);
        if(idx < s.length()-1){
            char ch2 = s[idx+1];
            int num = (ch-'0')*10 + (ch2-'0');
            if(num<=26) count+=dp[idx+2]; // numdecode_memo(s,idx+2,dp);
        }
        dp[idx] = count;
    }
    return dp[IDX];
}

int numdecode_opti(string s){
    int a = 1; //idx+1
    int b = 0; //idx+2
    int count = 0;
    for(int idx=s.length()-1;idx>=0;idx--){
        count = 0;
        char ch = s[idx];
        if(ch != '0'){
            count+=a;
            if(idx < s.length()-1){
                char ch2 = s[idx+1];
                int num = (ch-'0')*10 + (ch2-'0');
                if(num<=26) count+=b;
            }
        }
        b = a;
        a = count;
    }
    return a;
}

long numdecode_II_rec(string s,int idx,vector<long>& dp){
    if(idx==s.length()) return 1;
    char ch1 = s[idx];
    if(ch1=='0') return 0;
    
    int count = 0;
    if(ch1=='*'){
        // 1st digit ki call 
        count = (count%mod + (9 * numdecode_II_rec(s,idx+1,dp)%mod))%mod; 
        if(idx+1<s.length()){ // 2nd char ki call lag skti h
            char ch2 = s[idx+1];
            if(ch2=='*') count = (count%mod + (15 * numdecode_II_rec(s,idx+2,dp) )%mod)%mod;
            else if(ch2>='0' && ch2<='6') count = (count%mod + (2 * numdecode_II_rec(s,idx+2,dp))%mod )%mod;
            else if(ch2>'6' && ch2<='9') count = (count%mod +  numdecode_II_rec(s,idx+2,dp)%mod )%mod;
        }

    }else{  // starting char number h
        count = (count%mod + numdecode_II_rec(s,idx+1,dp)%mod )%mod; // 1 akela number aaya 
        if(idx+1<s.length()){ // 2nd char ki call lag skti h 
            char ch2 = s[idx+1];  // 2 possibility */n
            if(ch2=='*'){
                if(ch1=='1') count = (count%mod + (9 * numdecode_II_rec(s,idx+2,dp))%mod )%mod;
                if(ch1=='2') count = (count%mod + (6 * numdecode_II_rec(s,idx+2,dp))%mod )%mod;
            }else{  // ab 2nd bhi number hi h toh  numdecode last wala question
                int num = (ch1-'0')*10 + (ch2-'0');
                if(num<=26) count = (count%mod + numdecode_II_rec(s,idx+2,dp)%mod )%mod;;
            }
        }
    }
    return count;
}

long numdecode_II_memo(string s,int idx,vector<long>& dp){
    if(idx==s.length()) return dp[idx]=1;
    if(dp[idx]!=-1) return dp[idx];
    char ch1 = s[idx];
    if(ch1=='0') return dp[idx]=0;
    
    int count = 0;
    if(ch1=='*'){
        // 1st digit ki call 
        count = (count%mod + (9 * numdecode_II_memo(s,idx+1,dp)%mod))%mod; 
        if(idx+1<s.length()){ // 2nd char ki call lag skti h
            char ch2 = s[idx+1];
            if(ch2=='*') count = (count%mod + (15 * numdecode_II_memo(s,idx+2,dp) )%mod)%mod;
            else if(ch2>='0' && ch2<='6') count = (count%mod + (2 * numdecode_II_memo(s,idx+2,dp))%mod )%mod;
            else if(ch2>'6' && ch2<='9') count = (count%mod +  numdecode_II_memo(s,idx+2,dp)%mod )%mod;
        }

    }else{  // starting char number h
        count = (count%mod + numdecode_II_memo(s,idx+1,dp)%mod )%mod; // 1 akela number aaya 
        if(idx+1<s.length()){ // 2nd char ki call lag skti h 
            char ch2 = s[idx+1];  // 2 possibility */n
            if(ch2=='*'){
                if(ch1=='1') count = (count%mod + (9 * numdecode_II_memo(s,idx+2,dp))%mod )%mod;
                if(ch1=='2') count = (count%mod + (6 * numdecode_II_memo(s,idx+2,dp))%mod )%mod;
            }else{  // ab 2nd bhi number hi h toh  numdecode last wala question
                int num = (ch1-'0')*10 + (ch2-'0');
                if(num<=26) count = (count%mod + numdecode_II_memo(s,idx+2,dp)%mod )%mod;;
            }
        }
    }
    return dp[idx]=count;
}

long numdecode_II_dp(string s,int IDX,vector<long>& dp){
    for (int idx = s.length(); idx >= 0; idx--) {
        if(idx==s.length()){
            dp[idx]=1;
            continue;
        }
        char ch1 = s[idx];
        if(ch1=='0'){
            dp[idx]=0;
            continue;
        }

        int count = 0;
        if(ch1=='*'){
            // 1st digit ki call 
            count = (count%mod + (9 *  dp[idx+1]%mod))%mod; 
            if(idx+1<s.length()){ // 2nd char ki call lag skti h
                char ch2 = s[idx+1];
                if(ch2=='*') count = (count%mod + (15 *  dp[idx+2] )%mod)%mod;
                else if(ch2>='0' && ch2<='6') count = (count%mod + (2 *  dp[idx+2])%mod )%mod;
                else if(ch2>'6' && ch2<='9') count = (count%mod +   dp[idx+2]%mod )%mod;
            }

        }else{  // starting char number h
            count = (count%mod +  dp[idx+1]%mod )%mod; // 1 akela number aaya 
            if(idx+1<s.length()){ // 2nd char ki call lag skti h 
                char ch2 = s[idx+1];  // 2 possibility */n
                if(ch2=='*'){
                    if(ch1=='1') count = (count%mod + (9 *  dp[idx+2])%mod )%mod;
                    if(ch1=='2') count = (count%mod + (6 *  dp[idx+2])%mod )%mod;
                }else{  // ab 2nd bhi number hi h toh  numdecode last wala question
                    int num = (ch1-'0')*10 + (ch2-'0');
                    if(num<=26) count = (count%mod + dp[idx+2]%mod )%mod;;
                }
            }
        }
        dp[idx]=count;
    }
    return (int)dp[IDX];
}

long numDecodings_opti(string s) {
    long a = 1, b = 0;
    for (int idx = s.length() - 1; idx >= 0; idx--) {

        long count = 0;
        char ch1 = s[idx];
        if (ch1 == '0') {
            count = 0;
        } else if (ch1 == '*') {
            count = (count + 9 * a) % mod;
            if (idx < s.length() - 1) {
                char ch2 = s[idx + 1];
                if (ch2 == '*')
                    count = (count + 15 * b) % mod;
                else if (ch2 >= '0' && ch2 <= '6')
                    count = (count + 2 * b) % mod;
                else if (ch2 > '6')
                    count = (count + b) % mod;

            }
        } else {
            count = (count + a) % mod;
            if (idx < s.length() - 1) {
                if (s[idx + 1] != '*') {
                    char ch2 = s[idx + 1];
                    int num = (ch1 - '0') * 10 + (ch2 - '0');
                    if (num <= 26)
                        count = (count + b) % mod;
                } else {
                    if (s[idx] == '1')
                        count = (count + 9 * b) % mod;
                    else if (s[idx] == '2')
                        count = (count + 6 * b) % mod;
                }
            }
        }

        b = a;
        a = count;
    }

    return (int) a;
}

// https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/

int noOfWays(int n, int k, vector<vector<int>>& dp) {
    if (k == 1) {
        return dp[n][k] = 1;
    }
    if (n == k) {
        return dp[n][k] = 1;
    }

    if (dp[n][k] != 0)
        return dp[n][k];

    int uniqueGroup = noOfWays(n - 1, k - 1, dp);
    int partOfExisGroup = noOfWays(n - 1, k, dp) * k;

    return dp[n][k] = uniqueGroup + partOfExisGroup;
}








void decode(){
    cout<<numdecode_rec("1141036",0)<<endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    // int n = 8;
    // vector<int> dp(n + 1, -1);
    // cout<<fibbo_rec(n)<<endl;
    // cout<<fib_memo(n,dp)<<endl;
    // cout<<fib_tab(n,dp)<<endl;
    // n=4;
    // int m=4;
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<mazepath(0,0,n-1,m-1)<<endl;
    // cout<<mazepath_memo(0,0,n-1,m-1,dp)<<endl;
    // cout<<mazePath_DP(0,0,n-1,m-1,dp)<<endl;
    // cout<<mazepathjump_rec(0,0,n-1,m-1)<<endl;
    // cout<<mazePathInfi_memo(0,0,n-1,m-1,dp)<<endl;

    // vector<int> dp(10 , 0);
    // cout<<ways_memo(10,6,dp)<<endl;
    // cout<<ways_DP(20,6,dp)<<endl;
    // vector<int> arr={2,3,5,7};
    // cout<<waysarr_rec(9,arr)<<endl;
    // cout<<waysarr_memo(9,arr,dp)<<endl;
    // cout<<waysarr_tab(9,arr,dp)<<endl;
    // cout<<ways_DP(20,6,dp)<<endl;
    // print1D(dp);
    // cout<<friends("ABCDE")<<endl;
    // for(vector<string> ele: res){
    //     for(string aka : ele)
    //     cout<<aka<<" ";
    //     cout<<endl;
    // }
    // print2D(res);

    decode();
    return 0;
}