package com.kklll.learn.algorithm.toOffer;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * @ClassName LowestCommonAncestor
 * @Deacription 剑指 Offer 68 - II. 二叉树的最近公共祖先  https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
 * @Author DeepBlue
 * @Date 2021/2/15 12:16
 * @Version 1.0
 **/
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

/**
 * @author DeepBlue
 */
public class LowestCommonAncestor {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || p == root || q == root) {
            return root;
        }
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        //如果左右子树都找到公共节点，那么根节点就是公共节点
        if (left != null && right != null) {
            return root;
        } else if (left != null) {
            return left;
        } else if (right != null) {
            return right;
        } else {
            return null;
        }
    }


    public Map<Integer, TreeNode> parents = new HashMap<>();
    public Set<Integer> visited = new HashSet<>();

    public TreeNode lowestCommonAncestor2(TreeNode root, TreeNode p, TreeNode q) {
        dfs(root);
        while (p != null) {
            visited.add(p.val);
            p = parents.get(p.val);
        }
        while (q != null) {
            if (visited.contains(q.val)) {
                return q;
            }else {
                q=parents.get(q.val);
            }
        }
        return null;
    }

    public void dfs(TreeNode root) {
        if (root.left != null) {
            parents.put(root.left.val, root);
            dfs(root.left);
        }
        if (root.right != null) {
            parents.put(root.right.val, root);
            dfs(root.right);
        }
    }
}
