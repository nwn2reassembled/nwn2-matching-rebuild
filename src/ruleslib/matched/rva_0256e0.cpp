struct Legacy {
    void setVal(void* ptr, unsigned int val);
};

void Legacy::setVal(void* ptr, unsigned int val) {
    *(unsigned int*)((char*)ptr + 0x108) = val;
}
