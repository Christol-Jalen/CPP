// 206.翻转链表
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
    public:
    ListNode* reverseList(ListNode* head){
        ListNode* temp;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            temp = cur->next;
            cur->next = pre;
            //更新cur与pre指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1, 3, 5, 7, 9};
    ListNode* dummyHead = new ListNode(-1);
    ListNode* cur = dummyHead;

    for(int i=0; i<nums.size(); i++){
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    ListNode* head = dummyHead->next;
    delete dummyHead;
    // 打印出原始链表
    cout << "The original list node is: " << endl;
    for(ListNode* cur = head; cur != nullptr; cur = cur->next){
        cout << cur->val << " ";
    }
    cout << endl;

    // 反转链表
    head = solution.reverseList(head); // 重要：更新head节点
    cout << "The new list node is: " << endl;
    for(ListNode* cur = head; cur != nullptr; cur = cur->next){
        cout << cur->val << " ";
    }
    cout << endl;
}