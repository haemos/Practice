### 题目
给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。

删除完毕后，请你返回最终结果链表的头节点。

### 思路
通过递归逐步验证和为0结点，

### 代码
~~~ c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head)return nullptr;
        ListNode* Next=removeZeroSumSublists(head->next);   //吧下一个结点进行递归
        head->next=Next;

        ListNode* tmp=head;
        long long value=0;
        while(tmp!=nullptr){    //验证从这个结点开始到结束是否有为0的 有则返回下一个结点递归回去组成新链表
            value+=tmp->val;
            if(value==0){
                return tmp->next;
            }
            tmp=tmp->next;
        }
        return head;
    }
};
~~~
