struct Inner
{
    unsigned char padding[0x8d];
    unsigned char value;
};

class Outer
{
public:
    unsigned char GetValue() const;

private:
    Inner* m_pInner;
};

unsigned char Outer::GetValue() const
{
    if (m_pInner != 0)
        return m_pInner->value;
    return 8;
}
