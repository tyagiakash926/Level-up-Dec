#include<bits/stdc++.h>
using namespace std;

// combination sum ii Method -> 1
vector<vector<int>> res;
vector<int> smallAns;
void combinationSum2(vector<int> &arr, int idx, int target)
{
    if (target == 0)
    {
        res.push_back(smallAns);
        return;
    }

    int prev = -1;
    for (int i = idx; i < arr.size(); i++)
    {
        if (prev != -1 && arr[prev] == arr[i])
            continue;

        if (target - arr[i] >= 0)
        {
            smallAns.push_back(arr[i]);
            combinationSum2(arr, i + 1, target - arr[i]);
            smallAns.pop_back();
            prev = i;
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    combinationSum2(arr, 0, target);
    return res;
}

// combination sum ii Method -> 2

vector<vector<int>> res;
void coinChangeCombinationInfiSub(vector<int> &arr,int tar,int idx,vector<int>& small){
    if(idx==arr.size() || tar==0){
    if(tar==0) res.push_back(small);
    return ;
}
for(int i=idx;i<arr.size();i++){
    if(i>idx && arr[i]==arr[i-1]) continue;
    if(tar-arr[i]>=0){
        small.push_back(arr[i]);
        coinChangeCombinationInfiSub(arr,tar-arr[i],i+1,small);
        small.pop_back();
    }
}
}
vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
    sort(arr.begin(),arr.end());
    vector<int> small;
    coinChangeCombinationInfiSub(arr,tar,0,small);
    return res;
}

// combination sum ii Method -> 3 HASHMAP WALA / VIS WALA BREADTH PAR

// permutation - ii Method 1
vector<vector<int>> res; 
void find(vector<int> &arr,int idx,vector<bool> &vis,vector<int> &small){
    if(idx==arr.size()){
        res.push_back(small);
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(i>0 && arr[i]==arr[i-1] && !vis[i-1]) continue;
        
        if(!vis[i]){
            vis[i]=true;
            small.push_back(arr[i]);
            find(arr,idx+1,vis,small);
            small.pop_back();
            vis[i]=false;
        }
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<bool> vis(nums.size(),false);
    vector<int> small;
    find(nums,0,vis,small);
    return res;
}

// permutation - ii Method 2



int main(){
   return 0;
}