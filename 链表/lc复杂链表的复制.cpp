/*请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return nullptr;
        //复制
        Node* head_copy=head;
        while(head!=nullptr){
            Node* copy=new Node(head->val,nullptr,nullptr);
            copy->next=head->next;
            head->next=copy;
            head=copy->next;
        }

        //赋随机值。
        head=head_copy;
        while(head!=nullptr){
            if(head->random!=nullptr)
                head->next->random=head->random->next;
            head=head->next->next;
        }
        //分离
        head=head_copy;
        Node* newhead=head->next;
        Node* newnode=newhead;
        while(head!=nullptr){
            head->next=head->next->next;
            if(head->next!=nullptr){
                newnode->next=newnode->next->next;
            }
            head=head->next;
            newnode=newnode->next;
        }
        return newhead;
    }
};
