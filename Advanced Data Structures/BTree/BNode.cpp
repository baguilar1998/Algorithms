#include <iostream>
using namespace std;

class BNode {
    private:
        int n, key;
        BNode *children;        
        bool leaf;

    public:
        BNode(int key) {
            this->key = key;
            leaf = false;
            n = 0;
        }

        BNode(int key,int n) {
            this->key = key;
            leaf = false;
            this->n = n;
            keys = new BNode[n];
        }

        int get_key() {
            return key;
        }

        int key_size() {
            return n;
        }

        BNode* get_children() {
            return children;
        }

        bool is_leaf() {
            return leaf;
        }

        void set_leaf(bool leaf) {
            this->leaf = l;
        }

        void set_key(int key) {
            this->key = key;
        }
        
        void set_n(int n) {
            this->n = n;
            int* new_children = new BNode[this->n];
            this->children = new_children;
        }

}
