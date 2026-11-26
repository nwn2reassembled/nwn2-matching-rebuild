class CObject {
public:
    char m_pad[0x80];       // +0x00 .. +0x7F
    int m_related;          // +0x80
    void* m_other;          // +0x84

    int __stdcall GetRelated();
};

int __stdcall CObject::GetRelated()
{
    if (m_other != 0)
        return 0;
    return m_related;
}
