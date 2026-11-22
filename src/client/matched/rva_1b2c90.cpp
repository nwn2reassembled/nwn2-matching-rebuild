class Legacy {
public:
    void setValue(short);
};

void Legacy::setValue(short val) {
    *(short*)((char*)this + 0x4b8) = val;
}

