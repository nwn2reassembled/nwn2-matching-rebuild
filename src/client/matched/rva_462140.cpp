struct Node {
    Node* left;
    Node* parent;
    Node* right;
    unsigned char pad[0x21];
    unsigned char isnil;
};

struct Tree {
    int reserved;
    Node* head;
    void rotate_left(Node* x);
};

void Tree::rotate_left(Node* x)
{
    Node* y = x->right;
    x->right = y->left;
    if (!y->left->isnil)
        y->left->parent = x;
    y->parent = x->parent;

    Node* h = this->head;
    if (x == h->parent) {
        h->parent = y;
        y->left = x;
        x->parent = y;
        return;
    }

    Node* p = x->parent;
    if (x == p->left) {
        p->left = y;
        y->left = x;
        x->parent = y;
        return;
    }

    p->right = y;
    y->left = x;
    x->parent = y;
    return;
}
