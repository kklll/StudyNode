package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName longestCommonSubsequence
 * @Deacription 1143.最长公共子序列 https://leetcode-cn.com/problems/longest-common-subsequence/
 * @Author DeepBlue
 * @Date 2021/4/11 0:02
 * @Version 1.0
 **/
public class LongestCommonSubsequence {
    public int longestCommonSubsequence(String text1, String text2) {
        char[] chars = text1.toCharArray();
        char[] chars1 = text2.toCharArray();
        int[][] dp = new int[chars.length + 1][chars1.length + 1];
        for (int i = 1; i < chars.length + 1; i++) {
            for (int j = 1; j < chars1.length + 1; j++) {
                if (chars[i - 1] == chars1[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[chars.length][chars1.length];
    }
}
