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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            ListNode* future = curr->next;
            curr->next = prev;
            prev = curr;
            curr = future;
        }

        return prev;
    }

    ListNode* findKthNode(ListNode* head, int k){
        ListNode* temp = head;
        k -= 1;

        while(temp != nullptr && k > 0){
            temp = temp->next;
            k--;
        }

        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while(temp != nullptr){
            ListNode* kthNode = findKthNode(temp,k);

            if(kthNode == nullptr){
                if(prevLast != nullptr) prevLast->next = temp;
                break;
            }

            ListNode* nextEl = kthNode->next;
            kthNode->next = nullptr;

            ListNode* newHead = reverse(temp);
            if(temp == head) head = newHead;
            else prevLast->next = newHead;
            prevLast = temp;
            temp = nextEl;
        }

        return head;
    }
};