package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName IsToeplitzMatrix
 * @Deacription 766. 托普利茨矩阵 https://leetcode-cn.com/problems/toeplitz-matrix/
 * @Author DeepBlue
 * @Date 2021/2/22 14:04
 * @Version 1.0
 **/
public class IsToeplitzMatrix {
    public boolean isToeplitzMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (i-1>=0&&j-1>=0){
                    if (matrix[i-1][j-1]!=matrix[i][j]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
