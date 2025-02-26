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
        ListNode* head = new ListNode(0);
        ListNode* temp;
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = lists.size();
        for(int i = 0; i < n; i++){
            temp = lists[i];
            while(temp != NULL){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        temp = head;
        while(!pq.empty()){
            temp->next = new ListNode(pq.top());
            temp = temp->next;
            pq.pop();
        }
        return head->next;
    }
};