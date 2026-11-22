struct Outer {
    int placeholder;   // occupies offset 0x0 – ensures ptr is at offset 4
    void* ptr;         // member accessed as [ecx+0x4]
    int getValue() const;
};

int Outer::getValue() const {
    // load the pointer stored in 'ptr', then read an int at offset 0x314 from that object
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(ptr) + 0x314 );
}

