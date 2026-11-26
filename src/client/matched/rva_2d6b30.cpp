struct Result {
    unsigned char reserved[0x44];
    void* value;
};

struct Node {
    Result* result;
    int count;
};

struct Outer {
    Node* node;
    void* Get();
};

void* Outer::Get()
{
    if (node->count <= 4)
        return 0;
    return node->result->value;
}
