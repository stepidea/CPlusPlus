#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
合并K个有序链表（分治实现）：https://leetcode-cn.com/problems/merge-k-sorted-lists/
假设数组中有3个有序的链表：（下面数字代表对应链表的索引）
1、[划分链表]，将3个链表划分为（0、1）a链表组和（2）b链表组;
2、[由于a链表中有两个链表]，将a链表划分为（0）c链表和（1）d链表;
3、[链表合并是一个链表与另一个链表进行合并，故需要将上面的链表组拆分为单个]，即可将单个链表作为递归的终止条件，方便后面合并操作;
4、[c链表和d链表都是只有一个链表]，直接调用合并两个有序链表的方法将c和d变成一个链表a;
5、[a链表和b链表都是只有一个链表]，再直接调用合并两个有序链表的方法将a和b变成一个链表返回。
*/

class Solution {
public:
    // ListNode* mergeKLists(vector<ListNode*>& lists) {        
    //     auto it = lists.begin();
    //     if(it == lists.end()){            
    //         return nullptr;
    //     }
    //     ListNode * head = *it;
    //     while((++it) != lists.end()){            
    //         head = mergeTwoLists(head, *it);
    //     }
    //     return head;
    // }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.begin() == lists.end()){            
            return nullptr;
        }      
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];
        // if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res_List = new ListNode(-1);
        ListNode* con_List = res_List;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                con_List->next = l1;
                l1 = l1->next;
            }else{
                con_List->next = l2;
                l2 = l2->next;
            }
            con_List = con_List->next;
        } 
        con_List->next = l1 != nullptr ? l1 : l2;
        return res_List->next;
    }
};