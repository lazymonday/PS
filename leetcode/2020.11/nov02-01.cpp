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
    ListNode* insertionSortList(ListNode* head) {
        if(head == 0) return 0;
        
        ListNode dummy; // don't need to compare this value
        dummy.next = head;
        
        auto curr = head;
        while(curr) {
            auto nxt = curr->next;
            curr->next = 0;
            
            auto prev_node = &dummy;
            auto first = dummy.next;
           
            // find position
            while(first) {
                if(curr->val < first->val) break;
                prev_node = first;
                first = first->next;
            }
            
            auto tmp = prev_node->next;
            prev_node->next = curr;
            curr->next = tmp;
            curr = nxt;
        }
        
        return dummy.next;
    }
};