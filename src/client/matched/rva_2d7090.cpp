class CActor {
public:
    int GetResourceOrZero();

    int m_block0[43];   // +0x000 .. +0xA8 filler
    int m_resource;     // +0xAC
    int m_pad;          // +0xB0
    int m_count;        // +0xB4
};

int CActor::GetResourceOrZero()
{
    if (m_count > 0)
        return m_resource;
    return 0;
}
