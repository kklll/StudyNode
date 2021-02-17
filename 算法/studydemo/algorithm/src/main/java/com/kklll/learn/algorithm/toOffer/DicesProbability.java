package com.kklll.learn.algorithm.toOffer;

/**
 * @ClassName DicesProbability
 * @Deacription 剑指 Offer 60. n个骰子的点数 https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
 * @Author DeepBlue
 * @Date 2021/2/15 23:56
 * @Version 1.0
 **/
public class DicesProbability {
    public double[] dicesProbability(int n) {
        //二维数组用来存储递归计算出的数据，P[i][j]
        double[][] res = new double[n + 1][6 * n + 1];
        //初始化1-6的概率
        for (int i = 1; i <= 6; i++) {
            res[1][i] = (double) 1 / 6;
        }
        //表示层数即P[i][j]中的i
        for (int i = 2; i <= n; i++) {
            //表示层数即P[i][j]中的j，因为n个骰子点数不可能小于n，所以j=i
            for (int j = i; j <= 6 * i; j++) {
                //通过计算P[i][j-k]计算出前面的骰子点数的概率
                for (int k = 1; k <= 6; k++) {
                    if (j - k < 1) {
                        continue;
                    }
                    //计算P[i][j]
                    res[i][j] += res[1][k] * res[i - 1][j - k];
                }
            }
        }
        //结果的个数，因为n个骰子，个数和是6*n-n+1=5n+1
        double[] r = new double[5 * n + 1];
        //res[i][j]中j的其实位置从n开始
        int index = n;
        for (int i = 0; i < r.length; i++) {
            r[i] = res[n][index++];
        }
        return r;
    }
}
