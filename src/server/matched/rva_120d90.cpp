class TargetObject {
public:
    char              gap0[0x38];
    unsigned long     m_flags;
    char              gap3C[0x44];
    unsigned short    m_value80;

    void __fastcall ApplyEntry(unsigned unusedEdx, unsigned short* source, unsigned length);
};

void TargetObject::ApplyEntry(unsigned unusedEdx, unsigned short* source, unsigned length)
{
    if (length >= 2)
    {
        m_value80 = *source;
        m_flags |= 0x800;
    }
}
