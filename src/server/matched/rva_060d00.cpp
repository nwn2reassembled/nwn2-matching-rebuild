struct Node
{
    Node* left;
    Node* parent;
    Node* right;
    unsigned char color;
    unsigned char padding[8];
    bool isNil;
};

Node* Max(Node* node)
{
    while (!node->right->isNil)
        node = node->right;

    return node;
}
