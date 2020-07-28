### 题目
<https://leetcode-cn.com/problems/sum-lists-lcci/submissions/>

### 思路
算一位创建一位

~~~ c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         if (!l1 || !l2) {
            return l1 == nullptr ? l2 : l1;
        }
        int carry = 0;
        ListNode* ret = new ListNode(0);
        ListNode* p = ret;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
            p = p->next;
        }
        while (l1) {
            int sum = l1->val + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1->next;
            p = p->next;
        }
        while (l2) {
            int sum = l2->val + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;
            l2 = l2->next;
            p = p->next;
        }
        if (carry) {
            p->next = new ListNode(carry);
        }
        return ret->next;
    }
};
~~~
