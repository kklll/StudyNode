package com.kklll.learn.algorithm.leetcode;

/**
 * @ClassName DeleteDuplicates
 * @Deacription 83. 删除排序链表中的重复元素   https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 * @Author DeepBlue
 * @Date 2021/2/23 18:38
 * @Version 1.0
 **/
public class DeleteDuplicates {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode curr = head;
        while (curr!=null) {
            ListNode next = curr.next;
            while (next != null && next.val == curr.val) {
                next = next.next;
            }
            curr.next = next;
            curr = curr.next;
        }
        return head;
    }
}
