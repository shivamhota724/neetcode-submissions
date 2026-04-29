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
    ListNode* merge2lists(ListNode* list1,ListNode* list2){
                if(list1 == NULL) return list2;
                if(list2 == NULL) return list1;
                if(list1->val > list2->val) {
                    list2->next = merge2lists(list1 , list2->next);
                    return list2;
                }
                if(list1->val < list2->val) {
                    list1->next = merge2lists(list1->next , list2);
                    return list1;
                }
            }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        ListNode* merged = lists[0];
        for(int i=1;i<n;i++){
            merged = merge2lists(merged,lists[i]);
        }
        return merged;
    }
};
