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
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) tail->next = list1;
        if (list2) tail->next = list2;

        return dummy.next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = findMid(head);           
        ListNode* rightHead = mid->next;         
        mid->next = nullptr;                     

        ListNode* left = mergeSort(head);        
        ListNode* right = mergeSort(rightHead);  

        return merge(left, right);               
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
