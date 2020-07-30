### 题目
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return nullptr;
        ListNode* node=head;
        ListNode* start=new ListNode(0,nullptr);
        start->next=head;
        ListNode* startnode=start;
        while(node->next!=nullptr){
            int flag=node->val;
            if(node->next->val==flag){
                while(node!=nullptr&&node->val==flag){
                    node=node->next;
                }
                if(node==nullptr||node->next==nullptr){
                    startnode->next=node;
                    return start->next;
                }
                    continue;
            }
            startnode->next=node;
            startnode=startnode->next;
            node=node->next; 
        }
        return start->next;
    }
};
~~~
