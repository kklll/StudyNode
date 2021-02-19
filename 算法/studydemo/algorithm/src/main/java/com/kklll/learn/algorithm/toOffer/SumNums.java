package com.kklll.learn.algorithm.toOffer;

/**
 * @ClassName SumNums
 * @Deacription 剑指 Offer 64. 求1+2+…+n  https://leetcode-cn.com/problems/qiu-12n-lcof/
 * @Author DeepBlue
 * @Date 2021/2/19 15:10
 * @Version 1.0
 **/
public class SumNums {
    int res = 0;

    public int sumNums(int n) {
        boolean x = n > 0 && sumNums(n - 1) > 0;
        res += n;
        return res;
    }

    public static void main(String[] args) {
        SumNums sumNums = new SumNums();
        System.out.println(sumNums.sumNums(5));
    }
}
