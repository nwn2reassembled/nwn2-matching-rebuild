class ServerObject
{
public:
    unsigned short GetStatusWord();

    ServerObject* m_pInner;
};

class InnerObject
{
public:
    unsigned char pad0[0x70];
    unsigned short statusWord;
};

unsigned short ServerObject::GetStatusWord()
{
    return ((InnerObject*)m_pInner)->statusWord;
}
