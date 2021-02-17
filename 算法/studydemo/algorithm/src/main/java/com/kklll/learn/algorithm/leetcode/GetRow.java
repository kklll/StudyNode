package com.kklll.learn.algorithm.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * @ClassName GetRow
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/2/12 12:10
 * @Version 1.0
 **/
public class GetRow {
    public List<Integer> getRow(int rowIndex) {
        int[][] ints = new int[rowIndex+1][rowIndex+1];
        List<Integer> res = new ArrayList<>();
        if (rowIndex==0){
            res.add(1);
            return res;
        }
        ints[0][0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    ints[i][j] = 1;
                } else {
                    ints[i][j] = ints[i - 1][j - 1] + ints[i - 1][j];
                }
                if (i==rowIndex){
                    res.add(ints[i][j]);
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        List<Integer> row = new GetRow().getRow(2);
        System.out.println(row);
    }
}
