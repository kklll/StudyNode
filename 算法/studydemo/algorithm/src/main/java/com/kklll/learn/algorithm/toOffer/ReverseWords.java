package com.kklll.learn.algorithm.toOffer;

/**
 * @ClassName ReverseWords
 * @Deacription 剑指 Offer 58 - I. 翻转单词顺序 https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
 * @Author DeepBlue
 * @Date 2021/2/17 14:50
 * @Version 1.0
 **/
public class ReverseWords {
    public String reverseWords(String s) {
        String[] s1 = s.trim().split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = s1.length - 1; i >= 0; i--) {
            if (s1[i].equals("")||s1[i].equals(" ")){
                continue;
            }
            sb.append(s1[i]);
            sb.append(" ");
        }
        return sb.toString().trim();
    }

    public static void main(String[] args) {
        ReverseWords reverseWords = new ReverseWords();
        System.out.println(reverseWords.reverseWords("i am chinese   "));
    }
}
