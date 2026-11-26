struct Node
{
    int m_nUnused;
    Node* m_pNext;
    int m_nKey;
};

struct NodeList
{
    Node* m_pFirst;
};

class CNodeOwner
{
public:
    int HasNodeKey(int nKey);

private:
    char m_reserved[0x300];
    NodeList* m_pNodes;
};

int CNodeOwner::HasNodeKey(int nKey)
{
    if (m_pNodes == 0)
        return 1;

    Node* p = m_pNodes->m_pFirst;
    while (p != 0)
    {
        if (p->m_nKey == nKey)
            return 1;
        p = p->m_pNext;
    }

    return 0;
}
