class ServerApp {
public:
    unsigned int GetField4BC();
private:
    unsigned char m_pad[0x4BC];
    unsigned int m_field4BC;
};

unsigned int ServerApp::GetField4BC() {
    return m_field4BC;
}
