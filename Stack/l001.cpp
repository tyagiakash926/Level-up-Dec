#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// N : Next, G = greater, S : Smaller, L : Left, R : Right

void NGOR(vector<int> &arr , vector<int> &ans){
    int n = arr.size();
    ans.resize(n,n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(st.size() != 0 && arr[st.top()] < arr[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

void NGOL(vector<int> &arr , vector<int> &ans){
    int n = arr.size();
    ans.resize(n,-1);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(st.size() != 0 && arr[st.top()] < arr[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

void NSOR(vector<int>& arr ,vector<int> &ans){
    int n = arr.size();
    ans.resize(n,n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(st.size() != 0 && arr[st.top()] > arr[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

void NSOL(vector<int>& arr ,vector<int> &ans){
    int n = arr.size();
    ans.resize(n,-1);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(st.size() != 0 && arr[st.top()] > arr[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

//leetcode 503
vector<int> nextGreaterElements(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1); //Java :  Arrays.fill(ans,n);

    stack<int> st;
    for (int i = 0; i < 2 * n; i++)
    {
        while (st.size() != 0 && arr[st.top()] < arr[i % n])
        {
            ans[st.top()] = arr[i % n];
            st.pop();
        }
        if (i < n)
            st.push(i);
    }
    return ans;
}

// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
vector<int> NGOL(int arr[], int n)
{
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[st.top()] < arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }
    return ans;
}

vector<int> calculateSpan(int arr[], int n)
{
    vector<int> ans = NGOL(arr, n);
    for (int i = 0; i < n; i++)
        ans[i] = i - ans[i];
    return ans;
}

// leetcode 946
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int idx=0;
    for(int ele:pushed){
        st.push(ele);
        while(st.size()!=0 && st.top()==popped[idx]){
            st.pop();
            idx++;
        }
    }
    return st.size()==0;
}
//leetcode 20
bool isValid(string s) {
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else{
            if(st.size()==0) return false;
            if(s[i]==']' && st.top()!='[') return false;
            if(s[i]=='}' && st.top()!='{') return false;
            if(s[i]==')' && st.top()!='(') return false;
            else st.pop();
        }
    }
    return st.size()==0;
}
// leetcode 1249 (min remove to make valid parenthese)
string minRemoveToMakeValid(string s) {
    int n = s.length(); 
    vector<int> st;
    for(int i=0;i<n;i++){
        
        if(s[i]=='(') st.push_back(i);
        
        else if (s[i] == ')')
        {
            if (st.size() != 0 && s[st.back()] == '(')
                st.pop_back();
            else
                st.push_back(i);
        }
    }
    string str = "";
    int idx = 0;
    for(int i=0;i<n;i++){
        if(idx<st.size() && i==st[idx]){
            idx++;
            continue;
        } 
        str+=s[i];
    }
    return str;
}
// leetcode 32



int main(){
    vector<int> arr = {5,2,-1,4,5,-3,-7,-6,-4,6,5};
    vector<int> ans;
    NSOL(arr,ans);
    for(int ele : ans)
        cout<<ele<<" ";
    return 0;
}