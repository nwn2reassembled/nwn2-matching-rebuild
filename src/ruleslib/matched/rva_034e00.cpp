struct Legacy {
    unsigned char foo(unsigned int first, unsigned int second);
};

unsigned char Legacy::foo(unsigned int first, unsigned int second) {
    // Only the low byte of 'second' is used as a base address.
    return *reinterpret_cast<unsigned char*>( (second & 0xFFu) + first + 10 );
}
