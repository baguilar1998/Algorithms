/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* node) {
        int size = 0;
        ListNode* temp = node;
        while (temp != NULL) {
            size += 1;
            temp = temp->next;
        }
        return size;
    }
    
    ListNode* middleNode(ListNode* head) {
        if (head == NULL)
            return NULL;
        int size = length(head);
        ListNode* temp = head;
        for (int i = 0; i < size/2; i++)
            temp = temp->next;
        return temp;
    }
};