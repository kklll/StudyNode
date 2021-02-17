package com.kklll.learn.algorithm.leetcode;

import java.util.Stack;

/**
 * @ClassName evalRPN
 * @Deacription 150. 逆波兰表达式求值 https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 * @Author DeepBlue
 * @Date 2021/2/3 21:35
 * @Version 1.0
 **/
public class evalRPN {
    public int evalRPN(String[] tokens) {
        Stack<Integer> s = new Stack<>();
        for (String i : tokens) {
            if (isNumber(i)) {
                s.push(Integer.valueOf(i));
                continue;
            }
            int op1 = Integer.valueOf(s.pop());
            int op2 = Integer.valueOf(s.pop());
            switch (i) {
                case "+":
                    s.push(op2 + op1);
                    break;
                case "-":
                    s.push(op2 - op1);
                    break;
                case "*":
                    s.push(op2 * op1);
                    break;
                case "/":
                    s.push(op2 / op1);
                    break;
            }
        }
        return s.pop();
    }

    public boolean isNumber(String s) {
        if (!(s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/"))) {
            return true;
        }
        return false;
    }
}
