package com.kklll.learn.algorithm.leetcode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/**
 * @ClassName NextGreaterElements
 * @Deacription 503. 下一个更大元素 II  https://leetcode-cn.com/problems/next-greater-element-ii/
 * @Author DeepBlue
 * @Date 2021/3/6 21:22
 * @Version 1.0
 **/
public class NextGreaterElements {
    public int[] nextGreaterElements(int[] nums) {
        int[] res = new int[nums.length];
        Arrays.fill(res,-1);
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < 2 * nums.length - 1; i++) {
            while (!stack.isEmpty() && nums[i % nums.length] > nums[stack.peek()]) {
                res[stack.pop()] = nums[i % nums.length];
            }
            stack.push(i % nums.length);
        }
        return res;
    }
}
