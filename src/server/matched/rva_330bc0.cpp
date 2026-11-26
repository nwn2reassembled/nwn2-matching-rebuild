class ServerState
{
public:
    int __thiscall ClearPending();

private:
    unsigned char pad0[0x38];
    unsigned int field38;
    unsigned int field3C;
    unsigned int field40;
};

int ServerState::ClearPending()
{
    field38 = 0;
    field3C = 0;
    field40 = 0;
    return 1;
}
