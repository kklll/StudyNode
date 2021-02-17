package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName FindPeakElement
 * @Deacription 162. 寻找峰值 https://leetcode-cn.com/problems/find-peak-element/
 * @Author DeepBlue
 * @Date 2021/2/3 22:12
 * @Version 1.0
 **/
public class FindPeakElement {
    public int findPeakElement(int[] nums) {
        for (int i = 0; i < nums.length-1; i++) {
            if (nums[i]>nums[i+1]){
                return i;
            }
        }
        return nums.length-1;
    }
}
