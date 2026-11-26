struct Payload {
    unsigned int words[16];
};

class Container {
public:
    void Assign(const Payload* src);
private:
    unsigned char m_reserved0[0x21];
    unsigned char m_locked;
    unsigned char m_reserved1[0x560 - 0x22];
    Payload m_payload;
};

void Container::Assign(const Payload* src) {
    if (m_locked == 0) {
        m_payload = *src;
    }
}
