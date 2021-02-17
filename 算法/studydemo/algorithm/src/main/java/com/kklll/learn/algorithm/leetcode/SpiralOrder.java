package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName spiralOrder
 * @Deacription 剑指 Offer 29. 顺时针打印矩阵  https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
 * @Author DeepBlue
 * @Date 2021/1/26 20:04
 * @Version 1.0
 **/
public class SpiralOrder {
    public int[] spiralOrder(int[][] matrix) {
        int count=0;
        if(matrix.length==0){
            return new int[0];
        }
        int[] res=new int[matrix[0].length*matrix.length];
        int left=0;
        int right=matrix[0].length-1;
        int top=0;
        int buttom=matrix.length-1;
        while(true){
            for(int i=left;i<=right;i++){
                res[count++]=matrix[top][i];
            }
            if(++top>buttom){
                break;
            }
            for(int i=top;i<=buttom;i++){
                res[count++]=matrix[i][right];
            }
            if(--right<left){
                break;
            }
            for(int i=right;i>=left;i--){
                res[count++]=matrix[buttom][i];
            }
            if(--buttom<top){
                break;
            }
            for(int i=buttom;i>=top;i--){
                res[count++]=matrix[i][left];
            }
            if(++left>right){
                break;
            }
        }
        return res;
    }
}
