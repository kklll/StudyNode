package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName MatrixReshape
 * @Deacription 566. 重塑矩阵 https://leetcode-cn.com/problems/reshape-the-matrix/
 * @Author DeepBlue
 * @Date 2021/2/17 1:02
 * @Version 1.0
 **/
public class MatrixReshape {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int row = nums.length;
        int column = nums[0].length;
        if (r * c != row * column) {
            return nums;
        }
        int[][] res = new int[r][c];
        int count=0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j]=nums[count/column][count%column];
                count++;
            }
        }
        return res;
    }
}
