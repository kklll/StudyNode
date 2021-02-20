package com.kklll.learn.algorithm.toOffer;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @ClassName FindContinuousSequence
 * @Deacription 剑指 Offer 57 - II. 和为s的连续正数序列  https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
 * @Author DeepBlue
 * @Date 2021/2/20 20:04
 * @Version 1.0
 **/
public class FindContinuousSequence {
    public int[][] findContinuousSequence(int target) {
        List<int[]> res = new ArrayList<>();
        for (int i = 1; i <= target - 1; i++) {
            int sum = 0;
            int index = 0;
            for (int j = i; j <= target; j++) {
                if (sum == target) {
                    int[] resx = new int[j - i];
                    for (int k = i; k < j; k++) {
                        resx[index++] = k;
                    }
                    res.add(resx);
                    break;
                } else if (sum < target) {
                    sum += j;
                } else {
                    break;
                }
            }
        }
        int[][] res2 = new int[res.size()][];
        for (int i = 0; i < res.size(); i++) {
            res2[i] = res.get(i);
            System.out.println(Arrays.toString(res2[i]));
        }
        return res2;
    }

    public static void main(String[] args) {
        FindContinuousSequence findContinuousSequence = new FindContinuousSequence();
        findContinuousSequence.findContinuousSequence(15);
    }
}
