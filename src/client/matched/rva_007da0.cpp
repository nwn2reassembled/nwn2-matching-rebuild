int CountListNodes(void* head)
{
    int count = 0;
    void* node = head;
    while (node != 0)
    {
        node = *(reinterpret_cast<void**>(reinterpret_cast<char*>(node) + 0x1c));
        ++count;
    }
    return count;
}
