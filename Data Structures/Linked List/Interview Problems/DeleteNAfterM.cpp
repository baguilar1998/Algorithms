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
 		void deleteNAfterM(Node *n, int M, int N) {
 			if (n == null)
 				return;
 			int mCounter = 0;
 			Node *mNode = n;
 			while (mNode != NULL) {
 				mCounter = mCounter + 1;
 				if (mCounter == M) {
 					int nCounter = 0;
 					Node *nNode = mNode->next;
 					while (nNode != NULL && nCounter != N) {
 						nCounter = nCounter + 1l
 						nNode = nNode->next;
					 }
					 mNode->next = nNode;
					 mCounter = 0;
				 }
				 mNode = mNode->next;
			 }
		 }
 };
