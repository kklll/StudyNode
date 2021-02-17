package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName TwoSum
 * @Deacription 167. 两数之和 II - 输入有序数组 https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * @Author DeepBlue
 * @Date 2021/1/26 22:28
 * @Version 1.0
 **/
public class TwoSum {
    public int[] twoSum(int[] numbers, int target) {
        int [] res=new int[2];
        int left=0;
        int right=numbers.length-1;
        while(left<right){
            int sum=numbers[left]+numbers[right];
            if (sum==target){
                break;
            }else if (sum>target){
                right--;
            }else{
                left++;
            }
        }
        res[0]=left+1;
        res[1]=right+1;
        return res;
    }
}
