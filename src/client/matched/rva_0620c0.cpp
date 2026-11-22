class Legacy {
public:
    int dummy;
    void setFlag();
};

void Legacy::setFlag() {
    *((unsigned char*)((char*)this + 0x715)) = 1;
}

