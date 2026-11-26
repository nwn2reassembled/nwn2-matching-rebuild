class CNWSSomething {
public:
    unsigned short __thiscall GetField(bool flag);

private:
    unsigned char pad0[0x164];
    unsigned int m_fieldA;
    unsigned char pad1[0x4];
    unsigned int m_fieldB;
};

unsigned short __thiscall CNWSSomething::GetField(bool flag) {
    if (flag) {
        return (unsigned short)m_fieldA;
    }
    return (unsigned short)(m_fieldA + m_fieldB);
}
