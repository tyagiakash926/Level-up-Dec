 import java.util.Scanner;
public class l001{
    public static Scanner scn = new Scanner(System.in);

    //Binary Search
    public static int binarySearch(int[] arr, int data){
        int n = arr.length;
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

    public static int binarySearchFirstIndex(int[] arr,int data){
        int n = arr.length;
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

    public static int binarySearchLastIndex(int[] arr,int data){
        int n = arr.length;
        int si=0,ei=n-1;
        while(si<=ei){
            int mid = (si+ei) / 2 ;
            if(arr[mid]==data){
                if(mid+1>n-1) return mid;
                if(arr[mid]!=arr[mid+1]) return mid;
                si = mid+1;
            }else if(arr[mid]<data) si = mid+1;
            else ei = mid-1;
        }
        return -1;
    }

    public static int binarySearchLastIndex(int[] arr,int data){
        int si = 0,ei = arr.length - 1;
        while(si <= ei){
            int mid = (si + ei) / 2;
            if(arr[mid] == data){
                if(mid + 1 < arr.length && arr[mid + 1] == data) si = mid + 1;
                else return mid;
            }else if(arr[mid] < data) si = mid + 1;
            else ei = mid - 1;
        }

        return -1;
    }

    // ceil and floor 
    public static int binarySearchNearestIndex(int[] arr,int data){
        if(arr.length == 0) return -1;
        
        int n = arr.length;
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
    public int searchInsert(int[] arr, int d) {
        int n = arr.length;
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

    // star graph interview question ( bacche ka doubt not based on Searching sorting )
    public static void StarGraph(int[] arr){
        int n = arr.length;
        int highestValue = arr[0];
        int smallestValue = arr[0];
        int negativeHighest = -(int)1e8;
        for(int ele: arr){
            highestValue = Math.max(highestValue,ele);
            smallestValue= Math.min(smallestValue,ele);
            if(ele<0) negativeHighest = Math.max(negativeHighest,ele);
        }
        System.out.println(negativeHighest);
        if(highestValue>=0  && smallestValue>=0){
            int max = highestValue;
            while(max>=1){
                for(int j=0;j<n;j++){
                    if(arr[j]>=max) System.out.print("*");
                    else System.out.print("-");
                }
                System.out.println();
                max--;
            }
        }
        if(highestValue<0  && smallestValue<0){
            while(highestValue>=smallestValue){
                for(int j=0;j<n;j++){
                    if(highestValue>=arr[j]) System.out.print("*");
                    else  System.out.print("-");
                }
                System.out.println();
                highestValue--;
            }
        }

        if(highestValue>0 && smallestValue<0){
            int max = highestValue;
            while(max>=1){
                for(int i=0;i<n;i++){
                    if(arr[i]>=max) System.out.print("*");
                    else{
                        if(max==1 && arr[i]<0) System.out.print("*");
                        else System.out.print("-");
                    } 

                    
                }
                System.out.println();
                max--;
            }
            while(negativeHighest >= smallestValue+1){
                for(int i=0;i<n;i++){
                    if(arr[i]>=0) System.out.print("-");
                    else{
                        if(arr[i]<=negativeHighest) System.out.print("*");
                        else System.out.print("-");
                    }
                }
                System.out.println();
                negativeHighest--;
            }
        }
    }

    // leetcode 75
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length == 0 || matrix[0].length == 0) return false;
        int n = matrix.length, m = matrix[0].length;
        int si = 0, ei = n * m - 1;
        while(si <= ei){
            int mid = (si + ei) / 2;
            int val = matrix[mid / m][mid % m];
    
            if(val == target) return true;
            else if(val < target) si = mid + 1;
            else ei = mid - 1;
        }
        return false;
    }

    //https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
    static long totalInversionCount(long[] arr, long[] sortedArray,  int si,  int mid,  int ei){
        long count=0;
        int i=si,j=mid,k=si;
        while(i<mid && j<=ei){
            if(arr[i]<=arr[j]){
                sortedArray[k++] = arr[i++];
            }else{
                sortedArray[k++] = arr[j++];
                count+=mid-i;
            }
        }
        while (i < mid)
        sortedArray[k++] = arr[i++];
        while (j <= ei)
        sortedArray[k++] = arr[j++];
        while (si <= ei)
        arr[si] = sortedArray[si++];
        return count;
    }
    static long inversionCount(long[] arr, long[] sortedArray, int si,int ei){
        if(si>=ei) return 0;
        int mid = (si+ei)/2;
        long count=0;
        count += inversionCount(arr,sortedArray,si,mid);
        count += inversionCount(arr,sortedArray,mid+1,ei);

        count += totalInversionCount(arr,sortedArray,si,mid+1,ei);
        return count;
    }
    static long inversionCount(long arr[], long N)
    {
        if(N==0) return 0;
        int n = (int)N;
        long[] sortedArray = new long[n];
        return inversionCount(arr,sortedArray,0,n-1);

    }

    // leetcode 775  // lekin iska utube se dekio meri approach bahut tatti h 
    public boolean isIdealPermutation(int[] arr) {
        int n = arr.length;
        int max = arr[0];
        int global = 0,local=0;
        for(int i=0;i<n;i++){
            max= Math.max(max,arr[i]);
            global += (n-1)-max;
            if(i+1<n && arr[i]>arr[i+1]) local+=1;
        }
        global =((n-1)*(n) / 2 ) - global;
        return local==global;
    }

    // leetcode 658 k closest element
    public int binarySearch(int[] A,int x){
        int si = 0;
        int ei=A.length-1;
        while(si<=ei){
            int mid = (si+ei)/2;
            if(A[mid]==x) return mid;
            else if(A[mid]<x) si = mid+1;
            else ei=mid-1;
        }
        return ei+1;
    }
    public List<Integer> findClosestElements(int[] A, int k, int x) {
        List<Integer> arr = new ArrayList<>();
        for(int ele : A) arr.add(ele);
        int n = A.length;
        if(x < A[0]) return arr.subList(0,k);
        else if(x>A[n-1]) return arr.subList(n-k,n);
        else{
            int idx = binarySearch(A,x);   // x will supposed to be
            int si = Math.max(0,idx-k);
            int ei = Math.min(n-1,idx+k);
            while(ei - si + 1 > k){
                if( x-A[si] > A[ei]-x ) si++;
                else ei--;
            }
        } 
    }
    //leetcode 300 lis
    public int binarySearch(List<Integer> list,int ele){
        int si =0;
        int ei=list.size()-1;
        while(si<=ei){
            int mid = (si+ei)/2;
            if(list.get(mid)==ele) return mid;
            else if(list.get(mid)<ele) si = mid+1;
            else ei=mid-1;
        }
        return ei+1;
    }
    public int lengthOfLIS(int[] nums) {
        if(nums.length==0) return 0;
        List<Integer> list = new ArrayList<>();
        for(int ele:nums){
            int idx = binarySearch(list,ele);
            if(idx==list.size()) list.add(ele);
            list.set(idx,ele);
        }
        return list.size();
    }

    //leetcode 875 koko eating banana

    public boolean checkEating(int[] arr,int eatingSpeed ,int H){
        int count=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]%eatingSpeed==0) count += arr[i]/eatingSpeed;
            else count += (arr[i]/eatingSpeed) + 1;

            if(count>H) return false
        }
        return true;
    }
    
    public int minEatingSpeed(int[] piles, int H) {
        int n = piles.length;
        int max =(int)1e9;
        // for(int ele : piles) max = Math.max(max,ele); nhi krunga size 10^6
        int min=1;
        while(min<max){
            int eatingSpeed = min + (max-min)/2;
            if(checkEating(piles,eatingSpeed,H)) max = eatingSpeed;
            else min = eatingSpeed+1;
        }
        return min;
    }


    // leetcode 26
    public int removeDuplicates(int[] arr) {
        int j = arr.length-1;
        int lastEle = (int)1e8;
        for(int i=arr.length-1;i>=0;i--){
            if(lastEle==arr[i]){
                lastEle = arr[i];
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
                j--;
            }else
                lastEle = arr[i];
        }
        Arrays.sort(arr,0,j+1);
        return j+1;
    }
    //leetcode 27
    public int removeElement(int[] arr, int val) {
        int n = arr.length;
        if(n==1 && arr[0]==val) return 0; 
        int si=0,ei=n-1;
        while(si<=ei){
            if(arr[si]!=val) si++;
            else{
                int a = arr[si];
                arr[si]=arr[ei];
                arr[ei]=a;
                ei--;
            }
        }
        return si;
    }

    // maxArea to serve blackRock Interview Question!!!
    public static void isPossibleToServe(double[] area,double area,int k){
        int count = 0;
        for(double ele : area){
            count += ele / area;
            if(count >= k) return true;
        }
    
        return false;
    }

    public static void servingAreaCake(int[] radii,int k){
        int n = radii.length;
        double[] area = new double[n];
    
        double lo = 0.0, hi = 0.0,mid = 0.0;
        for(int i = 0;i < n; i++){
            area[i] = radii[i] * radii[i] * Math.PI;
            hi = Math.max(hi,area[i]);
        }
    
        while(hi - lo > 1e-5){
            mid = lo + (hi - lo) / 2.0;
            if(isPossibleToServe(area,mid,k)) lo = mid;
            else hi = mid;
        }
    
        return mid;
    }


    //leetcode 153 find minimum in rotated array
    public int findMin(int[] arr) {
        int n = arr.length;
        if(n==1) return arr[0];
        int si=0;
        int ei=n-1;
        while(si<=ei){
            int mid = (si+ei)/2;
            if(arr[mid]<arr[(mid+1)%n] && arr[mid]<arr[(mid-1+n)%n]) return arr[mid];
            else if(arr[mid]>arr[si] && arr[mid]<arr[ei]) return arr[si];
            else if(arr[mid]<arr[si]) ei = mid-1;
            else si=mid+1;
        }
        
        return -1;
    }

    // leetcode 15 search in rotated array
    public int findMin(int[] arr) {
        int n = arr.length;
        if(n==1) return 0;
        int si =0;
        int ei=n-1;
        while(si<=ei){
            int mid = (si+ei)/2;
            if(arr[mid]<arr[(mid+1)%n] && arr[mid]<arr[(mid-1+n)%n]) return mid;
            if(arr[mid]>=arr[si] && arr[mid]<=arr[ei]) return si;
            if(arr[mid]>=arr[si] && arr[mid]>=arr[ei]) si = mid+1;
            if(arr[mid]<=arr[si] && arr[mid]<=arr[ei]) ei = mid;
        }
        return -1;
    }
    public int search(int[] arr, int data) {
        int n = arr.length;
        int idx = findMin(arr);
        int si=0,ei=0;
        if(idx>0){
            if(data>=arr[0] && data<=arr[idx-1]){
                si=0;
                ei=idx;
            } 
            else{
                si=idx;
                ei=n-1;
            } 
        }else{
            si=idx;
            ei=n-1;
        }
        
        while(si<=ei){
            int mid=(si+ei)/2;
            if(arr[mid]==data) return mid;
            else if(arr[mid]<data) si=mid+1;
            else ei=mid-1;
        }
        return -1;
    }

    // leetcode 12 Integer to Roman
    public String intToRoman(int n) {
        int[] number = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] RomanNumber = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        String ans= "";
        int i=0;
        int k=0;
        while(n>0){
            k = n/number[i];
            for(int j=0;j<k;j++) ans+=RomanNumber[i];
            n = n%number[i];
            i++;
        }
        return ans;
    }

    //leetcode 13 roman to integer
    public int romanToInt(String s) {
        int sum=0;
           if(s.indexOf("IV")!=-1){sum-=2;}
           if(s.indexOf("IX")!=-1){sum-=2;}
           if(s.indexOf("XL")!=-1){sum-=20;}
           if(s.indexOf("XC")!=-1){sum-=20;}
           if(s.indexOf("CD")!=-1){sum-=200;}
           if(s.indexOf("CM")!=-1){sum-=200;}
           
           char c[]=s.toCharArray();
           int count=0;
           
          for(;count<=s.length()-1;count++){
              if(c[count]=='M') sum+=1000;
              if(c[count]=='D') sum+=500;
              if(c[count]=='C') sum+=100;
              if(c[count]=='L') sum+=50;
              if(c[count]=='X') sum+=10;
              if(c[count]=='V') sum+=5;
              if(c[count]=='I') sum+=1;
              
          }
          
          return sum; 
    }

    // three sum
    public List<List<Integer>> threeSum(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        int data = 0;
        List<List<Integer>> res= new ArrayList<>();
        for(int i=0;i<n;i++){
            while( i != 0 && i < n && arr[i] == arr[i-1]) i++;
            int si = i + 1, ei = n - 1;
            while(si<ei){
                int sum = arr[si]+arr[ei]+arr[i];
                if(sum==data){
                    List<Integer> ar = new ArrayList<>();
                    ar.add(arr[i]);
                    ar.add(arr[si]);
                    ar.add(arr[ei]);
                    res.add(ar);
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
     //leetcode 3 sumcloset
     public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int res = nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sumhere = nums[i]+nums[j]+nums[k];
                if(sumhere == target ) return target;
                
                
                if(Math.abs(sumhere-target) <= Math.abs(res-target)) res = sumhere;
                
                if(sumhere < target) j++;
                else k--;
            }
        }
        return res;
    }
    //leetcode 4sum
    public List<List<Integer>> fourSum(int[] arr, int data) {
        if(arr.length<4){
            List<List<Integer>> ans=new ArrayList<>();
            return ans;
        }
        Arrays.sort(arr);
        int n = arr.length;
        List<List<Integer>> ans=new ArrayList<>();
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
            if(j > i + 1 && arr[j] == arr[j - 1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = arr[i]+arr[j]+arr[k]+arr[l];
                if(sum==data){
                    List<Integer> smallans = new ArrayList<>();
                    smallans.add(arr[i]);
                    smallans.add(arr[j]);
                    smallans.add(arr[k]);
                    smallans.add(arr[l]);
                    ans.add(smallans);
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

    // 4sum 2
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int count=0;
        for(int e1:A){
            for(int e2 :B){
                map.put(e1+e2,map.getOrDefault(e1+e2,0)+1);
            }
        }
        for(int e1:C){
            for(int e2:D){
                count += map.getOrDefault(-(e1+e2),0);
            }
        }
        return count;
    }
    // lletcode 240
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        int i=n-1,j=0;
        while(i>=0 && i<n && j>=0 && j<m){
            if(matrix[i][j]==target) return true;
            else if (matrix[i][j]>target) i--;
            else j++;
        }
        return false;
    }

    // median of two sorted arrays
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
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
                  int leftBoundaryEle = Math.max(sLeftRegionEle, lLeftRegionEle);
                int rightBoundaryEle = Math.min(sRightRegionEle,lRightRegionEle);

                if(((n + m) & 1) != 0) return leftBoundaryEle * 1.0;
                else return (leftBoundaryEle + rightBoundaryEle) / 2.0;
             }
             

        }
        return 0.0;
    }

    // avoid flood in city
    public int[] avoidFlood(int[] rains) {
        int n = rains.length;
        int [] result = new int [n];
        Arrays.fill(result, 1);
        TreeSet<Integer> emptyLake = new TreeSet<>(); // O(logn)
        Map<Integer, Integer> fullLake = new HashMap<>();
        for (int i=0; i<n; i++) {
            int lake = rains[i];
            if (lake > 0) {
                result[i] = -1;
                if (fullLake.containsKey(lake)) {
                    Integer emptyDate = emptyLake.higher(fullLake.get(lake));
                    if (emptyDate == null)
                        return new int [0];
                    result[emptyDate] = lake;
                    emptyLake.remove(emptyDate);
                }
                    fullLake.put(lake, i);
            }
            else {
                emptyLake.add(i);
            }
        }
        return result;
    }
    

    public static void main(String[] args){
        int[] arr = {-5,2,5,7,-8 , 0,3,-2};
        // System.out.println(binarySearchFirstIndex(arr,1));
        // System.out.println(binarySearchLastIndex(arr,1));
        // System.out.println(binarySearchLastIndex(arr,4));
        // System.out.println(binarySearchLastIndex(arr,5));
        // System.out.println(binarySearchLastIndex(arr,6));
        // System.out.println(binarySearchLastIndex(arr,7));
        // System.out.println(binarySearchLastIndex(arr,8));
        // System.out.println(binarySearchLastIndex(arr,10));
        StarGraph(arr);
    } 
}