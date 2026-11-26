struct Node
{
    char m_reserved0[0x45c];
    bool m_bFlag;
    char m_reserved1[0x47c - 0x45d];
    Node* m_pNext;

    bool GetLastFlag();
};

bool Node::GetLastFlag()
{
    Node* p = this;
    while (p->m_pNext)
        p = p->m_pNext;
    return p->m_bFlag;
}
