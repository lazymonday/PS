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
    ListNode* findMid(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* mid = &dummy;
        while(fast and fast->next) {
            fast = fast->next->next;
            mid = mid->next;
        }
        auto ret = mid->next;
        mid->next = 0;
        return ret;
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy;
        auto node = &dummy;
        while(left and right) {
            if(left->val < right->val) {
                node->next = left;
                left = left->next;
            } else {
                node->next = right;
                right = right->next;
            }
            node = node->next;
        }
        
        if(left) node->next = left;
        else node->next = right;
        
        auto ret = dummy.next;
        return ret;
    }
    
    ListNode* mergeSort(ListNode* head) {
        if(head == 0 or head->next == 0) return head;
        
        auto mid = findMid(head);
        auto left = mergeSort(head);
        auto right = mergeSort(mid);
        return merge(left, right);
    }
    
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};