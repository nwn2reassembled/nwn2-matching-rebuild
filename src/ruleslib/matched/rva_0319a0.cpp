struct MyStruct {
    unsigned char getByte(void* p) const;
};

unsigned char MyStruct::getByte(void* p) const {
    return *reinterpret_cast<unsigned char*>(static_cast<char*>(p)+0x62A);
}

