struct Payload {
    unsigned long data[8];
};

class MyStruct {
public:
    unsigned long data[8];
    void* copyTo(void* dest) const;
};

void* MyStruct::copyTo(void* dest) const {
    *reinterpret_cast<Payload*>(dest) = *reinterpret_cast<const Payload*>(this);
    reinterpret_cast<unsigned char*>(dest)[32] = 0;
    return dest;
}
