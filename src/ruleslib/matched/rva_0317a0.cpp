struct Legacy {
    static void __stdcall set_word_at_offset(void* ptr, unsigned short val);
};

void Legacy::set_word_at_offset(void* ptr, unsigned short val) {
    *(unsigned short*)((char*)ptr + 0x618) = val;
}
