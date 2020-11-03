/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == 0) return 0;
        auto fast = head;
        auto slow = head;
        bool detected = false;
        while(fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                detected = true;
                break;
            }
        }
        
        if(!detected) return 0;
        
        auto post = head;
        while(post != slow) {
            post = post->next;
            slow = slow->next;
        }
        
        return post;
    }
};