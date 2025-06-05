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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* newN = new ListNode(INT_MIN);
        ListNode* prev = newN;
        
        while(temp != nullptr){
            if(temp->val != prev->val){
                prev->next = temp;
                prev = prev->next;
            }
            temp = temp->next;
        }

        prev->next = nullptr;
        return newN->next;
        
    }
};