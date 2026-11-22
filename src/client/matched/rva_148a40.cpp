struct Legacy {
    unsigned int foo();
};

unsigned int Legacy::foo() {
    // Load a pointer stored at offset +4 from this object.
    void* ptr = *(void**)((char*)this + 4);
    // Return the 32‑bit value located at ptr + 0x100ec.
    return *reinterpret_cast<unsigned int*>((char*)ptr + 0x100ec);
}
