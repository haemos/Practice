### 题目
给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
就是相交时候不是只有一个结点相交，而是后面全部都相同。

### 思路
用较长得减去两个链表之间的差，在逐步遍历得到相交点。

### 代码
~~~ c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0,lenB=0;
        ListNode* p=headA,*q=headB;
        while(p)p=p->next,lenA++;
        while(q)q=q->next,lenB++;
        p=headA,q=headB;
        if(lenA>=lenB){
            int diff = lenA-lenB;
            while(diff--)p=p->next;
        }
        else{
            int diff = lenB-lenA;
            while(diff--)q=q->next;
        }
        while(p&&q){
                if(p==q)return p;
                p=p->next;
                q=q->next;
        }
        return NULL;
    }
};
~~~
