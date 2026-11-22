struct Legacy {
    void* getFieldAddress();
};

void* Legacy::getFieldAddress() {
    return reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x1e0);
}

