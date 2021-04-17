#include <iostream>
#include<set>
#include<vector>
using namespace std;

int offToON(int n, int k)
{
    int mask = (1 << k);
    return (n | mask);
}

int onToOff(int n, int k)
{
    int mask = (~(1 << k));
    return (n & mask);
}

bool isBitSet(int n, int k)
{
    int mask = (1 << k);
    return (n & mask) != 0;
}

int hammingWeight(int n)
{

    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        int mask = (1 << i);
        if ((n & mask) != 0)
            count++;
    }

    return count;
}

int hammingWeight(int n)
{
    int count = 0;
    int bitsCount = 0;
    while (n != 0 && bitsCount < 32)
    {
        if ((n & 1) != 0)
            count++;
        n >>= 1;
        bitsCount++;
    }

    return count;
}

int hammingWeight(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n &= (n - 1);
    }

    return count;
}
int lastSetBit(int n){
    int lsb = 0;
    while (n != 0)
    {
        lsb = (n&(-n));
        n &= (n - 1); 
    }

    return lsb;
}
//leetcode 693
bool hasAlternatingBits(int n) {
    int cur = 0, pre = -1;
    while(n != 0) {
        cur = n & 1;
        if(cur == pre) return false;
        n >>= 1;
        pre = cur;
    }
    return true;
}
//leetcode 461
 int hammingDistance(int x, int y) {
    int n = (x^y);
    int count=0;
    while(n!=0){
        n=(n&(n-1));
        count++;
    }
    return count;
}
//leetcode 762
int countPrimeSetBits(int L, int R) {
    set<int> prime={2,3,5,7,11,13,17,19,23,29};
    
    int count =0;
    for(int i=L;i<=R;i++){
        int cnt=0;
        int n = i;
        while(n!=0){
            cnt++;
            n = (n&(n-1));
        }
        count += prime.count(cnt);
    }
    return count;
}

// leetcode 1342
int numberOfSteps (int num) {
    int count=0;
    while(num!=0){
        if((num&1)!=0){
            num = (num&(~1));
            count++;
        }else{
            num=num>>1;
            count++;
        }
    }
    return count;
}

// leetcode 1720
vector<int> decode(vector<int>& encoded, int first) {
    int n = encoded.size();
    vector<int> ans(n+1,0);
    ans[0] = first;
    for(int i=0;i<n;i++){
        ans[i+1] = (encoded[i]^ans[i]);
    }
    return ans;
}

// Decode xor permutation leetcode=> 1734
vector<int> decode(vector<int>& encoded) {
int n = encoded.size();
int total_xor = 0;

for(int i =1;i<=n+1;i++){
    total_xor = total_xor^i;
    if(i<n && (i&1)!=0) total_xor=total_xor^encoded[i];
}
vector<int> ans(n+1,0);
ans[0] = total_xor;
for(int i=0;i<n;i++){
    ans[i+1] = (encoded[i]^ans[i]);
}
return ans;
}

// leetcode 645
vector<int> findErrorNums(vector<int>& arr) {
    int duplicate = 0;
    int idx =0;
    while(true && idx<arr.size()){
        if(arr[idx]-1==idx){
            idx++;
            continue;
        }else{
            int ele = arr[idx];
            if(arr[ele-1]==arr[idx]){
                duplicate = ele;
                break;
            }else{
                int a = arr[ele-1];
                arr[ele-1] = arr[idx];
                arr[idx]=a;
            }
        }
    }
    int ans =0;
    for(int i=0;i<arr.size();i++){
        ans^=arr[i];
        ans^=i+1;
    }
    ans^=duplicate;
    // cout<<duplicate<<endl;
    return {duplicate,ans};
}
// single number ii
int singleNumber(vector<int>& nums) {
    int single=0;
    int mask =1;
    for(int i=0;i<32;i++){
        mask = 1<<i;
        int count = 0;
        for(int num:nums){
            if((num&mask)!=0) count++;
        }
        if((count%3)!=0){
            count = count%3;
            count = count<<i;
            single |= count; 
        }
    }
    return single;
}
//leetcode find compliment 476
int findComplement(int num) {
    int ans =0;
    int idx =0;
    while(num!=0){
        int lb = (num&1);
        if(lb==0) lb = 1;
        else lb = 0;
        ans = (ans | (lb<<idx));
        idx++;
        num=(num>>1);
    }
    return ans;
}
//leetcode 477. total hamming distance b/w all pair
int totalHammingDistance(vector<int>& nums) {
    int size = nums.size();
    if(size < 2) return 0;
    int ans = 0;
    int *zeroOne = new int[2];
    while(true)
    {
        int zeroCount = 0;
        zeroOne[0] = 0;
        zeroOne[1] = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) zeroCount++;
            zeroOne[(nums[i]&1)]++;
            nums[i] = nums[i] >> 1;
        }
        ans += zeroOne[0] * zeroOne[1];
        if(zeroCount == nums.size()) return ans;
    }
}




int main(){
    return 0;
}