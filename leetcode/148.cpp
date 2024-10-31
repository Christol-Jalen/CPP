// 148.排序链表
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution { // 冒泡排序法（但是超时）
private:
    // 交换 cur 后的两个节点
    void switch_node(ListNode* cur){
        ListNode* first = cur->next;
        ListNode* second = cur->next->next;
        cur->next = second;
        first->next = second->next;
        second->next = first;
    }
public:
    ListNode* sortList(ListNode* head) {
        // 边界条件检查
        if(!head || !head->next) return head;
        
        // 计算链表长度
        ListNode* temp = head; // 使用临时指针来遍历链表
        int countNodes = 0;
        while(temp != nullptr){
            temp = temp->next;
            countNodes++;
        }
        
        // 使用虚拟头节点简化边界处理
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        // 冒泡排序
        for(int i = 0; i < countNodes - 1; i++){
            ListNode* cur = dummyHead; // 每次外层循环重置 cur
            for(int j = 0; j < countNodes - 1 - i; j++){
                if(cur->next->val > cur->next->next->val){
                    switch_node(cur);
                }
                cur = cur->next; // 移动到下一个位置
            }
        }
        
        // 获取排序后的头节点
        ListNode* sortedHead = dummyHead->next;
        delete dummyHead; // 释放虚拟头节点
        return sortedHead;
    }
};