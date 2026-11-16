class Legacy {
public:
    int compare(const void* obj, unsigned short value) const;
};

int Legacy::compare(const void* obj, unsigned short value) const {
    const unsigned char* ptr = static_cast<const unsigned char*>(obj);
    unsigned char byte = ptr[0x15c];
    return (value < byte) ? 1 : 0;
}

