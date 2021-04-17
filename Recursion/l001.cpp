#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int coinChangePermutationInfi(vector<int> &arr,int tar,string ans){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(tar-arr[i]>=0)
            count += coinChangePermutationInfi(arr,tar-arr[i],ans+to_string(arr[i]));
    }
    return count;
}

int coinChangeCombinationInfi(vector<int> &arr,int idx,int tar,string ans){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<arr.size();i++){
        if(tar-arr[i]>=0)
            count += coinChangeCombinationInfi(arr,i,tar-arr[i],ans+to_string(arr[i]));
    }
    return count;
}

int coinChangeCombinationSingle(vector<int> &arr,int idx,int tar,string ans){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<arr.size();i++){
        if(tar-arr[i]>=0)
            count += coinChangeCombinationSingle(arr,i+1,tar-arr[i],ans+to_string(arr[i]));
    }
    return count;
}

int coinChangePermutationSingle(vector<int> &arr,int tar,string ans){
    if(tar==0 ){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0 && tar-arr[i]>=0){
            int ele = arr[i];
            arr[i]=-arr[i];
            count += coinChangePermutationSingle(arr,tar-ele,ans+to_string(ele));
            arr[i] = -arr[i];
        }
    }
    return count;
}

int coinChangeCombinationSingleSub(vector<int> &arr,int tar,int idx,string ans){
    if(tar==0 || idx==arr.size()){
        if(tar==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if(tar-arr[idx]>=0){
        count += coinChangeCombinationSingleSub(arr,tar-arr[idx],idx+1,ans+to_string(arr[idx]));
    }
    count += coinChangeCombinationSingleSub(arr,tar,idx+1,ans);
    return count;
}

int coinChangeCombinationInfiSub(vector<int> &arr,int tar,int idx,string ans){
    if(tar==0 || idx==arr.size()){
        if(tar==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if(tar-arr[idx]>=0){
        count += coinChangeCombinationInfiSub(arr,tar-arr[idx],idx,ans+to_string(arr[idx]));
    }
    count += coinChangeCombinationInfiSub(arr,tar,idx+1,ans);
    return count;
}

int coinChangePermuatationInfiSub(vector<int> &arr,int tar,int idx,string ans){
    if(tar==0 || idx==arr.size()){
        if(tar==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if(tar-arr[idx]>=0){
        count += coinChangePermuatationInfiSub(arr,tar-arr[idx],0,ans+to_string(arr[idx]));
    }
    count += coinChangePermuatationInfiSub(arr,tar,idx+1,ans);
    return count;
}

int coinChangePermuatationSingleSub(vector<int> &arr,int tar,int idx,string ans){
    if(tar==0 || idx==arr.size()){
        if(tar==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if(tar-arr[idx]>=0 && arr[idx]>0){
        int ele = arr[idx];
        arr[idx]=-arr[idx];
        count += coinChangePermuatationSingleSub(arr,tar-ele,0,ans+to_string(ele));
        arr[idx]=-arr[idx];
    }
    count += coinChangePermuatationSingleSub(arr,tar,idx+1,ans);
    return count;
}

//  https://www.interviewbit.com/problems/subset/
void find(vector<int> &arr,int idx,vector<int> &small,vector<vector<int>> &res){
    if(idx>=arr.size()) return ;
    
    for(int i=idx;i<arr.size();i++){
        small.push_back(arr[i]);
        res.push_back(small);
        find(arr,i+1,small,res);
        small.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &arr) {
    vector<int> small;
    vector<vector<int>> res;
    sort(arr.begin(),arr.end());
    res.push_back(small);
    find(arr,0,small,res);
    return res;
}

// permutation
vector<int> small;
    vector<vector<int>> res;
    void find(vector<int> &arr,int idx,vector<bool> &vis){
        if(idx==arr.size()){  // idx ki small.size()==arr.size() toh idx ko argument mei lene ki jaraura nhi hoti
            res.push_back(small);
            return ;
        }
        for(int i=0;i<arr.size();i++){
            if(!vis[i]){
                vis[i]=true;
                small.push_back(arr[i]);
                find(arr,idx+1,vis);  // idx no.of elemenet used
                vis[i]=false;
                small.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(),false);
        find(nums,0,vis);
        return res;
    }

// k queen placed in n boxes
int kqueenCombintion1D(int qpsf,int tnq,string ans,int n,int idx){
    if(qpsf==tnq || idx>=n){
        if(qpsf==tnq){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    for(int i=idx;i<n;i++){
        count +=kqueenCombintion1D(qpsf+1,tnq,ans+" b "+to_string(i)+" q "+to_string(qpsf),n,i+1);
    }
    return count;
}

int kqueenCombintion1DSub(int qpsf,int tnq,string ans,int n,int idx){
    if(qpsf==tnq || idx>=n){
        if(qpsf==tnq){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    count +=kqueenCombintion1DSub(qpsf+1,tnq,ans+" b "+to_string(idx)+" q "+to_string(qpsf),n,idx+1);  // idx+1 count taaki pta chle array khtm
    count += kqueenCombintion1DSub(qpsf,tnq,ans,n,idx+1);
    return count;
}

int kqueenPermutation1D(int qpsf,int tnq,string ans,int n,int idx,vector<bool> &vis){
    if(qpsf==tnq || idx>=n){
        if(qpsf==tnq){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i] = true;
            count +=kqueenPermutation1D(qpsf+1,tnq,ans+" b "+to_string(i)+" q "+to_string(qpsf),n,idx+1,vis);  // idx+1 count taaki pta chle array khtm
            vis[i] = false;
        }
    }
    return count;
}

int kqueenPermutation1DSub(int qpsf,int tnq,string ans,int n,int idx,vector<bool> &vis){
    if(qpsf==tnq || idx>=n){
        if(qpsf==tnq){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    
    if(!vis[idx]){
        vis[idx] = true;
        count +=kqueenPermutation1DSub(qpsf+1,tnq,ans+" b "+to_string(idx)+" q "+to_string(qpsf),n,0,vis);  // idx+1 count taaki pta chle array khtm
        vis[idx] = false;
    }
    count += kqueenPermutation1DSub(qpsf,tnq,ans,n,idx+1,vis);
    
    return count;
}

int kqueenCombintion2D(vector<vector<bool>>& boxes,int qpsf,int tnq,string ans,int idx){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int n = boxes.size();
    int m = boxes[0].size();
    int count=0;
    for(int i=idx;i<n*m;i++){
        int r = i/m;
        int c = i%m;
        count +=kqueenCombintion2D(boxes,qpsf+1,tnq,ans+"( "+to_string(r)+" , "+to_string(c)+" )",i+1);
    }
    return count;
}

int kqueenPermutation2D(vector<vector<bool>>& boxes,int qpsf,int tnq,string ans,int idx){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int n = boxes.size();
    int m = boxes[0].size();
    int count=0;
    for(int i=0;i<n*m;i++){
        int r = i/m;
        int c = i%m;
        if(!boxes[r][c]){
            boxes[r][c] = true;
            count +=kqueenPermutation2D(boxes,qpsf+1,tnq,ans+"( "+to_string(r)+" , "+to_string(c)+" )",i+1);
            boxes[r][c] = false;
        }
    }
    return count;
}

int kqueenCombintion2DSub(vector<vector<bool>>& boxes,int qpsf,int tnq,string ans,int idx){
    int n = boxes.size();
    int m = boxes[0].size();
    if(qpsf==tnq || idx >= n*m ){
        if(qpsf==tnq){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    int r = idx/m;
    int c = idx%m;
    count +=kqueenCombintion2DSub(boxes,qpsf+1,tnq,ans+"( "+to_string(r)+" , "+to_string(c)+" )",idx+1);
    count +=kqueenCombintion2DSub(boxes,qpsf,tnq,ans,idx+1);
    return count;
}

int kqueenPermutation2DSub(vector<vector<bool>>& boxes,int qpsf,int tnq,string ans,int idx){
    int n = boxes.size();
    int m = boxes[0].size();
    if(qpsf==tnq || idx >= n*m ){
        if(qpsf==tnq){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    int r = idx/m;
    int c = idx%m;
    if(!boxes[r][c]){
        boxes[r][c]=true;
        count +=kqueenPermutation2DSub(boxes,qpsf+1,tnq,ans+"( "+to_string(r)+" , "+to_string(c)+" )",0);
        boxes[r][c]=false;
    }
    count +=kqueenPermutation2DSub(boxes,qpsf,tnq,ans,idx+1);
    return count;
}

// n queen
vector<vector<int>> dirA = {{0,-1},{-1,-1},{-1,0},{-1,1}};
bool isSafe(vector<vector<bool>> &boxes,int r,int c){
        for(int i=0;i<dirA.size();i++){
            for(int rad=1;rad<=max(boxes.size(),boxes[0].size());rad++){
                int x = r + rad*dirA[i][0];
                int y = c + rad*dirA[i][1];
                if(x>=0 && y>=0 && x<boxes.size() && y<boxes[0].size()){
                    if(boxes[x][y])return false;
                }
                else break;
        }
    }
    return true;
}
int nqueen01(vector<vector<bool>>& boxes,int qpsf,int tnq,string ans,int idx){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int n = boxes.size();
    int m = boxes[0].size();
    int count=0;
    for(int i=idx;i<n*m;i++){
        int r = i/m;
        int c = i%m;
        if(isSafe(boxes,r,c)){
            boxes[r][c]=true;
            count +=nqueen01(boxes,qpsf+1,tnq,ans+"( "+to_string(r)+" , "+to_string(c)+" )",i+1);
            boxes[r][c]=false;
        }
    }
    return count;
}
int nqueen01Sub(vector<vector<bool>>& boxes,int qpsf,int tnq,string ans,int idx){
    int n = boxes.size();
    int m = boxes[0].size();
    if(qpsf==tnq || idx >= n*m ){
        if(qpsf==tnq){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    int r = idx/m;
    int c = idx%m;
    if(isSafe(boxes,r,c)){
        boxes[r][c]=true;
        count +=nqueen01Sub(boxes,qpsf+1,tnq,ans+"( "+to_string(r)+" , "+to_string(c)+" )",idx+1);
        boxes[r][c]=false;
    }
    count +=nqueen01Sub(boxes,qpsf,tnq,ans,idx+1);
    return count;
}
// 2nd Method!!


vector<bool> rowA;
vector<bool> colA;
vector<bool> diagA;
vector<bool> adiagA;
void toggle(int r,int c,int n,int m){
    rowA[r] = !rowA[r];
    colA[c] = !colA[c];
    diagA[r-c+m-1] = !diagA[r-c+m-1];
    adiagA[r+c] = !adiagA[r+c];
}
int nqueen02(int n,int m,int qpsf,int tnq,string ans,int idx){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<n*m;i++){
        int r = i/m;
        int c = i%m;
        if(!rowA[r] && !colA[c] && !diagA[r-c+m-1] && !adiagA[r+c]){
            toggle(r,c,n,m);
            count +=nqueen02(n,m,qpsf+1,tnq,ans+"( "+to_string(r)+" , "+to_string(c)+" )",i+1);
            toggle(r,c,n,m);
        }
    }
    return count;
}

int nqueen02Sub(int n,int m,int qpsf,int tnq,string ans,int idx){
    if(qpsf==tnq || idx >= n*m ){
        if(qpsf==tnq){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    int r = idx/m;
    int c = idx%m;
    if(!rowA[r] && !colA[c] && !diagA[r-c+m-1] && !adiagA[r+c]){
        toggle(r,c,n,m);
        count +=nqueen02Sub(n,m,qpsf+1,tnq,ans+"( "+to_string(r)+" , "+to_string(c)+" )",idx+1);
        toggle(r,c,n,m);
    }
    count +=nqueen02Sub(n,m,qpsf,tnq,ans,idx+1);
    return count;
}

// 3rd Method
int nqueen03(int n,int m,int qpsf,int tnq,string ans,int r){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int c=0;c<m;c++){
        if(!colA[c] && !diagA[r-c+m-1] && !adiagA[r+c]){
            colA[c]=!colA[c]; 
            diagA[r-c+m-1]=!diagA[r-c+m-1];
            adiagA[r+c]=!adiagA[r+c];
            count +=nqueen03(n,m,qpsf+1,tnq,ans+"( "+to_string(r)+" , "+to_string(c)+" )",r+1);
            colA[c]=!colA[c]; 
            diagA[r-c+m-1]=!diagA[r-c+m-1];
            adiagA[r+c]=!adiagA[r+c];
        }
    }
    return count;
}

// USING BITS METHOD 4
int rowB = 0;
int colB = 0;
int diagB = 0;
int adiagB = 0;
bool isBitSet(int n, int k)
{
    int mask = (1 << k);
    return (n & mask) != 0;
}
int setBit(int n , int k){
   int mask = (1 << k);
   n = (n | mask);
   return n;
}
int unsetBit(int n,int k){
    int mask = 1;
    mask = (mask<<k);
    mask = (~mask);
    n = (n & mask);
    return n;
}
int nqueen04(int n,int m,int qpsf,int tnq,string ans,int idx){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<n*m;i++){
        int r = i/m;
        int c = i%m;
        if(!isBitSet(rowB,r) && !isBitSet(colB,c) && !isBitSet(diagB,r-c+m-1) && !isBitSet(adiagB,r+c)){
           rowB = setBit(rowB,r);
           colB = setBit(colB,c);
           diagB = setBit(diagB,r-c+m-1);
           adiagB = setBit(adiagB,r+c);
           count +=nqueen04(n,m,qpsf+1,tnq,ans+"( "+to_string(r)+" , "+to_string(c)+" )",i+1);
           rowB = unsetBit(rowB,r);
           colB =  unsetBit(colB,c);
           diagB =  unsetBit(diagB,r-c+m-1);
           adiagB =  unsetBit(adiagB,r+c);
        }
    }
    return count;
}

// 5 Method

int nqueen05(int n,int m,int qpsf,int tnq,string ans,int r){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int c=0;c<m;c++){
        if( !isBitSet(colB,c) && !isBitSet(diagB,r-c+m-1) && !isBitSet(adiagB,r+c)){
            colB = setBit(colB,c);
           diagB = setBit(diagB,r-c+m-1);
           adiagB = setBit(adiagB,r+c);
            count +=nqueen05(n,m,qpsf+1,tnq,ans+"( "+to_string(r)+" , "+to_string(c)+" )",r+1);
            colB =  unsetBit(colB,c);
           diagB =  unsetBit(diagB,r-c+m-1);
           adiagB =  unsetBit(adiagB,r+c);
        }
    }
    return count;
}

// nqueen using toggle bits

// int colB = 0;
// int diagB = 0;
// int aDiagB = 0;

// void toggleNQueenBit(int r, int c, int n) {
//     colB ^= (1 << c);
//     diagB ^= (1 << (r - c + n - 1));
//     aDiagB ^= (1 << (r + c));
// }

// int nQueen04BitMask(int n, int r, int tnq, string ans) {
//     if (tnq == 0) {
//         cout<<ans<<endl;
//         return 1;
//     }
//     int count = 0;
//     for (int c = 0; c < n; c++) {
//         if ((colB & (1 << c)) == 0 && (diagB & (1 << (r - c + n - 1))) == 0 && (aDiagB & (1 << (r + c))) == 0) {
//             toggleNQueenBit(r, c, n);
//             count += nQueen04BitMask(n, r + 1, tnq - 1, ans + "(" + to_string(r) + "," + to_string(c) + ") ");
//             toggleNQueenBit(r, c, n);
//         }
//     }
//     return count;
// }

//suduko solver
vector<vector<int>> board= {{3, 0, 0, 0, 0, 0, 0, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 1, 0, 0, 8, 0},
                             {9, 0, 0, 8, 6, 3, 0, 0, 5},
                             {0, 5, 0, 0, 9, 0, 6, 0, 0},
                             {1, 3, 0, 0, 0, 0, 2, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 7, 4},
                             {0, 0, 5, 2, 0, 6, 3, 0, 0}};


bool isSafe(int x,int y,int num){
    // row check
    for(int c=0;c<9;c++){
        if(board[x][c]==num) return false;
    }

    // col check
    for(int r=0;r<9;r++){
        if(board[r][y]==num) return false;
    }

    // 3x3 check 
    x=x/3;
    x=x*3;
    y=y/3;
    y=y*3;
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if(board[i][j]==num) return false;
        }
    }

    return true;
}

void display()
{
    for (vector<int> &ar : board)
    {
        for (int ele : ar)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}

int sudokuSolver(int idx){
    if(idx==board.size()*board[0].size()){
        display();
        cout<<endl;
        return 1;
    }
    int r = idx/board[0].size();
    int c = idx % board[0].size();
    int count = 0;

    if(board[r][c]!=0) return sudokuSolver(idx+1);
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(r, c, num))
        {
            board[r][c] = num;
            count += sudokuSolver(idx + 1);
            board[r][c] = 0;
        }
    }
    return count;
}

bool sudokuSolver_01(int idx)
{
     if (idx == board.size() * board[0].size())
    {
        display();
        cout << endl;
        return true;
    }

    int r = idx / board[0].size();
    int c = idx % board[0].size();
    bool res = false;

    if (board[r][c] != 0)
    {
        return sudokuSolver_01(idx + 1);
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(r, c, num))
        {
            board[r][c] = num;
            res = res || sudokuSolver_01(idx + 1);
            board[r][c] = 0;
        }
    }

    return res;
}

bool sudokuSolver_02(vector<int> &loc, int idx)
{
    if (idx == loc.size())
    {
        display();
        cout << endl;
        return true;
    }

    int r = loc[idx] / board[0].size();
    int c = loc[idx] % board[0].size();
    bool res = false;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(r, c, num))
        {
            board[r][c] = num;
            res = res || sudokuSolver_02(loc, idx + 1);
            board[r][c] = 0;
        }
    }

    return res;
}
vector<int> row(9, 0);
vector<int> col(9, 0);
vector<vector<int>> mat(3, vector<int>(3, 0));

void toggleSudokuBit(int r, int c, int num)
{
    int mask = (1 << num);
    row[r] ^= mask;
    col[c] ^= mask;
    mat[r / 3][c / 3] ^= mask;
}

bool sudokuSolver_Bit(vector<int> &loc, int idx)
{
    if (idx == loc.size())
    {
        display();
        cout << endl;
        return true;
    }

    int r = loc[idx] / board[0].size();
    int c = loc[idx] % board[0].size();
    bool res = false;

    for (int num = 1; num <= 9; num++)
    {
        int mask = (1 << num);
        if ((row[r] & mask) == 0 && (col[c] & mask) == 0 && (mat[r / 3][c / 3] & mask) == 0)
        {
            board[r][c] = num;
            toggleSudokuBit(r, c, num);

            res = res || sudokuSolver_Bit(loc, idx + 1);

            board[r][c] = 0;
            toggleSudokuBit(r, c, num);
        }
    }

    return res;
}


void sudoku()
{
    vector<int> loc;
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                loc.push_back(i * m + j);
            else
                toggleSudokuBit(i, j, board[i][j]);
        }
    }
    // cout << sudokuSolver_01(0) << endl;
    // cout << sudokuSolver_02(loc,0) << endl;
    cout << sudokuSolver_Bit(loc,0) << endl;
}




int main(){
    vector<int> arr={2,3,5,7};
    int tar =10;
    vector<bool> vis(6,false);
    // vector<vector<bool>> vis(4,vector<bool>(4,false));
    // cout<<coinChangePermutationInfi(arr,tar,"");
    // cout<<coinChangeCombinationInfi(arr,0,tar,"");
    // cout<<coinChangeCombinationSingle(arr,0,tar,"");
    // cout<<coinChangePermutationSingle(arr,tar,"");
    // cout<<coinChangeCombinationSingleSub(arr,tar,0,"");
    // cout<<coinChangeCombinationInfiSub(arr,tar,0,"");
    // cout<<coinChangePermuatationInfiSub(arr,tar,0,"");
    // cout<<coinChangePermuatationSingleSub(arr,tar,0,"");
    // cout<<kqueenCombintion1D(0,3,"",6,0);
    // cout<<kqueenCombintion1DSub(0,3,"",6,0);
    // cout<<kqueenPermutation1D(0,3,"",6,0,vis);
    // cout<<kqueenPermutation1DSub(0,3,"",6,0,vis);
    //  cout<<kqueenCombintion2D(vis,0,4,"",0);
    //  cout<<kqueenPermutation2D(vis,0,4,"",0);
    //  cout<<kqueenCombintion2DSub(vis,0,4,"",0);
    //  cout<<kqueenPermutation2DSub(vis,0,4,"",0);
    // cout<<nqueen01(vis,0,4,"",0);
    // cout<<nqueen01Sub(vis,0,4,"",0);
    // rowA.resize(4,false);
    // colA.resize(4,false);
    // diagA.resize(7,false);
    // adiagA.resize(7,false);
    // cout<<nqueen02(4,4,0,4,"",0);
    // cout<<nqueen02Sub(4,4,0,4,"",0);
    // cout<<nqueen03(4,4,0,4,"",0);
    // cout<<nqueen04(4,4,0,4,"",0);
    // cout<<nqueen05(4,4,0,4,"",0);

    // sudoku();

    
    return 0;
}