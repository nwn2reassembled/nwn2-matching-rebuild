class C {
public:
    unsigned short GetField0x368();
private:
    unsigned char m_pad[0x368];
    unsigned short m_word;
};

unsigned short __thiscall C::GetField0x368() {
    return this->m_word;
}
