class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* newN = new ListNode(0);
        ListNode* curr = newN;

        while (temp1 != nullptr && temp2 != nullptr) {
            int sum = temp1->val + temp2->val + carry;
            carry = sum / 10;
            ListNode* currNode = new ListNode(sum % 10);
            curr->next = currNode;
            curr = curr->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp1 != nullptr) {
            int sum = temp1->val + carry;
            carry = sum / 10;
            ListNode* currNode = new ListNode(sum % 10);
            curr->next = currNode;
            curr = curr->next;
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) {
            int sum = temp2->val + carry;
            carry = sum / 10;
            ListNode* currNode = new ListNode(sum % 10);
            curr->next = currNode;
            curr = curr->next;
            temp2 = temp2->next;
        }

        if (carry > 0) {
            ListNode* currNode = new ListNode(carry);
            curr->next = currNode;
        }

        return newN->next;
    }
};