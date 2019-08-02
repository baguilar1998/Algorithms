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
    bool hasCycle(ListNode *head) {
        if (head == NULL) 
            return false;
        if(head->next == NULL)
            return false;
        ListNode *t1 = head, *t2 = head->next;
        while(t1 != NULL && t2 != NULL) {
            if(t1 == t2) return true;
            t1 = t1->next;
            t2 = t2->next;
            if(t2 != NULL) t2 = t2->next;
        }
        return false;
    }
};