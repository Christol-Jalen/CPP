#ifndef HEAD_H
#define HEAD_H

// 标准模板库（STL）:
#include <vector> //向量，动态数组。
#include <map> //映射，通常实现为红黑树。
#include <set> //集合，内部通常也是红黑树。
#include <unordered_map> //哈希表实现的映射。
#include <unordered_set> //哈希表实现的集合。
#include <queue> //队列，包括标准队列和优先队列。
#include <stack> //栈。
#include <algorithm> //包含各种算法，如排序、查找、变换等。
#include <string> //字符串类。
#include <list> //双向链表。
// 输入输出库:
#include <iostream> //包括输入输出流（如cin，cout，cerr）。
#include <fstream> //文件输入输出。
#include <sstream> //字符串流。
// 其他实用库:
#include <utility> //提供pair、make_pair等实用工具。
#include <tuple> //元组，可以存储不同类型的数据。
#include <memory> //智能指针如shared_ptr、unique_ptr。
#include <functional> //函数对象，包括function和bind。
#include <iterator> //迭代器。
#include <cmath> //数学函数。
// 并发编程相关:
#include <thread> //线程。
#include <mutex> //互斥量。
#include <condition_variable> //条件变量。
#include <atomic> //原子操作。

using namespace std;

// ListNode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
};

#endif