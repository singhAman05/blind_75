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
  In thos question I have not used the extra space for creating the array and then finding the random number
  I am just traversing for the linked list and then calculte the random number
*/
class Solution {
public:
    int si = 0;
    ListNode* node;
    Solution(ListNode* head) {
        ListNode* cur = head;
        node = head;
        while(cur!=NULL) {cur = cur->next;si++;}
    }
    
    int getRandom() {
        int l = rand()%si;
        ListNode *cur = node;
        while(l--){
            cur = cur->next;
        }
        return cur->val;
    }
};
