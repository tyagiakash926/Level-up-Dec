

import java.util.*;
public class l001 {
    public static Scanner scn = new Scanner(System.in);

    public static class pair{
        int longestPathLength=0;
        String longestPath="";
        public pair(int longestPathLength,String longestPath){
            this.longestPathLength = longestPathLength;
            this.longestPath=longestPath;
        }
    }

    public static pair longestPath(int sr,int sc,int dr,int dc,boolean[][] vis,int[][] dirA,String[] dirS){
        if(sr==dr && sc==dc){
            return new pair(0, "");
        }
        vis[sr][sc]=true;
        pair myans = new pair(-1,"");
        for(int i=0;i<dirA.length;i++){
            int r = sr + dirA[i][0];
            int c = sc + dirA[i][1];

            if(r>=0 && c>=0 && r<=dr && c<=dc && !vis[r][c]){
                pair recAns = longestPath(r, c, dr, dc, vis, dirA, dirS);
                if(recAns.longestPathLength + 1 > myans.longestPathLength){
                    myans.longestPathLength = recAns.longestPathLength+1;
                    myans.longestPath = dirS[i] + recAns.longestPath; 
                }
            }
        }
        vis[sr][sc]=false;
        return myans;
    }

    public static pair shortestPath(int sr,int sc,int dr,int dc,boolean[][] vis,int[][] dirA,String[] dirS){
        if(sr==dr && sc==dc){
            return new pair(0, "");
        }
        vis[sr][sc]=true;
        pair myans = new pair((int)1e9,"");
        for(int i=0;i<dirA.length;i++){
            int r = sr + dirA[i][0];
            int c = sc + dirA[i][1];

            if(r>=0 && c>=0 && r<=dr && c<=dc && !vis[r][c]){
                pair recAns = shortestPath(r, c, dr, dc, vis, dirA, dirS);
                if(recAns.longestPathLength + 1 < myans.longestPathLength){
                    myans.longestPathLength = recAns.longestPathLength+1;
                    myans.longestPath = dirS[i] + recAns.longestPath; 
                }
            }
        }
        vis[sr][sc]=false;
        return myans;
    }
    public static void main(String[] args){
        boolean[][] vis = new boolean[4][4];
        int[][] dirA = {{-1,0},{0,1},{1,0},{0,-1}};
        String[] dirS = {"U","R","D","L"};
        // pair ans = longestPath(0,0,3,3,vis,dirA,dirS);
        // System.out.println(ans.longestPath +" "+ans.longestPathLength); 
        // pair ans = shortestPath(0,0,3,3,vis,dirA,dirS);
        // System.out.println(ans.longestPath +" "+ans.longestPathLength);
    }   
}
