/**
 * Definition for singly-linked list.
 * struct Node {
 *     int val;
 *     Node *next;
 *     Node(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
 	public:
 		Node* removeCancelableNodes(Node* n) {
 			if (n == NULL)
 				return n;
 			else if (n->next == NULL) {
 				if (n->val != 0)
 					return n;
 				else
 					return NULL;
			 }
			 Node *start = n, *end = n->next;
			 int sum = start->val, prevSum = start;
			 while(start != NULL && end != NULL) {
			 	sum = sum + end->val;
			 	if (sum == 0) {
			 		start = end->next;
			 		end = start;
			 		sum = start->val;
			 		prevSum = sum;
				 } else if (sum == prevSum) {
				 	start->next = end->next;
				 }
				 end = end->next;
			 }
			 return start;
		 }
 };
