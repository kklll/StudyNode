package com.kklll.learn.algorithm.leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * @ClassName FindShortestSubArray
 * @Deacription 697. 数组的度  https://leetcode-cn.com/problems/degree-of-an-array/
 * @Author DeepBlue
 * @Date 2021/2/20 10:12
 * @Version 1.0
 **/
public class FindShortestSubArray {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, int[]> map = new HashMap<>();
        //先将nums中的数出现频次，起始下标，终止下标进行统计
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                int[] ints = map.get(nums[i]);
                ints[0]++;
                ints[2] = i;
            } else {
                map.put(nums[i], new int[]{1, i, i});
            }
        }
        int res = nums.length+1;
        //最大频次
        int maxCount = 0;
        //遍历元素，找到最频次最高的元素且连续子数组长度最短
        for (Map.Entry<Integer, int[]> entry : map.entrySet()) {
            if (entry.getValue()[0] > maxCount) {
                maxCount = entry.getValue()[0];
                res= entry.getValue()[2] - entry.getValue()[1] + 1;
            }else if (entry.getValue()[0]==maxCount){
                if (res>entry.getValue()[2] - entry.getValue()[1] + 1){
                    res=entry.getValue()[2] - entry.getValue()[1] + 1;
                }
            }
        }
        return res;
    }
}
