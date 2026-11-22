class Dummy {
public:
    int getValue();
};

int Dummy::getValue() {
    return *(int*)((char*)this + 0x9a0) + 0xc4;
}

