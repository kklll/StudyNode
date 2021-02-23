package com.kklll.learn.algorithm.leetcode;

import javax.swing.*;

/**
 * @ClassName MaxSatisfied
 * @Deacription 1052. 爱生气的书店老板  https://leetcode-cn.com/problems/grumpy-bookstore-owner/
 * @Author DeepBlue
 * @Date 2021/2/23 13:34
 * @Version 1.0
 **/
public class MaxSatisfied {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int serverCustoms = 0;
        for (int i = 0; i < customers.length; i++) {
            if (grumpy[i] == 0) {
                serverCustoms += customers[i];
            }
        }
        int count=0;
        for (int i = 0; i < X; i++) {
            if (grumpy[i]==1){
                count+=customers[i];
            }
        }
        int maxKeepCustom = count;
        for (int i = X; i < customers.length; i++) {
            count=count-(customers[i-X]*grumpy[i-X])+customers[i]*grumpy[i];
            maxKeepCustom=Math.max(maxKeepCustom,count);
        }
        return maxKeepCustom+serverCustoms;
    }
}
