class Legacy {
public:
    void reset();
};

void Legacy::reset() {
    *(unsigned int*)((char*)this + 0x410) = 0;
    *(unsigned int*)((char*)this + 0x40c) = 0;
}

