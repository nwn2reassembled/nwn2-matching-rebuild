struct C {
    void* ptr;
    unsigned short foo() const;
};

unsigned short C::foo() const {
    return *reinterpret_cast<unsigned short const *>( reinterpret_cast<const char*>(ptr) + 0xB4 );
}
