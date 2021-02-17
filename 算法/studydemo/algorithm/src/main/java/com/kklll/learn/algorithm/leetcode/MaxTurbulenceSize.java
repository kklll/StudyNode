package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName MaxTurbulenceSize
 * @Deacription 978. 最长湍流子数组   https://leetcode-cn.com/problems/longest-turbulent-subarray/
 * @Author DeepBlue
 * @Date 2021/2/8 11:07
 * @Version 1.0
 **/
public class MaxTurbulenceSize {
    public int maxTurbulenceSize(int[] arr) {
        int left = 0;
        int right = 0;
        int res = 1;
        while (right < arr.length - 1) {
            if (left == right) {
                if (arr[left] == arr[right + 1]) {
                    left++;
                }
                right++;
            }else{
                if (arr[right-1]>arr[right]&&arr[right]<arr[right+1]){
                    right++;
                }else if (arr[right-1]<arr[right]&&arr[right]>arr[right+1]){
                    right++;
                }else{
                    left=right;
                }
            }
            res=Math.max(res,right-left+1);
        }
        return res;
    }
}
