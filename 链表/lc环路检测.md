### 题目

给定一个有环链表，实现一个算法返回环路的开头节点。
有环链表的定义：在链表中某个节点的next元素指向在它前面出现过的节点，则表明该链表存在环路。

<https://leetcode-cn.com/problems/linked-list-cycle-lcci/>

### 思路借鉴
<https://leetcode-cn.com/problems/linked-list-cycle-lcci/solution/lian-biao-kuai-man-zhi-zhen-sao-miao-zheng-ming-by/>

### 代码复现
~~~ c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)return 0;
        ListNode *fast=head,*slow=head;
        while(fast&&slow){
            fast=fast->next;
            slow=slow->next;
            if(fast)
                fast=fast->next;
            else
                return 0;
            if(fast==slow){
                fast=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return 0;
    }
};
~~~
