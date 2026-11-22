class Legacy {
public:
    int readValue() const;
private:
    void* ptr; // first field at offset 0
};

int Legacy::readValue() const {
    return *reinterpret_cast<const int*>(reinterpret_cast<const char*>(ptr) + 0x7ac18);
}

