package com.kklll.learn.algorithm.toOffer;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * @ClassName LevelOrder
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/2/17 18:58
 * @Version 1.0
 **/
public class LevelOrder {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        int level = 1;
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.addFirst(root);
        while (!queue.isEmpty()) {
            LinkedList<Integer> part = new LinkedList<>();
            int x = queue.size();
            for (int i = 0; i < x; i++) {
                TreeNode now = queue.peekLast();
                if (now == null) {
                    queue.removeLast();
                } else {
                    if (level % 2 == 1) {
                        part.addLast(now.val);
                    } else {
                        part.addFirst(now.val);
                    }
                    if (now.left != null) {
                        queue.addFirst(now.left);
                    }
                    if (now.right != null) {
                        queue.addFirst(now.right);
                    }
                }
                queue.removeLast();
            }
            res.add(part);
            level++;
        }
        return res;
    }

    public static void main(String[] args) {
        LevelOrder levelOrder = new LevelOrder();
        TreeNode treeNode1 = new TreeNode(3);
        TreeNode treeNode2 = new TreeNode(9);
        TreeNode treeNode3 = new TreeNode(20);
        TreeNode treeNode4 = new TreeNode(15);
        TreeNode treeNode5 = new TreeNode(7);
        treeNode1.left = treeNode2;
        treeNode1.right = treeNode3;
        treeNode3.left = treeNode4;
        treeNode3.right = treeNode5;
        System.out.println(levelOrder.levelOrder(treeNode1));
    }
}
