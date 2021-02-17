package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName CharacterReplacement
 * @Deacription 424. 替换后的最长重复字符 https://leetcode-cn.com/problems/longest-repeating-character-replacement/
 * @Author DeepBlue
 * @Date 2021/2/2 10:39
 * @Version 1.0
 **/
public class CharacterReplacement {
    /**
     * @author DeepBlue
     * @date: 2021/2/2 11:04
     * @description: 解题思路滑动窗口
     */
    public int characterReplacement(String s, int k) {
        char[] chars = s.toCharArray();
        int res = 0;
        int[] charCount = new int[26];
        for (int i = 0, j = 0; j < chars.length; j++) {
            int index = chars[j] - 'A';
            charCount[index]++;
            while (!check(charCount,k)){
                int idx=chars[i]-'A';
                charCount[idx]--;
                i++;
            }
            res=Math.max(res,j-i+1);
        }
        return res;
    }

    public boolean check(int[] nums, int k) {
        int max = 0;
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            max = Math.max(max, nums[i]);
        }
        return sum - max <= k;
    }
}
