#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x,ListNode* next):val(x),next(next){};
};

/*
�ϲ�������������https://leetcode-cn.com/problems/merge-two-sorted-lists/
��Ҫ����������ʱָ��ָ��ͬһ����һ�����ڷ��ؽ��res��һ��������������con
�Ƚ������������������ָ���е�ֵ����С�ĸ�ֵ��һ��con��ʱָ�룬
ֱ������һ������������ָ��Ϊ�գ�ֱ������ѭ����
����Ϊ�յ�����ָ��ֱ�Ӹ��ӵ�con��ʱָ��next,����һ����������
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