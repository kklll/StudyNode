package com.kklll.learn.algorithm.PAT;

import java.util.HashMap;

/**
 * @ClassName Dominos
 * @Deacription 1128. 等价多米诺骨牌对的数量 https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
 * @Author DeepBlue
 * @Date 2021/1/26 10:50
 * @Version 1.0
 **/
public class Dominoes {
    public static int numEquivDominoPairs(int[][] dominoes) {
        int[] nums=new int[100];
        int res=0;
        for(int i=0;i<dominoes.length;i++){
            int val=dominoes[i][0]>dominoes[i][1]?dominoes[i][1]*10+dominoes[i][0]:dominoes[i][0]*10+dominoes[i][1];
            res+=nums[val];
            nums[val]++;
        }
        return res;
    }

    public static void main(String[] args) {
        numEquivDominoPairs(new int[][]{{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}});
    }
}
