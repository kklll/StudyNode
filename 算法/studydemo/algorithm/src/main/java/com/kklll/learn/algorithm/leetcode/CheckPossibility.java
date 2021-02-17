package com.kklll.learn.algorithm.leetcode;

import java.util.HashMap;

/**
 * @ClassName CheckPossibility
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/2/7 10:54
 * @Version 1.0
 **/
public class CheckPossibility {
    public boolean checkPossibility(int[] nums) {
//        HashMap
        int res=0;
        for (int i = 0; i < nums.length-1; i++) {
            if (nums[i]>nums[i+1]){
                res++;
                if (res>1){
                    return false;
                }
                if (i>0&&nums[i-1]>nums[i+1]){
                    nums[i+1]=nums[i];
                }
            }
        }
        return true;
    }
}
