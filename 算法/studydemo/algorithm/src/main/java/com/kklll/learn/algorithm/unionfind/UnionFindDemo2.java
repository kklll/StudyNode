package com.kklll.learn.algorithm.unionfind;

import java.util.*;

/**
 * @ClassName UnionFindDemo2
 * @Deacription 721. 账户合并 https://leetcode-cn.com/problems/accounts-merge/
 * @Author DeepBlue
 * @Date 2021/1/19 9:36
 * @Version 1.0
 **/
public class UnionFindDemo2 {
    public static void main(String[] args) {
        accountsMerge(null);
    }

    public static List<List<String>> accountsMerge(List<List<String>> accounts) {
        UnionFind2<String> unionFind2 = new UnionFind2<>();
        Map<String, String> mailToCount = new HashMap<>();
        for (int i = 0; i < accounts.size(); i++) {
            int num = accounts.get(i).size();
            for (int j = 1; j < num; j++) {
                if (mailToCount.containsKey(accounts.get(i).get(j))) {
                    unionFind2.merge(String.valueOf(i), mailToCount.get(accounts.get(i).get(j)));
                } else {
                    mailToCount.put(accounts.get(i).get(j), String.valueOf(i));
                }
            }
        }
        Map<String, List<String>> idToMail = new HashMap<>();
        for (Map.Entry<String, String> e : mailToCount.entrySet()) {
            //id
            String s = unionFind2.find(mailToCount.get(e.getValue()));
            List<String> list = idToMail.getOrDefault(s, new ArrayList<String>());
            list.add(e.getKey());
            idToMail.put(s, list);
        }
        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<String, List<String>> e : idToMail.entrySet()) {
            List<String> emails = e.getValue();
            Collections.sort(emails);
            List<String> list = new ArrayList<>();
            list.add(accounts.get(Integer.parseInt(e.getKey())).get(0));
            list.addAll(emails);
            res.add(list);
        }
        return res;
    }

}

class UnionFind2<T> {
    private Map<T, T> parent = new HashMap<>();

    public void add(T key) {
        parent.put(key, null);
    }

    public T find(T t) {
        T root = t;
        while (parent.get(t) != null) {
            root = find(t);
        }
        while (!t.equals(root)) {
            T now_parent = find(t);
            parent.put(t, now_parent);
            t = now_parent;
        }
        return root;
    }

    public void merge(T i, T j) {
        T rootX = find(i);
        T rootY = find(j);
        if (rootX != rootY) {
            parent.put(i, j);
        }
    }

    public boolean isConnect(T i, T j) {
        return find(i).equals(find(j));
    }
}
