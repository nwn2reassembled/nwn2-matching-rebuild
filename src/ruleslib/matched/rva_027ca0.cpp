class Legacy {
public:
    static unsigned int __stdcall GetField(void *arg);
};

unsigned int Legacy::GetField(void *arg) {
    return (*(unsigned int *)((char *)arg + 0x318)) & 0xedb500u;
}

