package com.kklll.learn.algorithm.unionfind;

import java.util.Arrays;

/**
 * @ClassName Network
 * @Deacription 并查集 1319. 连通网络的操作次数 https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/
 * @Author DeepBlue
 * @Date 2021/1/23 9:26
 * @Version 1.0
 **/
public class Network {
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) {
            return -1;
        }
        UnionFind uf = new UnionFind(n);
        for (int i = 0; i < connections.length; i++) {
            uf.merge(connections[i][0], connections[i][1]);
        }
        return uf.count - 1;
    }

    class UnionFind {
        int[] father;
        int[] deep;
        int count;

        UnionFind(int n) {
            father = new int[n];
            count = n;
            deep = new int[n];
            for (int i = 0; i < n; i++) {
                father[i] = i;
                deep[i] = 1;
            }
        }

        public boolean merge(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) {
                return false;
            } else if (deep[rootX] >= deep[rootY]) {
                father[rootY] = rootX;
                deep[rootY] += deep[rootX];
            } else {
                father[rootX] = rootY;
                deep[rootX] += deep[rootY];
            }
            count--;
            return true;
        }

        public int find(int x) {
            if (x != father[x]) {
                father[x] = find(father[x]);
            }
            return father[x];
        }

    }

    public static void main(String[] args) {
        Network nt = new Network();
        nt.makeConnected(4, new int[][]{{0, 1}, {0, 2}, {1, 2}});
    }
}
