package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName ReverseBetween
 * @Deacription 反转链表 II  https://leetcode-cn.com/problems/reverse-linked-list-ii/
 * @Author DeepBlue
 * @Date 2021/3/18 10:52
 * @Version 1.0
 **/
public class ReverseBetween {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy;
        //先找到要进行反转的链表的前一个Node
        for (int i = 0; i < left - 1; i++) {
            pre = pre.next;
        }
        ListNode after = pre;
        for (int i = 0; i < right - left + 1; i++) {
            after = after.next;
        }
        //切断出一个子链表
        ListNode begin = pre.next;
        ListNode end = after.next;
        //切断
        pre.next = null;
        after.next = null;
        reverseLinked(begin);
        pre.next = after;
        begin.next = end;
        return dummy.next;
    }

    public void reverseLinked(ListNode head) {
        ListNode pre = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
        }
    }
}
