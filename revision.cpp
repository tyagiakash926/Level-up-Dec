#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// int coinChangePermutationInfi(vector<int> &arr,int tar,string ans){
//     if(tar==0){
//         cout<<ans<<endl;
//         return 1;
//     }
//     int count=0;
//     for(int i=0;i<arr.size();i++){
//         if(tar-arr[i]>=0) count+=coinChangePermutationInfi(arr,tar-arr[i],ans+to_string(arr[i]));
//     }
//     return count;
// }

// int coinChangeCombinationInfi(vector<int> &arr,int idx,int tar,string ans){
//     if(tar==0){
//         cout<<ans<<endl;
//         return 1;
//     }
//     int count=0;
//     for(int i=idx;i<arr.size();i++){
//         if(tar-arr[i]>=0) count+=coinChangeCombinationInfi(arr,i,tar-arr[i],ans+to_string(arr[i]));
//     }
//     return count;
// }

// int coinChangeCombinationSingle(vector<int> &arr,int idx,int tar,string ans){
//     if(tar==0){
//         cout<<ans<<endl;
//         return 1;
//     }
//     int count=0;
//     for(int i=idx;i<arr.size();i++){
//         if(tar-arr[i]>=0) count+=coinChangeCombinationSingle(arr,i+1,tar-arr[i],ans+to_string(arr[i]));
//     }
//     return count;
// }

// int coinChangePermutationSingle(vector<int> &arr,int tar,string ans){
//     if(tar==0){
//         cout<<ans<<endl;
//         return 1;
//     }
//     int count=0;
//     for(int i=0;i<arr.size();i++){
//         if(arr[i]>0 && tar-arr[i]>=0){
//             int ele = arr[i];
//             arr[i]=-arr[i];
//             count+=coinChangePermutationSingle(arr,tar-ele,ans+to_string(ele));
//             arr[i]=-arr[i];
//         } 
//     }
//     return count;
// }

// int coinChangePermutationSingle(vector<int> &arr,int tar,string ans){
//     if(tar==0){
//         cout<<ans<<endl;
//         return 1;
//     }
//     int count=0;
//     for(int i=0;i<arr.size();i++){
//         if(arr[i]>0 && tar-arr[i]>=0){
//             int ele = arr[i];
//             arr[i]=-arr[i];
//             count+=coinChangePermutationSingle(arr,tar-ele,ans+to_string(ele));
//             arr[i]=-arr[i];
//         } 
//     }
//     return count;
// }

int coinChangeCombinationSingleSub(vector<int> &arr,int tar,int idx,string ans){
    if(tar==0||idx==arr.size()){
        if(tar==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(tar-arr[idx]>=0) count+=coinChangeCombinationSingleSub(arr,tar-arr[idx],idx+1,ans+to_string(arr[idx]));
    count+=coinChangeCombinationSingleSub(arr,tar,idx+1,ans);
    return count;
}

int coinChangeCombinationInfiSub(vector<int> &arr,int tar,int idx,string ans){
    if(tar==0||idx==arr.size()){
        if(tar==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(tar-arr[idx]>=0) count+=coinChangeCombinationInfiSub(arr,tar-arr[idx],idx,ans+to_string(arr[idx]));
    count+=coinChangeCombinationInfiSub(arr,tar,idx+1,ans);
    return count;
}

int coinChangePermuatationInfiSub(vector<int> &arr,int tar,int idx,string ans){
    if(tar==0||idx==arr.size()){
        if(tar==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(tar-arr[idx]>=0) count+=coinChangePermuatationInfiSub(arr,tar-arr[idx],0,ans+to_string(arr[idx]));
    count+=coinChangePermuatationInfiSub(arr,tar,idx+1,ans);
    return count;
}

int coinChangePermuatationSingleSub(vector<int> &arr,int tar,int idx,string ans){
    if(tar==0||idx==arr.size()){
        if(tar==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(arr[idx]>0 && tar-arr[idx]>=0){
        int ele = arr[idx];
        arr[idx]=-arr[idx];
        count+=coinChangePermuatationSingleSub(arr,tar-ele,0,ans+to_string(ele));
        arr[idx]=-arr[idx];
    } 
    count+=coinChangePermuatationSingleSub(arr,tar,idx+1,ans);
    return count;
}








int main(){
    vector<int> arr={2,3,5,7};
    int tar =10;
    // cout<<coinChangePermutationInfi(arr,tar,"");
    // cout<<coinChangeCombinationInfi(arr,0,tar,"");
    // cout<<coinChangeCombinationSingle(arr,0,tar,"");
    // cout<<coinChangePermutationSingle(arr,tar,"");
    // cout<<coinChangeCombinationSingleSub(arr,tar,0,"");
    // cout<<coinChangeCombinationInfiSub(arr,tar,0,"");
    // cout<<coinChangePermuatationInfiSub(arr,tar,0,"");
    cout<<coinChangePermuatationSingleSub(arr,tar,0,"");
    return 0;
}