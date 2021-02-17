package com.kklll.learn.algorithm.leetcode;


/**
 * @ClassName GetIntersectionNode
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/2/1 20:52
 * @Version 1.0
 **/
public class GetIntersectionNode {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode n1 = headA, n2 = headB;
        while(n1!=n2){
            n1=n1==null?headB:n1.next;
            n2=n2==null?headA:n2.next;
        }
        return n1;
    }
}




