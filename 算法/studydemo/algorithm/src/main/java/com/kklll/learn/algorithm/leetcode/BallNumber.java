package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName BallNumber
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/1/31 11:56
 * @Version 1.0
 **/
public class BallNumber {
    public int countBalls(int lowLimit, int highLimit) {
        int [] nums=new int[9*5+5];
        int res=0;
        for (int i=lowLimit;i<=highLimit;i++){
            int index = getIndex(i);
            nums[index]++;
            res=Math.max(res,nums[index]);
        }
        return res;
    }
    public int getIndex(int i){
        int res=0;
        while (i!=0){
            res+=i%10;
            i/=10;
        }
        return res;
    }
}
