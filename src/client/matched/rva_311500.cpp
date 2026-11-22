struct Legacy {
    void* getOffset();
};

void* Legacy::getOffset() {
    return reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x44c);
}
