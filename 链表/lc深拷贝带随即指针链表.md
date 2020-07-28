### 题目
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。 

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。

##### 深拷贝解释：从本体复制一个一模一样的拷贝体，但是这两个互不干扰，如改动了拷贝体但是不影响本体。对于链表则是，拷贝体和本体中值相同，但是他们不是公用一块
内存，也就是说改变了本体不改变拷贝体

### 思路
要拷贝1->2->3,则首先变成1->1'->2->2'->3->3' 在给他随机赋值，最后再进行分离得到。

### 代码
~~~ c++
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node *node = head;
        //1. 将复制节点添加到原节点后面
        while (node != nullptr) {
            Node *copy = new Node(node->val, nullptr, nullptr);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }
        
        //2. 复制random节点
        node = head;
        while (node != nullptr) {
            if (node->random != nullptr) {
                node->next->random = node->random->next;
            }            
            node = node->next->next;
        }
        
        //3. 分离链表
        node = head;
        Node *newHead = head->next;
        Node *newNode = newHead;
        while (node != nullptr) {
            node->next = node->next->next;     
            if (newNode->next != nullptr) {
                newNode->next = newNode->next->next;            
            }            
            node = node->next;
            newNode = newNode->next;
        }
        return newHead;
    }
};
