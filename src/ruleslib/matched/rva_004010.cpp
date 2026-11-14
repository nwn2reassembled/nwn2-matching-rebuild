class Legacy {
public:
    int check() const;
};

int Legacy::check() const {
    // Access the field at offset 0x8c
    const unsigned char* base = reinterpret_cast<const unsigned char*>(this);
    int value = *reinterpret_cast<const int*>(base + 0x8c);
    if (value == 8 || value == 14)
        return 1;
    else
        return 0;
}

