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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* curr = head;
        int count = 0;
        while(curr){
            count++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;
        curr = head;
        while(count >= k){
        ListNode* groupHead = curr;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        for(int i = 1; i <= k; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
         prevGroupTail->next = prev;

         groupHead->next = curr;

         prevGroupTail = groupHead;

         count -= k;
        }
        return dummy.next;
    }
};
