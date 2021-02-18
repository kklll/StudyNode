package com.kklll.learn.algorithm.toOffer;

import java.util.Arrays;
import java.util.HashMap;

/**
 * @ClassName TwoSum
 * @Deacription 剑指 Offer 57. 和为s的两个数字  https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
 * @Author DeepBlue
 * @Date 2021/2/17 20:58
 * @Version 1.0
 **/
public class TwoSum {
    /**
     * @author DeepBlue
     * @date: 2021/2/17 21:03
     * @description: 解法1，使用hashmap，每个数去登记自己要的那个数字，如果有匹配的，就返回。
     */
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] res = new int[2];
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                res[0] = nums[i];
                res[1] = target - nums[i];
                return res;
            } else {
                map.put(nums[i], target - nums[i]);
            }
        }
        return res;
    }

    /**
     * @author DeepBlue
     * @date: 2021/2/17 21:04
     * @description: 解法2, 双指针
     */
    public int[] twoSum2(int[] nums, int target) {
        int i = 0;
        int j = nums.length - 1;
        int[] res = new int[2];
        Arrays.sort(nums);
        while (i < j) {
            int sum=nums[i]+nums[j];
            if (sum==target){
                res[0]=nums[i];
                res[1]=nums[j];
                break;
            }
            //如果两数之和大于target，那么需要将j左移，否则将i指针右移
            if (sum>target){
                j--;
            }else{
                i++;
            }
        }
        return res;
    }
}
