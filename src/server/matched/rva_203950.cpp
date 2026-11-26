struct CItemQueue
{
    char reserved0[0xa90];
    int* items;
    int reserved1;
    int limit;
    char reserved2[0x18c];
    int index;

    int Next(int* value);
};

int CItemQueue::Next(int* value)
{
    ++index;
    if (index < limit)
    {
        *value = items[index];
        return 1;
    }
    return 0;
}
