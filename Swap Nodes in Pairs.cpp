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

/*
  In this question we will call the recusive function to swap the pairs of the node
*/


class Solution {
public:
    ListNode* solve(ListNode *node){
        if(node==NULL || node->next==NULL) return node;

        ListNode *temp = node->next;
        node->next = solve(node->next->next);
        temp->next = node;

        return temp;
    }
    ListNode* swapPairs(ListNode* head) {
        // if(head==NULL || head->next==NULL) return head;
        return solve(head);
    }
};
