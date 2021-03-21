package com.kklll.learn.algorithm.leetcode;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * @ClassName SetZeroes
 * @Deacription 73. 矩阵置零 https://leetcode-cn.com/problems/set-matrix-zeroes/
 * @Author DeepBlue
 * @Date 2021/3/21 21:05
 * @Version 1.0
 **/
public class SetZeroes {
    public void setZeroes(int[][] matrix) {
        ArrayList<ArrayList<Integer>> mark = new ArrayList<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    mark.add(new ArrayList<Integer>(Arrays.asList(i, j)));
                }
            }
        }
        for (ArrayList<Integer> i : mark) {
            toZero(i.get(0), i.get(1), matrix);
        }
    }

    public void toZero(int i, int j, int[][] matrix) {
        for (int k = 0; k < matrix.length; k++) {
            matrix[k][j] = 0;
        }
        for (int k = 0; k < matrix[0].length; k++) {
            matrix[i][k] = 0;
        }
    }
}
