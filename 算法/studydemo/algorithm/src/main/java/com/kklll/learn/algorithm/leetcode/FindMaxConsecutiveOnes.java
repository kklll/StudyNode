package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName FindMaxConsecutiveOnes
 * @Deacription 485. 最大连续1的个数 https://leetcode-cn.com/problems/max-consecutive-ones/
 * @Author DeepBlue
 * @Date 2021/2/15 10:08
 * @Version 1.0
 **/
public class FindMaxConsecutiveOnes {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        int nowCount = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                nowCount++;
            } else {
                max = Math.max(nowCount, max);
                nowCount = 0;
            }
        }
        max = Math.max(nowCount, max);
        return max;
    }

    public static void main(String[] args) {
        FindMaxConsecutiveOnes findMaxConsecutiveOnes = new FindMaxConsecutiveOnes();
        System.out.println(findMaxConsecutiveOnes.findMaxConsecutiveOnes(new int[]{1, 0, 1, 1, 0, 1}));
    }
}
