class ServerObject {
public:
    unsigned int GetField3B0() const;

    char m_pad[0x3b0];
    unsigned int field_3b0;
};

unsigned int ServerObject::GetField3B0() const
{
    return field_3b0;
}
