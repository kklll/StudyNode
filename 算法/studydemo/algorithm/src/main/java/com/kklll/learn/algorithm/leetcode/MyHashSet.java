package com.kklll.learn.algorithm.leetcode;

import java.util.Iterator;
import java.util.LinkedList;

/**
 * @ClassName MyHashSet
 * @Deacription 705. 设计哈希集合    https://leetcode-cn.com/problems/design-hashset/
 * @Author DeepBlue
 * @Date 2021/3/13 10:35
 * @Version 1.0
 **/
class MyHashSet {
    private static final int BASE = 769;
    private LinkedList[] data;

    /** Initialize your data structure here. */
    public MyHashSet() {
        data = new LinkedList[BASE];
        for (int i = 0; i < BASE; ++i) {
            data[i] = new LinkedList<Integer>();
        }
    }

    public void add(int key) {
        int h = hash(key);
        Iterator<Integer> iterator = data[h].iterator();
        while (iterator.hasNext()) {
            Integer element = iterator.next();
            if (element == key) {
                return;
            }
        }
        data[h].offerLast(key);
    }

    public void remove(int key) {
        int h = hash(key);
        Iterator<Integer> iterator = data[h].iterator();
        while (iterator.hasNext()) {
            Integer element = iterator.next();
            if (element == key) {
                data[h].remove(element);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        int h = hash(key);
        Iterator<Integer> iterator = data[h].iterator();
        while (iterator.hasNext()) {
            Integer element = iterator.next();
            if (element == key) {
                return true;
            }
        }
        return false;
    }

    private static int hash(int key) {
        return key % BASE;
    }


    public static void main(String[] args) {
        MyHashSet myHashSet = new MyHashSet();
        myHashSet.add(1);      // set = [1]
        System.out.println(myHashSet);
        myHashSet.add(2);      // set = [1, 2]
        System.out.println(myHashSet);
        System.out.println(myHashSet.contains(1)); // 返回 True

        System.out.println(myHashSet.contains(3)); //false
        myHashSet.add(2);      // set = [1, 2]
        System.out.println(myHashSet.contains(2));
        myHashSet.remove(2);   // set = [1]
        myHashSet.contains(2); // 返回 False ，（已移除）
        System.out.println(myHashSet);
    }
}
