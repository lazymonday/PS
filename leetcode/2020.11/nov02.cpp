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
    ListNode* findPos(ListNode* head, ListNode* node) {
        while(head and head->next) {
            if(node->val < head->next->val) return head;
            head = head->next;
        }
        
        return head;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        if(head == 0) return 0;
        
        auto dummy = new ListNode(-INT_MAX);
        dummy->next = head;
        
        auto prev = head;
        auto curr = prev->next;
        prev->next = 0;
        while(curr) {
            auto tmp = curr->next;
            auto pos = findPos(dummy, curr);
            auto cur_next = pos->next;
            pos->next = curr;
            curr->next = cur_next;
            
            prev = curr;
            curr = tmp;
        }
        
        return dummy->next;
    }
};