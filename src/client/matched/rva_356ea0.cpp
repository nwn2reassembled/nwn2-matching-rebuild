class Legacy {
public:
    int getField() const;
};

int Legacy::getField() const {
    return *(const int*)((char*)this + 0x584);
}

