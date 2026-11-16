
// Legacy member function matching the given assembly

class Legacy {
public:
    int getFlag(void* ptr);
};

int Legacy::getFlag(void* ptr) {
    const unsigned char value = *reinterpret_cast<const unsigned char*>(static_cast<char*>(ptr) + 0x6d0);
    return (value >> 2) & 1;
}

