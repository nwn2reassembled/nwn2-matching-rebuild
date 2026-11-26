class ServerInfo {
public:
    unsigned int GetField3C() const;

private:
    unsigned char pad00[0x3C];
    unsigned int field3C;
};

unsigned int ServerInfo::GetField3C() const
{
    return this->field3C;
}
