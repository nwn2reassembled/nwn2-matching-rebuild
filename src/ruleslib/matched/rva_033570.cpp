struct MyClass {
    unsigned char foo(void* ptr);
};

unsigned char MyClass::foo(void* ptr) {
    // Return the byte at offset 0x25 from the supplied pointer.
    return *reinterpret_cast<unsigned char*>(static_cast<char*>(ptr)+0x25);
}

