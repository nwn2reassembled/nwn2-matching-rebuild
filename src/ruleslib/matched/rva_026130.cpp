struct Legacy {
    int unused_member;
    int readOffset(void* p);
};

int Legacy::readOffset(void* p) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x158);
}
