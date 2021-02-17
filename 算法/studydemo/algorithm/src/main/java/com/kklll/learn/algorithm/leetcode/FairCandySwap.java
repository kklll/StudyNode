package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName FairCandySwap
 * @Deacription 888. 公平的糖果棒交换 https://leetcode-cn.com/problems/fair-candy-swap/
 * @Author DeepBlue
 * @Date 2021/2/1 0:05
 * @Version 1.0
 **/
public class FairCandySwap {
    public int[] fairCandySwap(int[] A, int[] B) {
        int aCount = 0;
        int bCount = 0;
        int[] res = new int[2];
        for (int i = 0; i < A.length; i++) {
            aCount += A[i];
        }
        for (int j = 0; j < B.length; j++) {
            bCount += B[j];
        }
        int mid = (aCount + bCount) / 2;
        int aNeed = mid - aCount;
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {
                if (B[j] - A[i] == aNeed) {
                    res[0] = A[i];
                    res[1] = B[j];
                    break;
                }
            }
        }
        return res;
    }
}
