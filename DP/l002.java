import java.util.*;
public class l002{
    public static Scanner scn = new Scanner(System.in);
    
    // 44
    // -1 -> default, 0 -> false, 1 -> true
    public int isMatch(String s, String p, int n, int m, int[][] dp) {
        if (n == 0 || m == 0) {
            if (n == 0 && m == 0)
                return dp[n][m] = 1;
            else if (m == 1 && p.charAt(m - 1) == '*')
                return dp[n][m] = 1;
            else
                return dp[n][m] = 0;
        }

        if (dp[n][m] != -1)
            return dp[n][m];

        char ch1 = s.charAt(n - 1);
        char ch2 = p.charAt(m - 1);

        if (ch1 == ch2 || ch2 == '?')
            return dp[n][m] = isMatch(s, p, n - 1, m - 1, dp);
        else if (ch2 == '*') {
            boolean res = false;
            res = res || (isMatch(s, p, n - 1, m, dp) == 1); // map to character
            res = res || (isMatch(s, p, n, m - 1, dp) == 1); // map to empty String

            return dp[n][m] = res ? 1 : 0;
        } else
            return dp[n][m] = 0;
    }

    public String removeStars(String s) {
        if (s.length() == 0)
            return "";
        StringBuilder sb = new StringBuilder();
        sb.append(s.charAt(0));

        int i = 1;
        while (i < s.length()) {
            while (i < s.length() && sb.charAt(sb.length() - 1) == '*' && s.charAt(i) == '*')
                i++;
            if (i < s.length())
                sb.append(s.charAt(i));
            i++;
        }

        return sb.toString();
    }

    public boolean isMatch(String s, String p) {
        p = removeStars(p);
        int n = s.length();
        int m = p.length();

        int[][] dp = new int[n + 1][m + 1];
        for (int[] d : dp)
            Arrays.fill(d, -1);

        return isMatch(s, p, n, m, dp) == 1;
    }

    public static void main(String[] args){
        
    }
}