struct Legacy {
    unsigned int getField(const void* p) const;
};

unsigned int Legacy::getField(const void* p) const {
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(p)+0x23c);
}

