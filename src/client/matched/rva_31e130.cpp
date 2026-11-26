class CApp {
    unsigned char pad[0x9b4];
    void* obj;
    unsigned char tail[0x20 - sizeof(void*)];

public:
    void* GetSomething();
};

void* CApp::GetSomething()
{
    void* p = *reinterpret_cast<void* const*>(reinterpret_cast<const char*>(this) + 0x9b4);
    if (p)
        return *reinterpret_cast<void* const*>(reinterpret_cast<const char*>(p) + 0x30);
    return 0;
}
