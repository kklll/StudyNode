package com.kklll.learn.algorithm.leetcode;

import java.util.List;

/**
 * @ClassName IsPalindrome
 * @Deacription 234. 回文链表 https://leetcode-cn.com/problems/palindrome-linked-list/
 * @Author DeepBlue
 * @Date 2021/2/6 10:24
 * @Version 1.0
 **/
public class IsPalindrome {
    public boolean isPalindrome(ListNode head) {
        if (head==null){
            return true;
        }
        ListNode mid = findMidNode(head);
        System.out.println(mid.val);
        ListNode listNode = reverseLinked(mid.next);
        System.out.println(mid.val);
        while (head!=null&&listNode!=null) {
            if (head.val==listNode.val){
                listNode=listNode.next;
                head=head.next;
            }else{
                return false;
            }
        }
        return true;
    }

    public ListNode findMidNode(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

    public ListNode reverseLinked(ListNode head) {
        ListNode pre = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }

    public static void main(String[] args) {

    }
}
