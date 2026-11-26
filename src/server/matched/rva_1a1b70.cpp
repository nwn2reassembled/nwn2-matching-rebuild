class ServerObject {
public:
    unsigned int GetProperty(unsigned char id);

    unsigned char m_pad[0x94];
    unsigned int m_properties[0x29];
};

unsigned int ServerObject::GetProperty(unsigned char id) {
    if (id <= 0x28)
        return m_properties[id];
    return 0;
}
