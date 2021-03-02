package com.kklll.learn.algorithm.leetcode;

import java.util.Arrays;

/**
 * @ClassName NumMatrix
 * @Deacription 304. 二维区域和检索 - 矩阵不可变  https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
 * @Author DeepBlue
 * @Date 2021/3/2 13:49
 * @Version 1.0
 **/
public class NumMatrix {
    public int[][] sums;

    public NumMatrix(int[][] matrix) {
        int m=0;
        int n=0;
        if (matrix.length!=0){
            m=matrix.length;
            n=matrix[0].length;
        }
        sums = new int[m][n];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    sums[i][j] = sums[i][j - 1] + sums[i - 1][j] + matrix[i][j] - sums[i - 1][j - 1];
                } else if (i - 1 >= 0) {
                    sums[i][j] = sums[i - 1][j] + matrix[i][j];
                } else if (j - 1 >= 0) {
                    sums[i][j] = sums[i][j - 1] + matrix[i][j];
                } else {
                    sums[i][j] = matrix[i][j];
                }
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 - 1 >= 0 && col1 - 1 >= 0) {
            return sums[row2][col2] - sums[row1 - 1][col2] - sums[row2][col1 - 1] + sums[row1 - 1][col1 - 1];
        } else if (row1 - 1 >= 0) {
            return sums[row2][col2] - sums[row1 - 1][col2];
        } else if (col1 - 1 >= 0) {
            return sums[row2][col2] - sums[row2][col1 - 1];
        } else {
            return sums[row2][col2];
        }
    }

    public static void main(String[] args) {
        NumMatrix numMatrix = new NumMatrix(new int[][]{
                {3, 0, 1, 4, 2},
                {5, 6, 3, 2, 1},
                {1, 2, 0, 1, 5},
                {4, 1, 0, 1, 7},
                {1, 0, 3, 0, 5}
        });
        for (int i = 0; i < numMatrix.sums.length; i++) {
            System.out.println(Arrays.toString(numMatrix.sums[i]));
        }

        System.out.println(numMatrix.sumRegion(0, 0, 2, 4));
    }
}
