class MyObject {
public:
    int v0;
    int v1;
    int v2;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char unused : 6;
    int compare(const MyObject* other) const;
};

int MyObject::compare(const MyObject* other) const {
    if (v0 == other->v0 && v1 == other->v1 && v2 == other->v2 &&
        bit0 == other->bit0 && bit1 == other->bit1)
        return 1;
    return 0;
}
