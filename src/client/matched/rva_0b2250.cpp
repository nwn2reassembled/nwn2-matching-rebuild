struct SNode
{
    unsigned int field0;
    unsigned int field4;
    SNode* next;

    bool Contains(const SNode* target);
};

bool SNode::Contains(const SNode* target)
{
    for (const SNode* node = this; node != 0; node = node->next)
    {
        if (node == target)
            return true;
    }
    return false;
}
