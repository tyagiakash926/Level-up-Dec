#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//Binary Search
int binarySearch(vector<int>& arr, int data){
    int n = arr.size();
    int si =0;
    int ei = n-1;
    while(si<=ei){
        int mid = si + (ei-si)/2 ;
        if(arr[mid]==data) return mid;
        else if(arr[mid]<data) si = mid+1;
        else ei = mid-1;
    }
    return -1;
}
int binarySearchFirstIndex(vector<int>& arr,int data){
    int n = arr.size();
    int si=0,ei=n-1;
    while(si<=ei){
        int mid = (si+ei) / 2 ;
        if(arr[mid]==data){
            if(mid-1<0) return mid;
            if(arr[mid]!=arr[mid-1]) return mid;
            ei = mid-1;
        }else if(arr[mid]<data) si = mid+1;
        else ei = mid-1;
    }
    return -1;
}
int binarySearchLastIndex(vector<int>& arr,int data){
    int n = arr.size();
    int si=0,ei=n-1;
    while(si<=ei){
        int mid = (si+ei) / 2 ;
        if(arr[mid]==data){
            if(mid+1>=n) return mid;
            if(arr[mid]!=arr[mid+1]) return mid;
            si = mid+1;
        }else if(arr[mid]<data) si = mid+1;
        else ei = mid-1;
    }
    return -1;
}
int binarySearchNearestIndex(vector<int>& arr,int data){
    if(arr.size() == 0) return -1;
    
    int n = arr.size();
    if(data <= arr[0] || data >= arr[n - 1]) return data <= arr[0] ? 0 : n - 1;

    int si = 0, ei = n - 1;
    while(si <= ei){
        int mid = (si + ei) / 2;
        if(arr[mid] == data) return mid;
        else if(arr[mid] < data) si = mid + 1;
        else ei = mid - 1;
    }

    // ei = floor, si = ceil.
    return ((data - arr[ei] < arr[si] - data) ? ei : si);
}
//leetcode 35
int searchInsert(vector<int>& arr, int d) {
    int n = arr.size();
    if(d>=arr[n-1]) return (d==arr[n-1]?n-1:n);
    if(d<=arr[0]) return 0;
    int si =0,ei=n-1;
    while(si<=ei){
        int mid = (si+ei)/2;
        if(arr[mid]==d) return mid;
        else if(arr[mid]<d) si=mid+1;
        else ei=mid-1;
    }
    return ei+1;
}
//leetcode 74
bool searchMatrix(vector<vector<int>>& arr, int d) {
    int n = arr.size();
    int m = arr[0].size();
    int si=0,ei=(m*n)-1;
    while(si<=ei){
        int mid = (si+ei)/2;
        if(arr[mid/m][mid%m]==d) return true;
        else if(arr[mid/m][mid%m]<d) si=mid+1;
        else ei=mid-1;
    }
    return false;   
}
//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
long long int totalInversionCount(long long arr[],vector<long long>& sortedArray,long long si,long long mid, long long ei){
    long long i=si,j=mid,k=si,count=0;
    while(i<mid && j<=ei){
        if(arr[i]<=arr[j]) sortedArray[k++]= arr[i++];
        else{
            sortedArray[k++] = arr[j++];
            count += mid-i;
        }
    }
    if(i<mid){
        while(i<mid){
            sortedArray[k++] = arr[i++];
        }
    }
    if(j<=ei){
        while(j<=ei){
            sortedArray[k++] = arr[j++];
        }
    }

    while(si<=ei){
        arr[si] = sortedArray[si++];
    }
    return count;
}
long long int inversionCount(long long arr[],vector<long long>& sortedArray,long long si, long long ei){
    if(si>=ei) return  0;
    long long mid = (si+ei)/2;
    long long count=0;
    count += inversionCount(arr,sortedArray,si,mid);
    count += inversionCount(arr,sortedArray,mid+1,ei);

    count += totalInversionCount(arr,sortedArray,si,mid+1,ei);
    return count;

}
long long int inversionCount(long long arr[], long long N)
{
    if (N == 0)
        return 0;
    vector<long long> sortedArray(N, 0);
    return inversionCount(arr, sortedArray, 0, N - 1);
}
//leetcode 658
int binarySearch(vector<int>& arr, int data){
        int n = arr.size();
        int si = 0,ei=n-1;
        while(si<=ei){
            int mid = si+(ei-si)/2;
            if(arr[mid]==data)  return mid;
            else if(arr[mid]<data) si= mid+1;
            else ei=mid-1;
        }
        return ei+1;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(x<=arr[0]){
             vector<int> ans(arr.begin(),arr.begin()+k);
            return ans;
        }
        if(x>=arr[n-1]){
            vector<int> ans(arr.begin()+n-k,arr.end());
            return ans;
        }
        else{
            int idx =  binarySearch(arr,x);
            int si = max(0, idx - k);
            int ei = min(n - 1, idx + k);
           while ((ei - si + 1) > k)
            {
                if ((x - arr[si]) > (arr[ei] - x))
                    si++;
                else
                    ei--;
            }
            vector<int> ans(arr.begin() + si, arr.begin() + ei + 1); // [si,ei)
            return ans;
        }
    
    }
    // leetcode lis
    int binarySearch(vector<int>& arr,int data){
        int si=0,ei=arr.size()-1;
        while(si<=ei){
            int mid = (si+ei)/2;
            if(arr[mid]==data) return mid;
            else if(arr[mid]<data) si=mid+1;
            else ei=mid-1;
        }
        return ei+1;
    }
    int lengthOfLIS(vector<int>& arr) {
        if(arr.size()<=1) return arr.size();
        vector<int> list;
        for(int i=0;i<arr.size();i++){
            int idx = binarySearch(list,arr[i]);
            if(idx == list.size())
                list.push_back(arr[i]);
            list[idx]=arr[i];
        }
        return list.size();
    }

    // minimize max distance of gas station (lintcode)
    bool  checkValid(vector<int>&arr,double mid,int k){
        int count=0;
        for(int i=1;i<arr.size();i++){
            count += (arr[i]-arr[i-1])/mid;
            if(count>k) return true;
        }
        return false;
    }
    
    double minmaxGasDist(vector<int> &arr, int k) {
        // Write your code here
        
        double lo=0.0;
        double hi=1e9;
        double mid = 0.0;
        while(hi-lo>=1e-5){
            mid = lo+(hi-lo)/2;
            if(checkValid(arr,mid,k)) lo=mid;
            else hi=mid;
        }
        return mid;
    } 

    // leetcode 33
    int search(vector<int>& arr, int data) {
        int si=0;
        int ei=arr.size()-1;
        while(si<=ei){
            int mid = (si+ei)/2;
            if(arr[mid]==data) return mid;
            if(arr[si]<arr[mid]){
                if(arr[si]<=data && arr[mid]>data) ei=mid-1;
                else si=mid+1;
            }else{
                if(arr[ei]>=data && arr[mid]<data) si=mid+1;
                else ei=mid-1;
            }
        }
        return -1;
        
    }
    // leetcode 81
    bool search1(vector<int>& arr, int data) {
        int si=0;
        int ei=arr.size()-1;
        while(si<=ei){
            int mid = (si+ei)/2;
            if(arr[mid]==data || arr[si]==data) return true;
            if(arr[si]<arr[mid]){
                if(arr[si]<=data && arr[mid]>data) ei=mid-1;
                else si=mid+1;
            }else if(arr[ei]>arr[mid]){
                if(arr[ei]>=data && arr[mid]<data) si=mid+1;
                else ei=mid-1;
            }else{
                si++;
            }
        }
        return false;
        
    }

    // find min insorted rotated array
    //153
    int findMin(vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1;
    if(arr[lo] <= arr[hi]) return arr[lo];
    
    while(lo < hi){
        int mid = (lo + hi) / 2;
        
        if(arr[mid] < arr[hi]) hi = mid;
        else if(arr[lo] <= arr[mid]) lo = mid + 1;
        // else lo++; // if ele is duplicate.
    }
    
    return arr[lo];
}

    // find maximum in sorted rotated array
    int findMax(vector<int>& nums) {
        // binary search
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) {
                left = mid;
            } else if (nums[left] > nums[mid]) {
                right = mid - 1;
            } else {    
                // subtility here if there are duplicate elements in the array.
                // shift the left linearly
                left = left + 1;
            }
        }
        return nums[left];
    }

    // leetcode 167
    vector<int> twoSum(vector<int>& arr, int data) {
        int i=0;
        int j = arr.size()-1;
        while(i<j){
            int sum = arr[i]+arr[j];
            if(sum==data) return {i+1,j+1};
            else if(sum>data) j--;
            else i++;
        }
        return {-1,-1};
    }
    //leetcode 2sum
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            if(map.find(target-arr[i])!=map.end()) {
                return {map[target-arr[i]],i};
            }
            if(map.find(arr[i])==map.end()) map[arr[i]]=i;  // input [3,3,4] target = [0,2] ans \/
        }
        return {-1,-1};
    }
    //leetcode 3sum
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int data = 0;
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            while( i != 0 && i < n && arr[i] == arr[i-1]) i++;
            int si = i + 1, ei = n - 1;
            while(si<ei){
                int sum = arr[si]+arr[ei]+arr[i];
                if(sum==data){
                    res.push_back({arr[i],arr[si],arr[ei]});
                    si++;
                    ei--;
                    while( si < ei && arr[si] == arr[si-1]) si++;
                     while( si < ei&& arr[ei] == arr[ei+1]) ei--;
                }else if(sum<data) si++;
                else ei--;
            }
        }
        return res;
    }
   

    //leetcode 4sum
    vector<vector<int>> fourSum(vector<int>& arr, int data) {
        if(arr.size()<4){
            vector<vector<int>> ans;
            return ans;
        }
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
            if(j > i + 1 && arr[j] == arr[j - 1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = arr[i]+arr[j]+arr[k]+arr[l];
                if(sum==data){
                    ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1]) k++;
                    while(k<l && arr[l]==arr[l+1]) l--;
                }else if(sum<data) k++;
                else l--;
            }
        }
        }
        return ans;
    }

    //leetcode 4sum-ii
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> map ;
        int count=0;
        for(int e1:A){
            for(int e2 :B){
                map[e1+e2] = (map.find(e1+e2)!=map.end())?map[e1+e2]+1:1;
            }
        }
        for(int e1:C){
            for(int e2:D){
                count += (map.find(-(e1+e2))!=map.end())?map[-(e1+e2)]:0;
            }
        }
        return count;
    }

    // leetcode 240
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i=n-1,j=0;
        while(i>=0 && i<n && j>=0 && j<m){
            if(matrix[i][j]==target) return true;
            else if (matrix[i][j]>target) i--;
            else j++;
        }
        return false;
    }

    // median of two sorted arrays
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if( n > m ) return (findMedianSortedArrays(nums2,nums1));
        
        int gMid = (n+m+1)/2;  // mid right oreinted h answer left mei milega left mei jyada element honge
        int si=0;
        int ei=n;  // no. of elements pr chala rhe h , na ki index;
        
        while(si<=ei){
             int sMid = (si + ei) >> 1;  // (si + ei) >> 1 == (si+ei)/2 same h 
             int lMid = gMid - sMid;
             int sLeftRegionEle = sMid - 1 >=0 ? nums1[sMid - 1] : -(int)1e8;
             int sRightRegionEle = sMid < n ? nums1[sMid] : (int) 1e8;
             
             int lLeftRegionEle = lMid - 1 >= 0? nums2[lMid - 1] : -(int)1e8;
             int lRightRegionEle = lMid < m ? nums2[lMid] : (int) 1e8;
            
             if(sLeftRegionEle > lRightRegionEle) ei = sMid - 1;
             else if(lLeftRegionEle > sRightRegionEle) si = sMid + 1;
             else{
                  int leftBoundaryEle = max(sLeftRegionEle, lLeftRegionEle);
                int rightBoundaryEle = min(sRightRegionEle,lRightRegionEle);

                if(((n + m) & 1) != 0) return leftBoundaryEle * 1.0;
                else return (leftBoundaryEle + rightBoundaryEle) / 2.0;
             }
             

        }
        return 0.0;
    }

int main(){
    return 0;
}