#include<iostream>
#include<cmath>
#include <algorithm>  
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

void sepratePositiveNegative(vector<int>& arr){
    if (arr.size() == 0) return;
    int p =-1;
    int i= 0;
    int n = arr.size();
    while(i<n){
        if(arr[i]<0){
            p=p+1;
            int a = arr[p];
            arr[p]=arr[i];
            arr[i]=a;
        }
        i++;
    }
}

void sortColors(vector<int>& arr) {
        if(arr.size()==1) return;
        int n = arr.size();
        int p=-1,i=0,j=n-1;
        while(i<n && i<=j && j>=0){
            if(arr[i]==0){
                p=p+1;
                int a = arr[p];
                arr[p] = arr[i];
                arr[i]=a;
                i++;
            }else{
                if(arr[i]==1) i++;
                else{
                    int a = arr[i];
                    arr[i]=arr[j];
                    arr[j] = a;
                    j--;
                }
            }
        }
    }

//int -2,147,483,648 to 2,147,483,647
// long long int -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
     int maxRotateFunction(vector<int>& arr) {
        if(arr.size()==0) return 0;
        int n = arr.size();
        long long int sum=0;
        long long int multiply_sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            multiply_sum += arr[i]*i;
        }
        long long int maximum = multiply_sum;
        for(int i=1;i<n;i++){
            multiply_sum -=sum;
            multiply_sum += arr[i-1];
            multiply_sum += arr[i-1]*(n-1);
            maximum = max(maximum,multiply_sum);
        }
        return maximum;
    }

    //leetcode 3
    int lengthOfLongestSubstring(string s) {
       int ns= s.length();
        if(ns<=1) return ns;
        int si=0,ei=0,count=0,len=0;
        vector<int> map(128,0); 
        while(ei<ns){
            if(map[s[ei++]]++ > 0) count++;
            while(count>0){
                if(map[s[si++]]-- >1) count--;
            }
            len = max(len,ei-si);
        }
        return len;
    }

    //leetcode 76
    string minWindow(string s, string t) {
       int ns = s.length();
       int nt = t.length();
        int si=0,ei=0,len=(int)1e8,head=0;
        int req=nt;
        vector<int> map(128,0);
        for(int i=0;i<nt;i++){
            map[t[i]]++;
        }
        while(ei<ns){
            if(map[s[ei++]]-- > 0) req--;
            while(req==0){
                if(len>ei-si){
                    len=ei-si;
                    head=si;
                }
                if(map[s[si++]]++ ==0 ) req++;
            }
        }
        return len==(int)1e8?"":s.substr(head,len);
    }

    // smallest window contains all character
    string smallString(string s){
        int ns = s.length();
        if(ns==0) return "";
        int ei=0,si=0,len=(int)1e8,req=0,head=0;
        vector<int> map(128,0);
        for(int i=0;i<ns;i++){
            map[s[i]] = 1;
        }
        for(int ele : map)
            req+=ele;
        while(ei<ns){
            if(map[s[ei++]]-- == 1) req--;
            while(req==0){
                if(len>ei-si){
                    len=ei-si;
                    head=si;
                }
                if(map[s[si++]]++ == 0) req++;
            }
        }
        return len==(int)1e8?"-1":s.substr(head,len);
    } 

    //lintcode longest substring atmost 2 character
     int lengthOfLongestSubstringTwoDistinct(string &s) {
        // Write your code here
        int ns = s.length();
        if(ns<=1) return ns;
        int si=0,ei=0,len=0,count=0;
        vector<int> map(128,0);
        while(ei<ns){
            if(map[s[ei++]]++ == 0) count++;
            while(count>2){
                if(map[s[si++]]-- == 1) count--;
            }
            if(len<ei-si){
                len =ei-si;
            }
        }
        return len;
    }
    //lintcode longest substring atmost k character
     int lengthOfLongestSubstringTwoDistinct(string &s,int k) {
        // Write your code here
        int ns = s.length();
        if(ns<=1) return ns;
        int si=0,ei=0,len=0,count=0;
        vector<int> map(128,0);
        while(ei<ns){
            if(map[s[ei++]]++ == 0) count++;
            while(count>k){
                if(map[s[si++]]-- == 1) count--;
            }
            if(len<ei-si){
                len =ei-si;
            }
        }
        return len;
    }
    //leetcode 1456
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='o'||c=='u'||c=='i') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int ns = s.length();
        int ei=0,si=0,maxV=0,vc=0;
        while(ei<ns){
            if(isVowel(s[ei++])) vc++;
            if(ei-si==k){
                maxV = max(maxV,vc);
                if(isVowel(s[si++])) vc--;
            }
        }
        return maxV;
    }

    //leetcode 1071 *** important sochne mei g**d faat jayegi!!
     string gcdOfStrings(string s1, string s2) {
       return (s1 + s2 == s2 + s1)  
		    ? s1.substr(0, __gcd(s1.length(), s2.length()))
			: "";
    }

    // sliding window maximum
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // <arr[i],i> pq
       priority_queue<pair<int,int>> pq ;//max pq default
        int n = nums.size();
        vector<int> arr(n-k+1,0);
        int idx=0;
        for(int i=0;i<n;i++){
            while(pq.size()!=0 && pq.top().second<=i-k){
                pq.pop();
            }
            pq.push({nums[i],i});
            if(i>=k-1){
                arr[idx++]=pq.top().first;
            }
        }
        return arr;    
    }
    // https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
    int maxLen(vector<int>& arr, int N){
        if(N==0) return 0;
        int len = 0;
        unordered_map<int,int> map;  //sum,idx
        map[0]=-1;
        int sum = 0;
        for(int i=0;i<N;i++){
            int val = arr[i];
            if(val==0) val=-1;
            sum+=val;

            if(map.find(sum)!=map.end()) len = max(len , i-map[sum]);
            else map[sum]=i;
        }
        return len;

    }
    // https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1
    long long int countSubarrWithEqualZeroAndOne(int arr[], int N){
        if(N==0) return 0;
        unordered_map<int,int> map;//sum,idx
        map[0]=1;
        long long int count=0;
        long long int sum =0;
        for(int i=0;i<N;i++){
            int val = arr[i];
            if(val==0) val=-1;
            sum += val;

            if(map.find(sum)!=map.end()){ 
                count += map[sum];
                map[sum]+=1;
            }else{
                map[sum]=1;
            }
        }
        return count;
    }
     
    // https://www.geeksforgeeks.org/count-substrings-that-contain-all-vowels-set-2/
    bool isVowel(char c){ 
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); 
    } 
    int countSubstringsUtil(string &s){
        int ns = s.length();
        int si=0,ei=0,req=0,count=0;
        vector<int> map(128,0);
        while(ei<ns){
            if(map[s[ei++]]++ ==0 ) req++;
            while(req==5){
                if(map['a']>0 && map['e']>0 && map['i']>0 && map['o']>0 && map['u']>0){
                    count += ns-(ei-1);
                    if(map[s[si++]]-- == 1 ) req--;
                }
            }
        }
        return count;
    }
    int countSubstrings(string s) {
        int count=0;
        string temp = ""; 
    
        for (int i = 0; i < s.length(); i++) { 
    
            // If current character is a vowel then 
            // append it to the temp string 
            if (isVowel(s[i])) { 
                temp += s[i]; 
            } 
    
            // The sub-string containing all vowels ends here 
            else { 
    
                // If there was a valid sub-string 
                if (temp.length() > 0) 
                    count += countSubstringsUtil(temp); 
    
                // Reset temp string 
                temp = ""; 
            } 
        } 
    
        // For the last valid sub-string 
        if (temp.length() > 0) 
            count += countSubstringsUtil(temp); 
    
        return count; 
    }

    // https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1#
    int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int> map; // sum,idx
	    map[0]=-1;
	    int sum=0,len=0;
	    for(int i=0;i<n;i++){
	        int val = arr[i];
	        sum+=val;
	        sum = ((sum%k)+k)%k;
	        if(map.find(sum)!=map.end()){
	            len = max(len,i-map[sum]);
	        }else{
	            map[sum]=i;
	        }
	    }
	    return len;
	}

    //leetcode 974
    int subarraysDivByK(vector<int>& arr, int k) {
         // Complete the function
        int n = arr.size(); 
	    unordered_map<int,int> map; // sum,idx
	    map[0]=1;
	    int sum=0,count=0;
	    for(int i=0;i<n;i++){
	        int val = arr[i];
	        sum+=val;
	        sum = ((sum%k)+k)%k;
	        if(map.find(sum)!=map.end()){
	            count += map[sum];
                map[sum]++;
	        }else{
	            map[sum]=1;
	        }
	    }
	    return count;
    }

    //leetcode 1590 **important gaand faat jayegi
     int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int mod = 0;
        for(int ele : nums)
            mod = (mod+ele)%p;
        if(mod==0) return 0;
        unordered_map<int,int> map;
        map[0]=-1;
        int sum=0;
        int res=n;
        for(int i=0;i<n;i++){
            sum += nums[i];
            sum = sum%p;
            int temp = (sum-mod)%p;
            if(temp<0) temp+=p;
            if(map.find(temp)!=map.end()){
                res = min(res,i-map[temp]);
            }
            // ye abhi bacha hua h 


        }
        return 0;
     }

     //leetcode 904
     int totalFruit(vector<int>& arr) {
        int ns = arr.size();
        if(ns<=1) return  ns;
        int si=0,ei=0,len=0,count=0;
        unordered_map<int,int> map ;
        while(ei<ns){
            if(map[arr[ei++]]++ == 0) count++;
            while(count>2){
                if(map[arr[si++]]-- == 1) count--;
            }
            len = max(len,ei-si);
        }
        return len;
    }
    // number of rabits
    int totalFruit(vector<int>& arr) {
        int ns = arr.size();
        if(ns<=1) return  ns;
        int si=0,ei=0,len=0,count=0;
        unordered_map<int,int> map ;
        while(ei<ns){
            if(map[arr[ei++]]++ == 0) count++;
            while(count>2){
                if(map[arr[si++]]-- == 1) count--;
            }
            len = max(len,ei-si);
        }
        return len;
    }
    
    // find duplicate leetcode 287
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        int count = n-1;
        while(count-->0){
            int ele = arr[0];
            if(arr[ele]==ele) return ele;
            else{
                int a = arr[ele];
                arr[ele] = arr[0];
                arr[0]=a;
            }
        }
        return arr[0];
    }

    



int main(){

}