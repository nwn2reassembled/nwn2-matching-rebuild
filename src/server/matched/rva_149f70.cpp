struct Legacy {
    char pad[4];
    void* data;
    unsigned int getValue() const;
};

unsigned int Legacy::getValue() const {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(data)+0x100c8);
}

