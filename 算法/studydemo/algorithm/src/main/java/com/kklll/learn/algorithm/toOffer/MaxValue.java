package com.kklll.learn.algorithm.toOffer;

/**
 * @ClassName MaxValue
 * @Deacription 剑指 Offer 47. 礼物的最大价值  https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
 * @Author DeepBlue
 * @Date 2021/2/17 11:23
 * @Version 1.0
 **/
public class MaxValue {
    public int maxValue(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (i - 1 < 0 && j - 1 < 0) {
                    continue;
                } else if (i - 1 < 0) {
                    grid[i][j] += grid[i][j - 1];
                } else if (j - 1 < 0) {
                    grid[i][j] += grid[i - 1][j];
                } else {
                    grid[i][j] += Math.max(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid[grid.length - 1][grid[0].length - 1];
    }
}
