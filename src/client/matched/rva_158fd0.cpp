class CMaxValue
{
public:
    void Update(int value);
private:
    unsigned char m_padding[0x4c];
    int m_current;
    int m_changed;
};

void CMaxValue::Update(int value)
{
    if (m_current < value)
    {
        m_current = value;
        m_changed = 1;
    }
}
