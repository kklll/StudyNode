package com.kklll.learn.algorithm.leetcode;

import java.util.HashMap;

/**
 * @ClassName EqualSubstring
 * @Deacription 1208. 尽可能使字符串相等  https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
 * @Author DeepBlue
 * @Date 2021/2/5 15:03
 * @Version 1.0
 **/
public class EqualSubstring {
    public int equalSubstring(String s, String t, int maxCost) {
        int[] costs = new int[s.length()];
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            costs[i] = cost(s.charAt(i), t.charAt(i));
        }
        int left = 0;
        int right = 0;
        int sum=0;
        while (right < s.length()) {
            sum+=costs[right];
            while (sum > maxCost) {
                sum-=costs[left];
                left++;
            }
            res = Math.max(right - left+1, res);
            right++;
        }
        return res;
    }

    public int cost(char a, char b) {
        return Math.abs(a - b);
    }

    public static void main(String[] args) {
        EqualSubstring equalSubstring = new EqualSubstring();
        System.out.println(equalSubstring.equalSubstring("abcd",
                "bcdf",
                3));
    }
}
