struct Object
{
    char m_reserved[0x4b8];
    unsigned short m_value;

    void SetValue(unsigned short value);
};

void Object::SetValue(unsigned short value)
{
    m_value = value;
}
