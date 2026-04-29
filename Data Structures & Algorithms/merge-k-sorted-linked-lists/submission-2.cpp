/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
   ListNode* merge2Lists(ListNode* list1,ListNode* list2){
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val >= list2->val){
            list2->next = merge2Lists(list1 , list2->next);
            return list2;
        }
       else{
            list1->next = merge2Lists(list2 , list1->next);
            return list1;
        }
    }
    ListNode* solve(vector<ListNode*>& lists, int start, int end){
        if(start>end) return NULL;
        if(start == end) return lists[start];
        int mid = start + (end-start)/2;
        ListNode* left = solve(lists, start, mid);
        ListNode* right = solve(lists, mid+1, end);
        return merge2Lists(left , right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return solve(lists,0,lists.size()-1);
    }
};
