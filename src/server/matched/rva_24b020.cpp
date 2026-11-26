struct Legacy {
    void set(int);
};

void Legacy::set(int value) {
    *(reinterpret_cast<int*>(reinterpret_cast<char*>(this)+0x500)) = value;
}

