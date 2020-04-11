#include <iostream>
#include "BNode.cpp"
using namespace std;

template <class T>
class BTree {
    private:
        BNode* root;
        int t, size;

    public:
        BTree(int degree) {
            this->t = degree;
            size = 0;
            BNode* x = new BNode();
            x->set_leaf(true);
            this->root = x;
        }

        int search(BNode* x, int key) {
            int i = 0;
            int* keys = x->get_keys();
            while(i <= x->key_size() && key > this->keys[i])
                i += 1;
            if (i <= x->key_size() && k == this->keys[i])
                return i;
            else if (x->is_leaf())
                return -1;
            BNode* children = x->get_children();
            for (int i = 0; i < x->child_size(); i++) {
                int index_location = search(this->children[i],key);
                if (index_location != -1)
                    return index_location;
            }
            return -1;
        }

        void split-child(BNode* x, int i) {
            BNode* z = new BNode();
            BNode* y = x->get_children()[i];
            z->set_leaf(y->is_leaf());
            z->set_n(t-1);
            for (int j = 0; j <= t-1; j++)
                z->set_key(y->get_key(j+t));
            y->set_n(t-1);
            // CONTINUE CODE
        }
}