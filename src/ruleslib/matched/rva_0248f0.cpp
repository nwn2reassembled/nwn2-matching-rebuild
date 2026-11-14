class Legacy {
public:
    int getField(const void* ptr) const;
};

int Legacy::getField(const void* ptr) const {
    // The function returns the 16‑bit value located at offset 0x12 from the
    // supplied pointer, zero‑extended to a 32‑bit integer.
    return static_cast<int>(static_cast<const unsigned short*>(ptr)[0x12/2]);
}

