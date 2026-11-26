class ServerApp {
    unsigned char pad[0x500];
    unsigned int m_status;
public:
    unsigned int GetStatus();
};

unsigned int ServerApp::GetStatus() {
    return m_status;
}
