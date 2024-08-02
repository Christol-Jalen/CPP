//203. 移除链表元素
#include "head.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != NULL){
            if(cur->next->val == val){
                // 新建一个临时指针保存即将被删除的节点
                ListNode* tmp = cur->next; 
                // 当前节点被跳过，但是这块内存被tmp指定着
                cur->next = cur->next->next;
                // 删除当前节点的内存
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main() {
    Solution solution;
    
    // 给定的数组
    int values[] = {1, 2, 6, 3, 4, 5, 6};
    int n = sizeof(values) / sizeof(values[0]); // 计算数组长度

    // 创建链表的头结点
    ListNode* dummyhead = new ListNode(0); // 使用临时的虚拟头结点
    ListNode* cur = dummyhead;

    // 构造链表
    for (int i = 0; i < n; ++i) {
        cur->next = new ListNode(values[i]);
        cur = cur->next;
    }
    ListNode* head = dummyhead->next; // 实际的头结点是虚拟头结点的下一个节点
    delete dummyhead; // 删除虚拟头结点

    // 打印原始链表
    cout << "Original list: ";
    for (cur = head; cur != NULL; cur = cur->next) {
        cout << cur->val << " ";
    }
    cout << endl;

    // 删除元素
    ListNode* result = solution.removeElements(head, 6);

    // 打印新链表
    cout << "Modified list: ";
    for (cur = result; cur != NULL; cur = cur->next) {
        cout << cur->val << " ";
    }
    cout << endl;

    // 释放链表内存
    while (result != NULL) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}

