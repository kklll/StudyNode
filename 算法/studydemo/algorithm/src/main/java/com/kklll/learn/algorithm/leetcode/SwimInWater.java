package com.kklll.learn.algorithm.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * @ClassName SwimInWater
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/1/30 14:43
 * @Version 1.0
 **/
public class SwimInWater {

    public static int swimInWater(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) {
            return -1;
        }
        List<int[]> edges=new ArrayList<>();
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i * n + j;
                if (i>0){
                    edges.add(new int[]{id-n,id,Math.max(grid[i-1][j],grid[i][j])});
                }
                if (j>0){
                    edges.add(new int[]{id-1,id,Math.max(grid[i][j-1],grid[i][j])});
                }
            }
        }
        Collections.sort(edges,(o1,o2)->{
            return o1[2]-o2[2];
        });
        int res=0;
        UnionFind uf=new UnionFind(m*n);
        for (int i=0;i<edges.size();i++){
            int i1=edges.get(i)[0];
            int i2=edges.get(i)[1];
            int i3=edges.get(i)[2];
            uf.merge(i1,i2);
            if (uf.isConnect(0,m*n-1)){
                res=i3;
                break;
            }
        }
        return res;
    }


    static class UnionFind {
        public int num;
        public int[] father;
        public int[] depth;

        public UnionFind(int n) {
            num = n;
            father = new int[n];
            depth = new int[n];
            for (int i = 0; i < n; i++) {
                father[i] = i;
                depth[i] = 1;
            }
        }

        public boolean merge(int i, int j) {
            int rootX = find(i);
            int rootY = find(j);
            if (rootX == rootY) {
                return false;
            }
            if (depth[rootX] > depth[rootY]) {
                father[rootY] = rootX;
                depth[rootX] += depth[rootX];
            } else {
                father[rootY] = rootX;
                depth[rootY] += depth[rootX];
            }
            return true;
        }

        public int find(int x) {
            if (father[x] != x) {
                father[x] = find(father[x]);
            }
            return father[x];
        }

        public boolean isConnect(int i, int j) {
            return find(i) == find(j);
        }
    }

    public static void main(String[] args) {
//        int i = swimInWater(new int[][]{{0, 2}, {1, 3}});
        int i = swimInWater(new int[][]{{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}});
        System.out.println(i);
    }
}
