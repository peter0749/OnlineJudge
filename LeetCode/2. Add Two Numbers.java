/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
 
 //AC or TLE
public class Solution {
    private ListNode[] append(ListNode l, int n) {
        ListNode res[] = new ListNode[2];
        l.val=n%10;
        l.next=new ListNode(n/10);
        res[0]=l;
        l=l.next; l.next=null;
        res[1]=l;
        return res;
    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res[]= new ListNode[2];
        ListNode r;
        res[1] = r = new ListNode(0); r.next=null;
        while(l1!=null&&l2!=null) {
            res = append(res[1], l1.val+l2.val+res[1].val);
            l1=l1.next; l2=l2.next;
        }
        while(l1!=null) {
            res = append(res[1], l1.val+res[1].val);
            l1=l1.next;
        }
        while(l2!=null) {
            res = append(res[1], l2.val+res[1].val);
            l2=l2.next;
        }
        while(res[1]!=null && res[1].val>=10) {
            res = append(res[1],res[1].val);
        }
        if(res[1].val==0) res[0].next=null;
        return r;
    }
}
