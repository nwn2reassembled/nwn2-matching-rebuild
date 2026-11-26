class ServerInfo {
public:
    unsigned long GetField37C();

private:
    unsigned char pad_0[0x37C];
    unsigned long field_37C;
};

unsigned long ServerInfo::GetField37C()
{
    return field_37C;
}
