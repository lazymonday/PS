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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == 0) return 0;
        
        int len = 0;
        ListNode* cur = head;
        ListNode* tail = nullptr;
        while(cur != nullptr) {
            tail = cur;
            cur = cur->next;
            len++;
        }
        
        k %= len;
        k = len - k;
        
        if(len == 1) return head;
        
        while(k--) {
            ListNode* tmp = head->next;
            tail->next = head;
            tail = tail->next;
            tail->next = nullptr;
            head = tmp;
        }
        
        return head;
    }
};