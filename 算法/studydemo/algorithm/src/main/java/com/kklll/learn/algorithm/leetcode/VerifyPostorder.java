package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName VerifyPostorder
 * @Deacription 剑指 Offer 33. 二叉搜索树的后序遍历序列 https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
 * @Author DeepBlue
 * @Date 2021/2/1 22:24
 * @Version 1.0
 **/
public class VerifyPostorder {
    public boolean verifyPostorder(int[] postorder) {
        return recursion(postorder, 0, postorder.length - 1);
    }

    public boolean recursion(int[] postorder, int start, int end) {
        int index = 0;
        if (start >= end) {
            return true;
        }
        for (int i = start; i < end; i++) {
            if (postorder[i] > postorder[end]) {
                index = i;
                break;
            }
        }
        int temp = index;
        while (temp < end) {
            if (postorder[temp++] < postorder[end]) {
                return false;
            }
        }
        return recursion(postorder, start, index - 1) && recursion(postorder, index, end-1);
    }
}
