class Legacy {
public:
    int placeholder; // arbitrary member required by the task
    void writeByte(void* addr, unsigned char value);
};

void Legacy::writeByte(void* addr, unsigned char value) {
    *reinterpret_cast<unsigned char*>(static_cast<char*>(addr)+0x5BE) = value;
}

