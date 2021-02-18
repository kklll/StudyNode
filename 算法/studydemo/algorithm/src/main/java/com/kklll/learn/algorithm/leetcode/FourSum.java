package com.kklll.learn.algorithm.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @ClassName FourSum
 * @Deacription 18. 四数之和 https://leetcode-cn.com/problems/4sum/
 * @Author DeepBlue
 * @Date 2021/2/18 11:01
 * @Version 1.0
 **/
public class FourSum {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums == null || nums.length < 4) {
            return res;
        }
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            for (int j = i+1; j < nums.length - 2; j++) {
                if (j > i+1 && nums[j - 1] == nums[j]) {
                    continue;
                }
                int left = j + 1;
                int right = nums.length - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        ArrayList<Integer> integers = new ArrayList<>();
                        integers.addAll(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        res.add(integers);
                        left++;
                        right--;
                        while (left<right&&nums[left - 1] == nums[left]) {
                            left++;
                        }
                        while (left<right&&nums[right + 1] == nums[right]) {
                            right--;
                        }
                    }
                }
            }
        }
        return res;
    }
}
