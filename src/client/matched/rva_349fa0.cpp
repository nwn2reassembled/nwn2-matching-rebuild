class Legacy {
public:
    void setFlag();
};

void Legacy::setFlag() {
    *(int*)((char*)this + 0x824) = 1;
}

