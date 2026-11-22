struct Legacy {
    static void __stdcall setField(void* ptr, unsigned int value);
};

void Legacy::setField(void* ptr, unsigned int value) {
    *((unsigned int*)((unsigned char*)ptr + 0x98)) = value;
}

