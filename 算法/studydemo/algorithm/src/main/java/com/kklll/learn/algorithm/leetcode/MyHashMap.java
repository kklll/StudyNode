package com.kklll.learn.algorithm.leetcode;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;

/**
 * @ClassName MyHashMap
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/3/14 19:40
 * @Version 1.0
 **/
class MyHashMap {
    private final int cap = 800;
    private LinkedList[] data;

    private class Node {
        private int key;
        private int val;

        public Node(int key, int val) {
            this.key = key;
            this.val = val;
        }
    }

    /**
     * Initialize your data structure here.
     */
    public MyHashMap() {
        data = new LinkedList[cap];
        for (int i = 0; i < cap; i++) {
            data[i] = new LinkedList<Node>();
        }
    }

    /**
     * value will always be non-negative.
     */
    public void put(int key, int value) {
        int index = key % cap;
        LinkedList<Node> datum = data[index];
        for (Node next : datum) {
            if (next.key == key) {
                next.val = value;
                return;
            }
        }
       datum.add(new Node(key, value));
    }

    /**
     * Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
     */
    public int get(int key) {
        int index = key % cap;
        LinkedList<Node> datum = data[index];
        for (Node next : datum) {
            if (next.key == key) {
                return next.val;
            }
        }
        return -1;
    }

    /**
     * Removes the mapping of the specified value key if this map contains a mapping for the key
     */
    public void remove(int key) {
        int index = key % cap;
        Iterator<Node> iterator = data[index].iterator();
        while (iterator.hasNext()) {
            Node pair = iterator.next();
            if (pair.key == key) {
                data[index].remove(pair);
                return;
            }
        }

    }
}
