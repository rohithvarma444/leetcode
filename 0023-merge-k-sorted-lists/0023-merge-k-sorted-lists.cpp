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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;

        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;

        for(auto it: lists){
            ListNode* curr = it;
            while(curr != nullptr){
                pq.push({curr->val,curr});
                curr = curr->next;
            }
        }

        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while(!pq.empty() && temp != nullptr){
            temp->next = pq.top().second;
            temp = temp->next;
            pq.pop();
        }

        return head->next;
    }
};