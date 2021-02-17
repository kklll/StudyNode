package com.kklll.learn.algorithm.PAT;

import java.util.*;

/**
 * @ClassName QuickSort
 * @Deacription 快速排序实现
 * @Author DeepBlue
 * @Date 2021/1/23 20:08
 * @Version 1.0
 **/
public class QuickSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();
        int[] nums = new int[i];
        for (int j = 0; j < i; j++) {
            nums[j] = sc.nextInt();
        }
        int count = 0;
        List<Integer> res = new ArrayList<>();
        int[] ints = Arrays.copyOfRange(nums, 0, i);
        quickSort(nums, 0, nums.length - 1);
        for (int k = 0; k < i; k++) {
            if (ints[k] == nums[k]) {
                res.add(nums[k]);
                count++;
            }
        }

    }

    public static void quickSort(int[] nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int i = start;
        int j = end;
        int bench = nums[i];
        while (i < j) {
            while (i < j && nums[j] >= bench) {
                j--;
            }
            while (i < j && nums[i] <= bench) {
                i++;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        nums[start] = nums[i];
        nums[i] = bench;
        quickSort(nums, start, i - 1);
        quickSort(nums, i + 1, end);
    }
}
