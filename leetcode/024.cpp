#include <iostream>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;
            // update cur
            cur = cur->next->next;   
        }
        return dummyHead->next;
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

    // 开始两两交换
    ListNode* newHead = solution.swapPairs(head);

    // 打印交换后的链表
    cout << "Swiched list: ";
    for (cur = newHead; cur != NULL; cur = cur->next) {
        cout << cur->val << " ";
    }
    cout << endl;

    return 0;
}