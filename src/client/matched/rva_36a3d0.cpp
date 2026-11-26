class CValueHolder
{
public:
    unsigned char GetValue(unsigned char index);
private:
    unsigned char m_padding[0x16b8];
    unsigned char m_values[3];
};

unsigned char CValueHolder::GetValue(unsigned char index)
{
    if (index < 3)
        return m_values[index];
    return 0;
}
