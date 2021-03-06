package com.kklll.learn.algorithm.leetcode;


/**
 * @ClassName FlipAndInvertImage
 * @Deacription 832. 翻转图像 https://leetcode-cn.com/problems/flipping-an-image/
 * @Author DeepBlue
 * @Date 2021/2/24 23:04
 * @Version 1.0
 **/
public class FlipAndInvertImage {
    public int[][] flipAndInvertImage(int[][] A) {
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[0].length / 2; j++) {
                int temp = A[i][j];
                A[i][j] = A[i][A[0].length - j - 1];
                A[i][A[0].length - j - 1] = temp;
            }
            for (int j = 0; j < A[0].length; j++) {
                if (A[i][j] == 0) {
                    A[i][j] = 1;
                } else {
                    A[i][j] = 0;
                }
            }
        }
        return A;
    }

}
