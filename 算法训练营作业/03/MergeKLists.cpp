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
合并K个有序链表：https://leetcode-cn.com/problems/merge-k-sorted-lists/
分治实现
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
    ListNode* merge(vector <ListNode*> &lists, int l, int r) {
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