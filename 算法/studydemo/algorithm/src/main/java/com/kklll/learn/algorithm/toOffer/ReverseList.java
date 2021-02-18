package com.kklll.learn.algorithm.toOffer;

import com.kklll.learn.algorithm.leetcode.ListNode;

/**
 * @ClassName ReverseList
 * @Deacription 剑指 Offer 24. 反转链表 https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
 * @Author DeepBlue
 * @Date 2021/2/17 20:23
 * @Version 1.0
 **/
public class ReverseList {
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode curr = head;
        ListNode next = null;
        while (curr != null) {
            next=curr.next;
            curr.next = pre;
            pre=curr;
            curr=next;
        }
        return pre;
    }
}
