class Legacy {
public:
    const void* getPtr() const;
};

const void* Legacy::getPtr() const {
    return reinterpret_cast<const char*>(this) + 0x10;
}

