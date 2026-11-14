struct MyStruct {
    unsigned getField(const void* p);
};

unsigned MyStruct::getField(const void* p) {
    return *reinterpret_cast<const unsigned*>(reinterpret_cast<const char*>(p) + 0x6c);
}
