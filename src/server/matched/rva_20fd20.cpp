class ServerState {
public:
    unsigned long GetFlags() const;
private:
    unsigned char m_pad[0xe68];
    unsigned long m_flags;
};

unsigned long ServerState::GetFlags() const {
    return m_flags;
}
