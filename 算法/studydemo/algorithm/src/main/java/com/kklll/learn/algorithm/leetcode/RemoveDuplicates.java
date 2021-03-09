package com.kklll.learn.algorithm.leetcode;

import java.util.Stack;

/**
 * @ClassName RemoveDuplicates
 * @Deacription 1047. 删除字符串中的所有相邻重复项 https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
 * @Author DeepBlue
 * @Date 2021/3/9 9:51
 * @Version 1.0
 **/
public class RemoveDuplicates {
    public String removeDuplicates(String S) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < S.length(); i++) {
            if (!stack.isEmpty()&&stack.peek() == S.charAt(i)) {
                stack.pop();
            }else {
                stack.push(S.charAt(i));
            }
        }
        StringBuilder sb = new StringBuilder();
        int n=stack.size();
        for (int i = 0; i < n; i++) {
             sb.append(stack.pop());
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        RemoveDuplicates removeDuplicates = new RemoveDuplicates();
        System.out.println(removeDuplicates.removeDuplicates("aaaaaaaaab"));
    }
}
