package com.kklll.learn.algorithm.leetcode;

import java.util.Arrays;

/**
 * @ClassName MinPathSum
 * @Deacription 64. 最小路径和  https://leetcode-cn.com/problems/minimum-path-sum/
 * @Author DeepBlue
 * @Date 2021/3/17 19:02
 * @Version 1.0
 **/
public class MinPathSum {
    //递推公式 dp[i][j]=Math.min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
    public int minPathSum(int[][] grid) {
        int[][] dp = new int[grid.length][grid[0].length];
        int sum = 0;
        int sum1 = 0;
        for (int i = 0; i < grid[0].length; i++) {
            sum += grid[0][i];
            dp[0][i] = sum;
        }
        for (int i = 0; i < grid.length; i++) {
            sum1 += grid[i][0];
            dp[i][0] = sum1;
        }
        for (int i = 1; i < grid.length; i++) {
            for (int j = 1; j < grid[0].length; j++) {
                dp[i][j] = Math.min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        for (int i = 0; i < dp.length; i++) {
            System.out.println(Arrays.toString(dp[i]));
        }
        return dp[grid.length - 1][grid[0].length - 1];
    }
}
