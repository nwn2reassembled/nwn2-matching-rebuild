struct Node
{
    Node* left;
    Node* parent;
    Node* right;
    char gap[9];
    unsigned char isnil;
};

struct Tree
{
    char gap[4];
    Node* head;
    void Lrotate(Node* where);
};

void Tree::Lrotate(Node* where)
{
    Node* pnode = where->right;
    where->right = pnode->left;
    if (!pnode->left->isnil)
        pnode->left->parent = where;
    pnode->parent = where->parent;
    if (where == head->parent)
        head->parent = pnode;
    else if (where == where->parent->left)
        where->parent->left = pnode;
    else
        where->parent->right = pnode;
    pnode->left = where;
    where->parent = pnode;
}
