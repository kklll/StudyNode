package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName NumSimilarGroups
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/1/31 10:45
 * @Version 1.0
 **/
public class NumSimilarGroups {

    public int numSimilarGroups(String[] strs) {
        UnionFind uf=new UnionFind(strs.length);
        for (int i = 0; i <strs.length; i++) {
            for (int j = i; j <strs.length; j++) {
                if (isSimilar(strs[i],strs[j])){
                    uf.union(i,j);
                }
            }
        }
        return uf.num;
    }

    public boolean isSimilar(String i,String j){
        //长度不同直接不相似
        if (i.length()!=j.length()){
            return false;
        }
        int num=0;
        for (int k = 0; k < i.length(); k++) {
            if (i.charAt(k)!=j.charAt(k)){
                num++;
            }
            if (num>2){
                return false;
            }
        }
        return true;
    }

    class UnionFind{
        int num;
        int[]father;
        int[]depth;
        public UnionFind(int n){
            num=n;
            father=new int[n];
            depth=new int[n];
            for (int i = 0; i < n; i++) {
                depth[i]=1;
                father[i]=i;
            }
        }

        public boolean union(int x,int y){
            int rootX=find(x);
            int rootY=find(y);
            if (rootX==rootY){
                return false;
            }
            if (depth[rootX]>depth[rootY]){
                father[rootY]=rootX;
                depth[rootX]+=depth[rootY];
            }else{
                father[rootX]=rootY;
                depth[rootY]+=depth[rootX];
            }
            num--;
            return true;
        }

        public int find(int i){
            if (i!=father[i]){
                father[i]=find(father[i]);
            }
            return father[i];
        }
    }

    public static void main(String[] args) {
        NumSimilarGroups nm=new NumSimilarGroups();
        System.out.println(nm.numSimilarGroups(new String[]{"omv","ovm"}));
    }
}
