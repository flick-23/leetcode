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
        ListNode* ans = new ListNode(0); // Dummy node to start the result list
        ListNode* curr = ans; // Pointer to iterate over the result list
        int carry = 0;        // To store the carry-over during addition

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int sum = carry; // Start with carry from previous step

            // Add the value from l1 if available
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add the value from l2 if available
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10; // Update carry
            sum = sum % 10;   // The current digit for the new node

            // Create a new node with the sum's last digit
            curr->next = new ListNode(sum);
            curr = curr->next; // Move to the next node
        }

        return ans->next; // Skip the dummy node and return the actual result
    }
};