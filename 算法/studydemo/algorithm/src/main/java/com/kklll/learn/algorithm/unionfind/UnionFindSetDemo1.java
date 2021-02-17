package com.kklll.learn.algorithm.unionfind;


/*
省份数量

有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-provinces
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/**
 * class UnionFind {
 * private Map<Integer,Integer> father;
 * <p>
 * public UnionFind() {
 * father = new HashMap<Integer,Integer>();
 * }
 * <p>
 * public void add(int x) {
 * if (!father.containsKey(x)) {
 * father.put(x, null);
 * }
 * }
 * <p>
 * public void merge(int x, int y) {
 * int rootX = find(x);
 * int rootY = find(y);
 * <p>
 * if (rootX != rootY){
 * father.put(rootX,rootY);
 * }
 * }
 * <p>
 * public int find(int x) {
 * int root = x;
 * <p>
 * while(father.get(root) != null){
 * root = father.get(root);
 * }
 * <p>
 * while(x != root){
 * int original_father = father.get(x);
 * father.put(x,root);
 * x = original_father;
 * }
 * <p>
 * return root;
 * }
 * <p>
 * public boolean isConnected(int x, int y) {
 * return find(x) == find(y);
 * }
 * }
 * <p>
 * 作者：MiloMusiala
 * 链接：https://leetcode-cn.com/problems/number-of-provinces/solution/python-duo-tu-xiang-jie-bing-cha-ji-by-m-vjdr/
 * 来源：力扣（LeetCode）
 * 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * @ClassName UnionFindSetDemo1
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/1/18 17:13
 * @Version 1.0
 **/
class Edge{
    public int x;
    public int y;
    public int len;

    Edge(int x,int y,int len){
        this.x=x;
        this.y=y;
        this.len=len;
    }
}
class UnionFind{
    int num = 0;
    private Map<Integer, Integer> father = new HashMap<>();

    public void add(int i) {
        if (!father.containsKey(i)) {
            father.put(i, null);
            num++;
        }
        Queue<Edge> queue=new PriorityQueue<>((o1,o2)-> o1.len-o2.len);
    }

    public Integer find(int i) {
        int root = i;
        while (father.get(root) != null) {
            root = father.get(root);
        }
        //路径压缩
        while (i != root) {
            int originFather = father.get(i);
            father.put(i, root);
            i = originFather;
        }
        return root;
    }

    //合并节点
    public void merge(int i, int j) {
        int rootX = find(i);
        int rootY = find(j);
        if (rootX != rootY) {
            father.put(rootX, rootY);
            num--;
        }
    }

    public boolean connect(int i, int j) {
        return find(i).equals(find(j));
    }
}
/**
 * @author DeepBlue
 */
public class UnionFindSetDemo1 {
    public static void main(String[] args) {
        System.out.println(findCircleNum(new int[][]{}));

    }
    public static int findCircleNum(int[][] isConnected) {
        UnionFind uf=new UnionFind();
        for (int i = 0; i < isConnected.length; i++) {
            uf.add(i);
            for (int j = 0; j < i; j++) {
                uf.merge(i,j);
            }
        }
        return uf.num;
    }

}
