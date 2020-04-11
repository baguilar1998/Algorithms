#include <iostream>
using namespace std;

class BNode {
    private:
        int n, key;
        BNode *children;
        int* keys;     
        bool leaf;

    public:

        BNode() {
            leaf = false;
            n = 0;
        }

        BNode(int key) {
            this->key = key;
            leaf = false;
            n = 0;
        }

        BNode(int key,int n) {
            this->key = key;
            leaf = false;
            this->n = n;
            this->keys = new int[n];
            this->children = new BNode[n+1];
        }

        int get_main_key() {
            return key;
        }

        int get_key(int index) {
            return this->keys[index];
        } 

        int key_size() {
            return n;
        }

        int child_size() {
            return n+1;
        }

        int* get_keys() {
            return keys;
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

        void set_main_key(int key) {
            this->key = key;
        }

        void set_key(int i, int key) {
            this->keys[i] = key;
        }
        
        void set_n(int n) {
            this->n = n;
            int* new_keys = new int[this->n]
            int* new_children = new BNode[this->n+1];
            this->keys = new_keys;
            this->children = new_children;
        }

}
