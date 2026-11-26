class ServerInfo {
public:
    unsigned int GetField40();

    char pad00[0x40];
    unsigned int field40;
};

unsigned int ServerInfo::GetField40()
{
    return field40;
}
