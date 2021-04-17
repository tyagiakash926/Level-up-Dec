import java.util.Scanner;
import java.util.*;
import java.util.ArrayList;
public class l001{
    public static Scanner scn =new Scanner(System.in);

    public static void seprateInteger(int[] arr) {
        int p=-1;
        int i=0;
        while(i<arr.length){
            if(arr[i]>0){
                p = p+1;
                int a = arr[i];
                arr[i] =arr[p];
                arr[p] = a;
            }
            i++;
        }
    }
    public static void segregate(int[] arr){
        int n = arr.length;
        int p=-1 , i=0,j=n-1;
        while(i<=j && i<n && j>0){
            if(arr[i]==0){
                p=p+1;
                int a = arr[i];
                arr[i] = arr[p];
                arr[p] = a;
                i++;
            }else{
                if(arr[i]==2){
                    int a= arr[i];
                    arr[i]=arr[j];
                    arr[j]=a;
                    j--;
                }else{
                    i++;
                }
            }
        } 
    }
    // sefrate possitive and negative order matters
    public static void segregateOrder(int[] arr){
        int n = arr.length;
        int k = 0;
        int i=0;
        int p=-1;
        while(i<n){
            if(arr[i]>=0){
                i++;
            }else{
                p = p+1;
                k = arr[p];
                arr[p] = arr[i];
                for(int j = p+1;j<=i;j++){
                    int a = arr[j];
                    arr[j] = k;
                    k = a;
                }
                i++;
            }
        }
    }


    public static void maxSubstring(String s){
        int si = 0;
        int ei =0 ,  len =0 , count =0;
        int[] arr = new int[128];
        while(ei<s.length()){
            if(arr[s.charAt(ei++)]++ > 0) count++;

            while(count>0){
                if(arr[s.charAt(si++)]-- >1) count--;
            }

            if(ei-si>len){
                len = ei-si;
            }
        }
        System.out.println(len);
    }
    public static void minimum_window_sliding(String s , String t) {
        int ns = s.length();
        int nt = t.length();
        int si = 0 , ei = 0 , len = ns , head = 0 , count = nt;
        int[] arr = new int[128];
        for(int i=0;i<nt;i++){
            arr[t.charAt(i)]++;
        }
        while(ei<ns){
            if(arr[s.charAt(ei++)]-- > 0) count--;
            while(count==0){
                if(len>ei-si){
                    len = ei-si;
                    head = si;
                }
                if(arr[s.charAt(si++)]++ == 0)  count++;
            }
        }
        return len==(int)1e8?"-1": s.substring(head,head+len);
        System.out.println(s.substring(head,head+len));
    }

    //leetcode 30
    public List<Integer> findSubstring(String str, String[] words) {
        if(str == null || str.length() == 0 || words == null || words.length == 0) {
       return new ArrayList<>();
     }
     
     Map<String, Integer> frequencyMap = new HashMap<>();
     
     for(String word: words) {
       frequencyMap.put(word, frequencyMap.getOrDefault(word, 0) + 1);
     }
     
     int eachWordLength = words[0].length();
     int totalWords = words.length;
     List<Integer> result = new ArrayList<>();
     
     for (int i = 0; i <= str.length() - totalWords * eachWordLength; i++) {
       
       Map<String, Integer> seenWords = new HashMap<>();
       
       for (int j = 0; j < totalWords; j++) {
         int wordIndex = i + j * eachWordLength;
         
         String word = str.substring(wordIndex, wordIndex + eachWordLength);
         
         if(!frequencyMap.containsKey(word)) {
           break;
         }
         
         seenWords.put(word, seenWords.getOrDefault(word, 0) + 1);
         
         if(seenWords.get(word) > frequencyMap.getOrDefault(word, 0)) {
           break;
         }
         
         if(j + 1 == totalWords)   {
           result.add(i);
         }
       }
     }
     
     return result;
         
     }

    public int lengthOfLongestSubstringTwoDistinct(String s) {
        // Write your code here
        int ns = s.length();
        int si =0,ei=0,head=0,len=0;
        int count=0;
        int[] arr = new int[128];
        while(ei<ns){
            if(arr[s.charAt(ei++)]++ == 0) count++;
            
            while(count>2){
                if(arr[s.charAt(si++)]-- == 1) count--;
            }
            
            if(ei-si>len){
                len = ei-si;
                head=si;
            }
        }
        return len;
    }
    //https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring/0#
    public static int Longest_K_unique_characters_substring(String s , int k){
        int ns = s.length();
        if(ns==0 || k==0 ) return 0;
        int si=0,ei=0,len=0,count=0;
        int[] arr=new int[128];
        while(ei<ns){
            if(arr[s.charAt(ei++)]++ == 0 ) count++;
            while(count > k){
                if(arr[s.charAt(si++)]-- == 1) count--;
            }
            if(count==k){
                len = Math.max(len,ei-si);
            }
        }
        return len==0?-1:len;
    }


    //Maximum Number of Vowels in a Substring of Given Length
    public boolean isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    public int maxVowels(String s, int k) {
        int ns = s.length();
        int si =0,ei=0,vowelCount =0 ,maxVowel=0;
        while(ei<ns){
            if(isVowel(s.charAt(ei++))) vowelCount ++;
            if(ei-si==k){
                maxVowel = Math.max(maxVowel,vowelCount);
                if(isVowel(s.charAt(si++))) vowelCount--;
            }
        }
        return maxVowel;
    }
    //https://www.geeksforgeeks.org/count-substrings-that-contain-all-vowels-set-2/
    public static int countSubstringsUtil(String s) {
        int count = 0;
        int n = s.length(); 
        Map<Character, Integer> mp = new HashMap<>(); 
        int ei=0,si=0;
        for(int i=0;i<n;i++){
            if(mp.containsKey(s.charAt(i))) 
            { 
                mp.put(s.charAt(i), mp.get(s.charAt(i)) + 1); 
            } 
            else
            { 
                mp.put(s.charAt(i), 1); 
            } 
            while (mp.containsKey('a') && mp.containsKey('e') && 
               mp.containsKey('i') && mp.containsKey('o') && 
               mp.containsKey('u') && mp.get('a') > 0 &&  
               mp.get('e') > 0 && mp.get('i') > 0 &&  
               mp.get('o') > 0 && mp.get('u') > 0){
                count += n - i; 
                mp.put(s.charAt(si), mp.get(s.charAt(si)) - 1); 
  
                si++; 
            }  
        }
        return count;
    }
    public static int countSubstrings(String s){
        int count =0;
        String temp ="";
        for(int i=0;i<s.length();i++){
            if(isVowel(s.charAt(i))) temp+=s.charAt(i);
            else{
                if(temp.length()>0) count += countSubstringsUtil(temp);
                temp="";
            }
        }
        if(temp.length()>0) count += countSubstringsUtil(temp);

        return count;
    }


    // sliding window maximum with pq
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(k==1) return nums;
        
        int n = nums.length;
        int[] arr = new int[n-k+1]; 
        int idx =0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->{
            return nums[b]-nums[a];
        });
        for(int i=0;i<n;i++){
            while(pq.size()!=0 && pq.peek()<=i-k){
                pq.remove();    
            }
            pq.add(i);
            if(i>=k-1){
                arr[idx++] = nums[pq.peek()];
            }
        }
        return arr;
    }



    // https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
    int maxLen(int[] arr, int N)
    {
        // Your code here
        if(N==0) return 0;
        // HashMap<Integer, String> hash_map = new HashMap<Integer, String>(); 
        HashMap< Integer , Integer > map = new HashMap<Integer,Integer>();
        map.put(0,-1);
        int len = 0;
        int sum = 0;
        for(int i=0;i<N;i++){
            int val = arr[i];
            if(val == 0) val = -1;
            sum += val;
            
            if(map.get(sum) != null){
                len = Math.max(i-map.get(sum) , len);
            } 
            else{
                map.put(sum,i);
            }
        }
        return len;

    }
    // https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1#
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        // Complete the function
        if(n==0) return 0;
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        map.put(0,-1);
        int sum = 0;
        int len = 0;
        int modulus = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            modulus = ( (sum%k) + k )%k ;
            if(map.get(modulus)!=null){
                len = Math.max(len , i-(map.get(modulus)));
            }else{
                map.put(modulus,i);
            }
        }
        return len;
    }
    // leetcode 974
    public int subarraysDivByK(int[] arr, int k) {
        int n = arr.length;
        if(n==0) return 0;
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        map.put(0,1);
        int sum = 0;
        int count = 0;
        int modulus = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            modulus = ( (sum%k) + k )%k ;
            if(map.get(modulus)!=null){
                count += map.get(modulus);
                map.put(modulus,map.get(modulus)+1);
            }else{
                map.put(modulus,1);
            }
        }
        return count;
    }
    // leetcode 781
    public int numRabbits(int[] arr) {
        int n = arr.length;
        if(n==0) return 0;
        HashMap<Integer,Integer> map = new HashMap<>();
        int count =0;
        for(int i=0;i<n;i++){
            if(map.get(arr[i])==null){
                count += (arr[i]+1);
                map.put(arr[i],1);
            }else{
                map.put(arr[i],map.get(arr[i])+1);
            }
            
            if(map.get(arr[i]) == arr[i]+1)
                map.remove(arr[i]);
        }
        return count;
    }
    // leetcode 930
    public int numSubarraysWithSum(int[] arr, int s) {
        int n = arr.length;
        if(n==0) return 0;
        HashMap<Integer,Integer> map = new HashMap<>();
        int count = 0;
        map.put(0,1);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(map.get(sum-s)!= null){
                count += map.get(sum-s);
            }
            
            map.put(sum, map.getOrDefault(sum,0)+1);
            
        }
        return count;
    }
    //2nd method 930 
    
    public int numSubarraysWithAtMostSum(int[] arr,int S){
        int si = 0, ei = 0, count = 0, sum = 0, n = arr.length;
    
        while(ei < n){
            sum += arr[ei++];
    
            while(sum > k){
                sum -= arr[si++];
            }
    
            count += ei - si;
        }
    
        return count;
    }
    
    public int numSubarraysWithSum(int[] arr, int S) {
        int n = arr.length;
        if(n == 0) return 0;
        return numSubarraysWithAtMostSum(arr,S) - (S > 0 ? numSubarraysWithAtMostSum(arr,S - 1) : 0);
    }

    // leetcode 485
    public int findMaxConsecutiveOnes(int[] arr) {
        int n =arr.length;
        if(n==0) return 0;
        int si=0,ei=0,count=0,len=0;
        while(ei<n){
            if(arr[ei++]==0) count++;
            while(count>0)
                if(arr[si++]==0) count--;
            if(ei-si>len) len = ei-si;
        }    
        return len;
    }
    //leetcode total fruits
    public int totalFruit(int[] arr) {
        int n = arr.length;
        int si =0,ei=0,count=0,len=0;
        HashMap<Integer,Integer> map = new HashMap<>();
        while(ei<n){
            if(map.get(arr[ei])!=null) map.put(arr[ei],map.get(arr[ei])+1);
            else{
                count++;
                map.put(arr[ei],1);
            }
            ei++;
            while(count>2){
                if(map.get(arr[si]) == 1){
                    count--;
                    map.remove(arr[si]);
                }else{
                    map.put(arr[si],map.get(arr[si])-1);
                }
                si++;
                
            }
            
            if(ei-si>len) len=ei-si;
        }
        return len;
    }

    // kaden algo
    public static void kadanesAlgo(int[] arr){
        int gMaxSum = -(int)1e8, runningSum = 0;
        for(int ele : arr){
            runningSum += ele;
            
            if(runningSum > gMaxSum) gMaxSum = runningSum;
            
            if(runningSum <= 0) runningSum = 0;
        }
    
        return gMaxSum;
    }

    public static void kadanesAlgoSubarray(int[] arr){
        int gMaxSum = -(int)1e8, runningSum = 0;
        int gsi = 0, gei = 0, rsi = 0; // gsi : gloabl start index, rsi : running start index
        for(int rei = 0; rei < arr.length; rei++){
            runningSum += arr[rei];
            
            if(runningSum > gMaxSum){
                gMaxSum = runningSum;
                gsi = rsi;
                gei = rei;
            }
    
            if(runningSum <= 0){
                runningSum = 0;
                rsi = rei + 1;
            }
        }
        return gMaxSum;
    }
    // ye h orginal kaden's lekin iska dry run mei dikhega nhi ki humne subarray -ve wale bhi liye h!!! 1 try do dry run ko
    public static long kadanesAlgoGeneric(int[] arr){
        long gMaxSum = arr[0], runningSum = arr[0];
        for(int i = 1; i < arr.length; i++){
            runningSum = Math.max(arr[i],runningSum + arr[i]);
            gMaxSum = Math.max(gMaxSum, runningSum);
        }
        
        return gMaxSum;
    }

    // k conacation
    static long mod = (int)1e9 + 7;
    public long kadanesAlgo(int[] arr){
        long gMaxSum = 0, runningSum = 0;
        for(int ele : arr){
            runningSum +=(long)ele;
            
            if(runningSum > gMaxSum) gMaxSum = runningSum;
            
            if(runningSum <= 0) runningSum = 0;
        }
    
        return gMaxSum;
    }
    public long prefixSum(int[] arr){
        long gSum = -(int)1e9;
        long cSum = 0;
        for(int ele : arr){
            cSum = (cSum + ele) % mod;
            gSum = Math.max(gSum, cSum); 
        }

        return gSum;
    }
    public long suffixSum(int[] arr){
        long gSum = -(int)1e9;
        long cSum = 0;
        for(int i=arr.length-1;i>=0;i--){
            cSum = (cSum + arr[i]) % mod;
            gSum = Math.max(gSum, cSum); 
        }

        return gSum;
    }
    
    public int kConcatenationMaxSum(int[] arr, int k) {
        long kadenSum = kadanesAlgo(arr) % mod;
        if(k==1) return (int)kadenSum;
        long sumOfArray = 0;
        for(int ele : arr) sumOfArray += ele;
        long prefixSum = prefixSum(arr);
        long suffixSum = suffixSum(arr);
        if(sumOfArray > 0){
        long APSum = ((k - 2) * sumOfArray  % mod + suffixSum % mod + prefixSum % mod) % mod;
        return (int)Math.max(APSum, kadenSum);
        }else{
            return (int)(Math.max(suffixSum + prefixSum, kadenSum));
        }
    }

    // Best or 2nd method k conacation
    public long kadanesSum(int[] arr,int k){
        int gMaxSum = 0, runningSum = 0;
        int n = arr.length;
        
        for(int i = 0; i < n * k; i++){
            runningSum = (runningSum + arr[i % n]) % mod;
            
            if(runningSum > gMaxSum) gMaxSum = runningSum;
            
            if(runningSum <= 0) runningSum = 0;
        }

        return gMaxSum % mod;
    }

    public int kConcatenationMaxSum(int[] arr, int k) {
        long prevSum = 0;
        for(int i = 1 ; i <= k && i <= 3;i++){
            long KSum =  kadanesSum(arr, i);
            if(i == k) return (int)KSum;
            
            if(i == 3){
                return (int)((prevSum + (k - 2) * (KSum - prevSum)) % mod);
            }

            prevSum = KSum;
        }
        return  0;
    }
    //leetcode  1074
    public int numSubmatrixSumTarget(int[][] arr, int k) {
        int n = arr.length;
        int m = arr[0].length;
        int count=0;
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
                arr[i][j] = arr[i][j] + arr[i-1][j];
        for(int base=0;base<n;base++){
            for(int row=base;row<n;row++){
                HashMap<Integer,Integer> map = new HashMap<>();
                map.put(0,1);
                int presum=0;
                for(int j=0;j<m;j++){
                    presum += arr[row][j] - (base!=0 ? arr[base-1][j] : 0);
                    if(map.get(presum-k)!=null) count += map.get(presum-k);
                    map.put(presum,map.getOrDefault(presum,0)+1);
                }
            }
        }
        return count;
    }
    // leetcode 363
    
    public int maxSumSubmatrix(int[][] arr, int k) {
        int n =arr.length;
        int m =arr[0].length;
        int maxSum = -(int)1e9;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = arr[i][j] + arr[i-1][j];
            }
        }
        
        for(int base=0;base<n;base++){  // kasden ke saath  time pr heavy impact
            for(int row=base;row<n;row++){
                 int gMaxSum = -(int)1e8, runningSum = 0;
        for(int j=0;j<m;j++){
            runningSum += arr[row][j]-(base!=0?arr[base-1][j]:0);
            
            if(runningSum > gMaxSum) gMaxSum = runningSum;
            
            if(runningSum <= 0) runningSum = 0;
            
            if(gMaxSum==k) return k;
        }
    
                if(gMaxSum<k){
                    maxSum = Math.max(maxSum,gMaxSum);
                    continue;  
                } 
                TreeSet<Integer> map = new TreeSet<>();
                int sum = 0;
                map.add(0);
               for(int j = 0; j <m ; j++){
               sum += arr[row][j]-(base!=0?arr[base-1][j]:0);
                    if(map.contains(sum-k)) return k;
                    Integer val = map.ceiling(sum - k);
                    if(val != null){
                        maxSum = Math.max(maxSum,sum - val);
                    }
                    map.add(sum); 
           }
        } 
    }

    return maxSum;
        
    }

    //leetcode 152
    public int maxProduct(int[] arr) {
        int max= arr[0];
        int n = arr.length;
        int l =0;
        int r =0;
        for(int i=0;i<n;i++){
            l = (l==0?1:l)*arr[i];
            r = (r==0?1:r)*arr[n-1-i];
            max = Math.max(max,Math.max(l,r));
        }
        return max;
    }

    //leetcode 26
    public int removeDuplicates(int[] arr) {
        int n = arr.length-1;
        int count=0;
        int j = 0;
        int last = (int) 1e8;
        int i=0;
        while(i<=n){
            if(last==arr[i]){
                if(count==0) count++;
            }else{
                last = arr[i];
                int a = arr[i];
                arr[i]=arr[j];
                arr[j]=a;
                j++;
                count=0;
            }
            
            i++;
        }
        return j;
    }

    // leetcode 80
    public int removeDuplicates2(int[] arr) {
        int n = arr.length-1;
        int count=0;
        int j = 0;
        int last = (int) 1e8;
        int i=0;
        while(i<=n){
            if(last==arr[i]){
                if(count==0){
                    int a = arr[i];
                    arr[i]=arr[j];
                    arr[j]=a;
                    j++;
                    count++;
                }
            }else{
                last = arr[i];
                int a = arr[i];
                arr[i]=arr[j];
                arr[j]=a;
                j++;
                count=0;
            }
            
            i++;
        }
        return j;
    }

    //
    

    public static void main(String[] args){
        // int n = scn.nextInt();
        // int[] arr = new int[n];
        // for(int i=0;i<n;i++){
        //     arr[i] = scn.nextInt();
        // }
        // seprateInteger(arr);
        // segregate(arr);
        // maxSubstring("abcbbcdebb");
        int[] arr = {12, 11, -13, -5, 6, -7, 5, -3, -6};
        segregateOrder(arr);
        // minimum_window_sliding("EDOBACODEBANC" , "ABC");
        for(int d : arr){
            System.out.print(d+" ");
        }
        System.out.println();
    }
}
