public class question{
    
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    // i prefer this 
    public ListNode midNode(ListNode head) {
        if(head ==null && head.next ==null) return head;
        
        ListNode slow = head;
        ListNode fast = head;
        
        while(fast.next!=null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        return slow;
    }

    //leetcode 876
    public ListNode middleNode(ListNode head) {
        if(head ==null && head.next ==null) return head;
        
        ListNode slow = head;
        ListNode fast = head;
        
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        return slow;
    }

    // leetcode 206
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next ==null) return head;
        
        ListNode pre = null;
        ListNode curr = head;
        while(curr!=null){
            ListNode forw = curr.next;
            curr.next = pre;
            pre = curr;
            curr = forw;
        }
        return pre;
    }

    // leetcode 206 using recursion(Argue in this topic)
    public ListNode reverseList_rec(ListNode head) {
        if(head == null || head.next==null) return head;

        ListNode curr = head;
        ListNode temp = head.next;
        head.next = null;
        ListNode rl = reverseList_rec(temp);
        temp.next = curr;
        curr.next = null;
        return rl;
    }

    //leetcode 234
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;
        
        ListNode mid = midNode(head);
        ListNode nhead = mid.next;
        mid.next = null;
        nhead = reverseList(nhead);
        
        ListNode curr1 = head;
        ListNode curr2 = nhead;
        
        boolean res = true;
        
        while(curr1!=null && curr2!=null){
            if(curr1.val == curr2.val){
                curr1 = curr1.next;
                curr2 = curr2.next;
            }else{
                res = false;
                break;
            }
        }
        
        nhead = reverseList(nhead);
        mid.next = nhead;
        return res;
    }

    // leetcode 143
    public void reorderList(ListNode head) {
        if(head == null || head.next == null) return ;
        
        ListNode mid = midNode(head);
        ListNode nhead = mid.next;
        mid.next =null;
        nhead = reverseList(nhead);
        
        ListNode c1 = head;
        ListNode c2 = nhead;
        
        while(c1!=null && c2!=null){
            ListNode f1 = c1.next,f2 = c2.next;
            c1.next = c2;
            c2.next = f1;
            
            c1 = f1;
            c2 = f2;
        }
    }

    // reverse the data
    public void dataReverse(ListNode head)
    {
        if (head == null || head.next == null)
            return;

        ListNode mid = midNode(head);
        ListNode nhead = mid.next;
        mid.next = null;

        nhead = reverseList(nhead);

        ListNode curr1 = head;
        ListNode curr2 = nhead;

        while (curr1 != null && curr2 != null)
        {

            int temp = curr1.val;
            curr1.val = curr2.val;
            curr2.val = temp;

            curr1 = curr1.next;
            curr2 = curr2.next;
        }

        nhead = reverseList(nhead);
        mid.next = nhead;
    }

    // order the List
    // public void addLast(ListNode s,ListNode h1,ListNode t1){
    //     if(h1 == null){
    //         h1 = s;
    //         t1 = s;
    //     }else{
    //         t1.next = s;
    //         t1 = s;
    //     }
        
    // }

    // public void addFirst(ListNode s,ListNode h2,ListNode t2){
    //     if(h2 == null){
    //         h2 = s;
    //         t2 = s;
    //     }else{
    //         s.next = h2;
    //         h2 = s;
    //     }
    // }

    // public ListNode removeFirst(ListNode head){
    //     ListNode rn = head;
    //     head = head.next;
    //     rn.next = null;
    //     return rn;
    // }

    // public ListNode orderList(ListNode head) {
    //     if(head == null || head.next == null) return head;

    //     ListNode h1 = null , t1 = null , h2 = null , t2 = null;
    //     ListNode curr = head;
    //     int i=0;
    //     while(curr!=null){
    //         ListNode f = curr.next;
    //         if(i%2==0){
    //             ListNode rn = removeFirst(curr);
    //             addLast(rn, h1, t1);
    //         }else{
    //             ListNode rn = removeFirst(curr);
    //             addFirst(rn, h2, t2);
    //         }
    //         curr = f;
    //            i++
    //     }

    //     t1.next = h2;
    //     return h1;
    // }

    //leetcode 21
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null || l2==null){
            return l1==null?l2:l1;
        }
        ListNode c1 = l1 , c2 = l2;
        ListNode pre = new ListNode(-1);
        ListNode temp = pre;
        
        while(c1!=null && c2!=null){
            ListNode f1 = c1.next;
            ListNode f2 = c2.next;
            
            if(c2.val>c1.val){
                pre.next = c1;
                pre = c1;
                c1 = f1;
            }else{
                pre.next = c2;
                pre = c2;
                c2 = f2;
            }
        }
        
        if(c1!=null) pre.next = c1;
        else if(c2!=null) pre.next = c2;
        
        return temp.next;
    }



}