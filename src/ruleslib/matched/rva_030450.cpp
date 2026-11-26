class CFieldHolder
{
public:
    unsigned char m_reserved[0xb0];
    int m_value;

    int __stdcall SetValue(int value);
};

int __stdcall CFieldHolder::SetValue(int value)
{
    return m_value = value;
}
