package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName CountBits
 * @Deacription 338. 比特位计数 https://leetcode-cn.com/problems/counting-bits/
 * @Author DeepBlue
 * @Date 2021/3/3 15:22
 * @Version 1.0
 **/
public class CountBits {
    public int[] countBits(int num) {
        int[] res = new int[num + 1];
        for (int i = 0; i <= num; i++) {
            res[i]=bitCount(i);
        }
        return res;
    }

    public int bitCount(int n) {
        int count = 0;
        while (n != 0) {
            if ((n & 1) == 1) {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }

    public static void main(String[] args) {
        CountBits countBits = new CountBits();
        System.out.println(countBits.bitCount(3));
    }
}
