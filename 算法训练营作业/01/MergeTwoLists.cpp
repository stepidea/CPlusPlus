#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x,ListNode* next):val(x),next(next){};
};

/*
合并两个有序链表：https://leetcode-cn.com/problems/merge-two-sorted-lists/
需要创建两个临时指针指向同一处，一个用于返回结果res，一个用于连接数据con
比较两个传入的有序链表指针中的值，将小的赋值个一个con临时指针，
直到其中一个或两个有序指针为空，直接跳出循环，
将不为空的有序指针直接附加到con临时指针next,构成一个完整链表
*/

class Solution
{
private:
    /* data */
public:
    ListNode * MergeTwoLists(ListNode *l1,ListNode *l2);
};

ListNode * Solution::MergeTwoLists(ListNode *l1,ListNode *l2){
    ListNode *res_list = new ListNode(-1);
    ListNode *con_list = res_list;
    while (nullptr != l1 && nullptr != l2)
    {
        if(l1->val < l2->val)
        {
            con_list->next = l1;
            l1 = l1->next;
        }
        else{
            con_list->next = l2;
            l2 = l2->next;
        }
        con_list = con_list->next;
    }
    con_list->next = nullptr!=l1?l1:l2;
    return res_list->next;    
}