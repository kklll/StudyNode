package com.kklll.learn.algorithm.PAT;

import java.util.Scanner;

/**
 * @ClassName ABFormat
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/1/20 20:15
 * @Version 1.0
 **/
public class ABformat {
    public static void main(String[] args) {
//        Scanner in = new Scanner(System.in);
//        boolean flag=false;
//        int a = in.nextInt();
//        int b = in.nextInt();
//        int count = a + b;
//        if (count<0) {
//            flag = true;
//        }
//        System.out.printf("%d,%03d,%03d",count/1000000, count%1000000/1000, count%1000);
//        String s="123";
//        System.out.println(s.charAt(0));
        int a=1;
        int add = add(a);
        System.out.println(add);
    }

    public static int add(int i){
        i=i+1;
        return i;
    }
}
