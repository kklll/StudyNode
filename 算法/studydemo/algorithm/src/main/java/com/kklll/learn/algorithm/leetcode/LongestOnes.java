package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName LongestOnes
 * @Deacription 1004. 最大连续1的个数 III https://leetcode-cn.com/problems/max-consecutive-ones-iii/
 * @Author DeepBlue
 * @Date 2021/2/19 12:10
 * @Version 1.0
 **/
public class LongestOnes {
    public int longestOnes(int[] A, int K) {
        int left = 0;
        int right = left;
        int nowUse = 0;
        int res = 0;
        while (right < A.length) {
            if (A[right] == 0) {
                nowUse++;
            }
            while (nowUse > K) {
                if (A[left++] == 0) {
                    nowUse--;
                }
            }
            res = Math.max(res, right - left + 1);
            right++;
        }
        return res;
    }
}
