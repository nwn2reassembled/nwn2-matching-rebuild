struct NodeBlock {
    int data[20]; // 0x50-byte POD
};

NodeBlock* __cdecl CopyNodes(NodeBlock* first, NodeBlock* last, const NodeBlock* src)
{
    while (first != last) {
        *first = *src;
        ++first;
    }
    return first;
}
