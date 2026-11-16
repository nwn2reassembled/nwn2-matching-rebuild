struct Foo {
    void setByte(void *base, unsigned char idx, unsigned char value);
};

void Foo::setByte(void *base, unsigned char idx, unsigned char value) {
    reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(base) + idx + 0xD)[0] = value;
}

