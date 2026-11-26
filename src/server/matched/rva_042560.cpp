struct Node
{
    Node* left;
    Node* parent;
    Node* right;
    int score;
    int kind;
    char tier;
    bool isnil;
};

class Container
{
public:
    int field0;
    Node* head;

    void Relink(Node* x);
};

void Container::Relink(Node* x)
{
    Node* a = x->right;
    Node* w = a->left;
    x->right = w;
    w = a->left;
    if (w->isnil == false)
        w->parent = x;
    Node* xp = x->parent;
    a->parent = xp;
    Node* root = head;
    if (x == root->parent)
    {
        root->parent = a;
        a->left = x;
        x->parent = a;
        return;
    }
    Node* p = x->parent;
    if (x == p->left)
    {
        p->left = a;
        a->left = x;
        x->parent = a;
        return;
    }
    p->right = a;
    a->left = x;
    x->parent = a;
}
