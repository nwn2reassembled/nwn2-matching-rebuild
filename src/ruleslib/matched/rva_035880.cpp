struct MyStruct {
    unsigned char func(const void*);
};

unsigned char MyStruct::func(const void* ptr) {
    // Return the byte at offset 0x17a of the object pointed to by ptr.
    return *reinterpret_cast<const unsigned char*>(static_cast<const char*>(ptr)+0x17a);
}

