struct Legacy {
    void reset();
};

void Legacy::reset() {
    reinterpret_cast<volatile unsigned int*>(reinterpret_cast<char*>(this)+0x410)[0] = 0;
    reinterpret_cast<volatile unsigned int*>(reinterpret_cast<char*>(this)+0x40C)[0] = 0;
}

