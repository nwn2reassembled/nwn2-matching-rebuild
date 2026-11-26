class ServerApp {
public:
    void __stdcall ShutdownStage(int phase, int flags, int timeoutMs, int reserved);
};

void ServerApp::ShutdownStage(int phase, int flags, int timeoutMs, int reserved) {
    (void)phase; (void)flags; (void)timeoutMs; (void)reserved;
}
