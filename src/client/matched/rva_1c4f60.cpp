typedef int BOOL;

class Agent
{
public:
    BOOL IsSpecialMode() const;
    unsigned short field_5c;
};

BOOL Agent::IsSpecialMode() const
{
    unsigned short mode = *(unsigned short*)((char*)this + 0x5c);
    return (mode == 6) || (mode == 0x187);
}
