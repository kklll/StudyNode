package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName 约瑟夫环
 * @Deacription 剑指 Offer 62.
 * 圆圈中最后剩下的数字 https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
 * @Author DeepBlue
 * @Date 2021/1/26 19:49
 * @Version 1.0
 **/
public class LastRemaining {
    public int lastRemaining(int n, int m) {
        int res=0;
        for(int i=2;i<=n;i++){
            res=(res+m)%i;
        }
        return res;
    }
}
