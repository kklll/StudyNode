package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName MaxScore
 * @Deacription 1423. 可获得的最大点数  https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
 * @Author DeepBlue
 * @Date 2021/2/6 8:30
 * @Version 1.0
 **/
public class MaxScore {
    public int maxScore(int[] cardPoints, int k) {
        int sum = 0;
        for (int i = 0; i < cardPoints.length; i++) {
            sum += cardPoints[i];
        }
        int size = cardPoints.length - k;
        int sum2 = 0;
        for (int i = 0; i < size; i++) {
            sum2 += cardPoints[i];
        }
        int min = sum2;
        for (int i = size; i < cardPoints.length; i++) {
            sum2 += cardPoints[i] - cardPoints[i - size];
            min = Math.min(sum2, min);
        }
        return sum - min;
    }
}
