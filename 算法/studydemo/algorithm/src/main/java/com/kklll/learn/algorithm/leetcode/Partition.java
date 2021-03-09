package com.kklll.learn.algorithm.leetcode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * @ClassName Partition
 * @Deacription 131. 分割回文串  https://leetcode-cn.com/problems/palindrome-partitioning/
 * @Author DeepBlue
 * @Date 2021/3/7 11:03
 * @Version 1.0
 **/
public class Partition {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        Deque<String> path = new ArrayDeque<>();
        if (s.length()==0){
            return res;
        }
        dfs(s, 0, s.length(), path, res);
        return res;
    }

    public void dfs(String s, int index, int len, Deque<String> path, List<List<String>> res) {
        if (index == len) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = index; i < len; i++) {
            if (!isPalindrome(s, index, i)) {
                continue;
            }
            path.addLast(s.substring(index,i+1));
            dfs(s,i+1,len,path,res);
            path.removeLast();
        }
    }

    public boolean isPalindrome(String s, int i, int j) {
        int x = i;
        int y = j;
        while (x < y) {
            if (s.charAt(x) == s.charAt(y)) {
                x++;
                y--;
            } else {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Partition partition = new Partition();
        System.out.println(partition.isPalindrome("aab", 1, 2));
    }
}
