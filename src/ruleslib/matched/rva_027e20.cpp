class Legacy {
public:
    int getByteAtOffset(void* p) const;
};

int Legacy::getByteAtOffset(void* p) const {
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(p) + 0x335);
}

