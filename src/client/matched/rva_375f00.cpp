class C {
public:
    void Set(unsigned char index, unsigned char value);
private:
    unsigned char m_pad[0x53b];
    unsigned char m_entries[4][0x10c];
};

void C::Set(unsigned char index, unsigned char value)
{
    if (index < 4)
        m_entries[index][0] = value;
}
