package com.kklll.learn.algorithm.toOffer;

import java.util.Stack;

/**
 * @ClassName ValidateStackSequences
 * @Deacription 剑指 Offer 31. 栈的压入、弹出序列 https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
 * @Author DeepBlue
 * @Date 2021/2/19 14:43
 * @Version 1.0
 **/
public class ValidateStackSequences {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<>();
        int index = 0;
        for (int x : pushed) {
            stack.push(x);
            while (!stack.isEmpty() && stack.peek() == popped[index]) {
                index++;
                stack.pop();
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        ValidateStackSequences validateStackSequences = new ValidateStackSequences();
        System.out.println(validateStackSequences.validateStackSequences(new int[]{1, 2, 3, 4, 5}, new int[]{2, 4, 3, 5, 1}));
    }
}
