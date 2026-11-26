struct LinkNode
{
    char reserved[0xa4];
    LinkNode* next;
};

class LinkTable
{
public:
    void ClearNodes();

private:
    char m_prefix[0x1d8];
    LinkNode* m_links[39];
};

void LinkTable::ClearNodes()
{
    LinkNode** p = &m_links[1];
    int count = 13;

    do
    {
        if (p[-1] != 0)
            p[-1]->next = 0;
        if (p[0] != 0)
            p[0]->next = 0;
        if (p[1] != 0)
            p[1]->next = 0;

        p += 3;
    }
    while (--count != 0);
}
