class KeyMapper {
    unsigned char m_pad[136];
    unsigned char m_table[10];
public:
    unsigned char GetAction(unsigned char key);
};

unsigned char KeyMapper::GetAction(unsigned char key)
{
    if (key >= 10)
        return 0;
    return m_table[key];
}
