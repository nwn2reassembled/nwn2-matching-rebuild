class Legacy {
public:
    int dummy;
    void *ptr; // stored at offset 4
    unsigned int GetValue() const;
};

unsigned int Legacy::GetValue() const {
    return *reinterpret_cast<const unsigned int*>(
        reinterpret_cast<const char*>(ptr) + 0x5c);
}

