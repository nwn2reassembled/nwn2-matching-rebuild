struct Node {
    int* ptr;
    int getValue() const;
};

int Node::getValue() const { return *ptr; }
