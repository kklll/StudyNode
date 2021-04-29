import java.math.BigDecimal;
import java.util.*;

/**
 * @ClassName Main2
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/3/17 15:24
 * @Version 1.0
 **/
//public class Main2 {
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        String next = sc.next();
//        String next2 = sc.next();
//        next=next.split("\\,")[0];
//        next=next.substring(1,next.length()-1);
//        next2=next2.substring(1,next2.length()-1);
//        System.out.println(compare(next, next2));
//    }
//
//    public static int compare(String a, String b) {
//        String[] split1 = a.split("\\.");
//        String[] split2 = b.split("\\.");
//        if (split1.length == split2.length) {
//            int res = 0;
//            for (int i = 0; i < split1.length; i++) {
//                res = split1[i].compareTo(split2[i]);
//                if (res != 0) {
//                    return res;
//                }
//            }
//            return res;
//        } else {
//            if (split2.length > split1.length) {
//                String[] temp = split2;
//                split2 = split1;
//                split1 = temp;
//            }
//            int res = 0;
//            for (int i = 0; i < split2.length; i++) {
//                res = split1[i].compareTo(split2[i]);
//                if (res != 0) {
//                    return res;
//                }
//            }
//            for (int i = split2.length - 1; i < split1.length; i++) {
//                res = split1[i].compareTo("0");
//                if (res != 0) {
//                    return res;
//                }
//            }
//            return res;
//        }
//    }
//}

public class Shopee {

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        public TreeNode() {
        }

        public TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }

        public TreeNode(int val) {
            this.val = val;
        }

        public int getVal() {
            return val;
        }

        public void setVal(int val) {
            this.val = val;
        }

        public TreeNode getLeft() {
            return left;
        }

        public void setLeft(TreeNode left) {
            this.left = left;
        }

        public TreeNode getRight() {
            return right;
        }

        public void setRight(TreeNode right) {
            this.right = right;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String next = sc.next();
        next = next.substring(1, next.length() - 1);
        String[] split = next.split(",");
        TreeNode head = createTree(split);
        List<List<Integer>> lists = levelPrint(head);
        System.out.println(lists);
    }


    public static TreeNode createTree(String[] nodes) {
        TreeNode[] nodes1 = new TreeNode[nodes.length];
        for (int i = 0; i < nodes1.length; i++) {
            if (nodes[i].equals("#")) {
                nodes1[i] = null;
            } else {
                nodes1[i] = new TreeNode(Integer.parseInt(nodes[i]));
            }
        }
        for (int i = 0; i <= nodes.length / 2; i++) {
            if (nodes1[i] == null) {
                continue;
            }
            if (i * 2 + 1 <= nodes.length - 1) {
                nodes1[i].left = nodes1[i * 2 + 1];
            }
            if (i * 2 + 2 <= nodes.length - 1) {
                nodes1[i].right = nodes1[i * 2 + 2];
            }
        }
        return nodes1[0];
    }

    public static List<List<Integer>> levelPrint(TreeNode node) {
        List<List<Integer>> res = new LinkedList<>();
        if (node == null) {
            return res;
        }
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.addLast(node);
        while (!queue.isEmpty()) {
            LinkedList<Integer> res2 = new LinkedList<>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode treeNode = queue.pollFirst();
                res2.add(treeNode.val);
                if (treeNode.left != null) {
                    queue.addLast(treeNode.left);
                }
                if (treeNode.right != null) {
                    queue.addLast(treeNode.right);
                }
            }
            res.add(res2);
        }
        return res;
    }

}
