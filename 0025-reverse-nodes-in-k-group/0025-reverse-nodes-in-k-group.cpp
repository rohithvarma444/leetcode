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
    ListNode* findKthNode(ListNode* temp, int k){
        if (k == 0) return temp;
        while (temp != nullptr && k > 1) {  
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* nextEl = nullptr;

        while (temp != nullptr){
            nextEl = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextEl;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        ListNode* temp = head;
        ListNode* newHead = nullptr;       
        ListNode* prevTail = nullptr;      

        while (temp != nullptr) {
            ListNode* KthNode = findKthNode(temp, k);

            if (KthNode == nullptr) {
                if (prevTail != nullptr) {
                    prevTail->next = temp; 
                }
                break;
            }

            ListNode* nextNode = KthNode->next;  

            KthNode->next = nullptr;             
            ListNode* revHead = reverse(temp);   

            if (newHead == nullptr) {
                newHead = revHead;               
            }

            if (prevTail != nullptr) {
                prevTail->next = revHead;       
            }

            prevTail = temp;                     
            temp = nextNode;                     
        }

        return newHead;
    }
};