class ServerObj {
public:
    void* m_handle; // offset 0x0

    unsigned short __thiscall GetRuntimeWord();
};

unsigned short __thiscall ServerObj::GetRuntimeWord()
{
    void* handle = m_handle;
    if (handle != 0)
        return *(unsigned short*)((char*)handle + 0x7ac40);
    return 0;
}
