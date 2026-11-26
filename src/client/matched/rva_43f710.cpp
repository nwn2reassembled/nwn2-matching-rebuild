struct Legacy {
    void* ptr;
    unsigned short func() const;
};

unsigned short Legacy::func() const {
    return *(unsigned short*)((char*)ptr + 0xb4);
}
