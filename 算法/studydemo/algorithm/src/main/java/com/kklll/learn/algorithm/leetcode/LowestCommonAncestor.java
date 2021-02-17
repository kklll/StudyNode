package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName LowestCommonAncestor
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/2/1 23:13
 * @Version 1.0
 **/
public class LowestCommonAncestor {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        //都大于
        if (p.val > root.val && q.val > root.val) {
            return lowestCommonAncestor(root.right, p, q);
        }//都小于
        else if (p.val < root.val && q.val < root.val) {
            return lowestCommonAncestor(root.left, p, q);
        }//一大一小
        else {
            return root;
        }
    }
}

