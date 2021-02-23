package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName Search
 * @Deacription 704. 二分查找   https://leetcode-cn.com/problems/binary-search/
 * @Author DeepBlue
 * @Date 2021/2/23 17:02
 * @Version 1.0
 **/
public class Search {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                while (mid-1>=0&&nums[mid]==nums[mid-1]){
                    mid--;
                }
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
}
