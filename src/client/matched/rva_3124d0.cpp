struct Inner {
    unsigned char pad2[0x5ac];
    unsigned int index;
};

class Legacy {
public:
    unsigned int getField();
private:
    unsigned char pad1[0x54];
    Inner* field54;
};

unsigned int Legacy::getField() {
    Inner* p = this->field54;
    unsigned int idx = p->index;
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(p) + idx * 0x19c + 0x28);
}

