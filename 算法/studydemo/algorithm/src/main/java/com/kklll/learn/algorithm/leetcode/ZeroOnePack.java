package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName ZeroOnePack
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/3/13 22:03
 * @Version 1.0
 **/
public class ZeroOnePack {
    public static void zeroOnePack(int c, int[] weight, int[] value) {
        int[][] dp = new int[weight.length][c + 1];
        //递推公式：dp[i][j]=Math.max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i])
        for (int j = c; j > 0; j--) {
            dp[0][j] = dp[0][j - weight[0]] + value[0];
        }
        for (int i = 1; i < weight.length; i++) {
            for (int j = 0; j <= c; j++) {
                if (j < weight[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                }
            }
        }
        System.out.println(dp[weight.length - 1][c]);
    }

    public static void zeroOnePack2(int c, int[] weight, int[] value) {
//        int[][] dp = new int[weight.length][c+1];
        int[] dp = new int[c + 1];
        //递推公式：dp[i][j]=Math.max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i])
        for (int i = 0; i < weight.length; i++) {
            for(int j=c;j>=0;j--){
                dp[j]=Math.max(dp[j],dp[j-weight[i]]+value[i]);
            }
        }
        System.out.println(dp[c]);
    }

    public static void main(String[] args) {
        zeroOnePack(4, new int[]{1, 3, 4}, new int[]{15, 20, 30});
    }


}
