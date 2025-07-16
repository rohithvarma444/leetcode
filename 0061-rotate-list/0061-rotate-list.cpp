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
        
        if(head == nullptr) return nullptr;
        
        int n = 1;
        ListNode* temp = head;
        while(temp->next != nullptr){
            n++;
            temp = temp->next;
        }
        k = k % n;
        if(k == 0) return head;
        
        int pos = 1;
        temp = head;
        while(pos < n-k){
            temp = temp->next;
            pos++;
        }

        ListNode* newH = temp->next;
        ListNode* tail = newH;

        while(tail->next != nullptr && tail != nullptr) tail = tail->next;

        tail->next = head;
        temp->next = nullptr;

        return newH;
    }
};