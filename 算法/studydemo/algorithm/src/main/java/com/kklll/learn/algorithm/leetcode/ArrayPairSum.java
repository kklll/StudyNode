package com.kklll.learn.algorithm.leetcode;

import java.util.Arrays;

/**
 * @ClassName ArrayPairSum
 * @Deacription 561. 数组拆分 I   https://leetcode-cn.com/problems/array-partition-i/
 * @Author DeepBlue
 * @Date 2021/2/16 14:43
 * @Version 1.0
 **/
public class ArrayPairSum {
    public int arrayPairSum(int[] nums) {
        int n = nums.length / 2;
//        quickSort(nums);

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += Math.min(nums[2 * i], nums[2 * i + 1]);
        }
        return res;
    }

    public void quickSort(int[] nums) {
        quickSort(nums, 0, nums.length - 1);
    }

    public void quickSort(int[] nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int i = start;
        int j = end;
        int benchmark = nums[i];
        while (i < j) {
            while (i < j && nums[j] >= benchmark) {
                j--;
            }
            while (i < j && nums[i] <= benchmark) {
                i++;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        nums[start] = nums[j];
        nums[j] = benchmark;
        quickSort(nums, start, j - 1);
        quickSort(nums, j + 1, end);
    }

    public static void main(String[] args) {
        ArrayPairSum arrayPairSum = new ArrayPairSum();
    }
}
