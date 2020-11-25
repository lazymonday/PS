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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> left;
        while(l1) {
            left.push(l1);
            l1 = l1->next;
        }
        
        stack<ListNode*> right;
        while(l2) {
            right.push(l2);
            l2 = l2->next;
        }
        
        stack<ListNode*>& larger = left.size() > right.size() ? left : right;
        stack<ListNode*>& smaller = left.size() <= right.size() ? left : right;
        
        int carry = 0;
        ListNode* ret = 0;
        while(!smaller.empty()) {
            ret = larger.top();
            auto stop = smaller.top();
            
            ret->val = (ret->val + stop->val + carry);
            carry = ret->val/10;
            ret->val %= 10;
            
            larger.pop();
            smaller.pop();
        }
        
        while(!larger.empty()) {
            ret = larger.top();
            ret->val += carry;
            carry = ret->val / 10;
            ret->val %= 10;
            larger.pop();
        }
        
        if(carry) {
            ret = new ListNode(carry, ret);
        }
    
        return ret;
    }
};