package com.kklll.learn.algorithm.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * @ClassName FindDisappearedNumbers
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/2/13 9:24
 * @Version 1.0
 **/
public class FindDisappearedNumbers {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> res = new ArrayList<>();
        int[] xx = new int[nums.length];
        for (int i = 0; i < xx.length; i++) {
            xx[nums[i]-1]++;
        }
        for (int i = 0; i < xx.length; i++) {
            if (xx[i]==0){
                res.add(i+1);
            }
        }
        return res;
    }
}
