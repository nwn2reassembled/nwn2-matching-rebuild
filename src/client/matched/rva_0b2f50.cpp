struct Object;

struct Holder {
    char reserved[0x14];
    Object* object;
    unsigned char GetValue() const;
};

struct Object {
    char reserved[0x20];
    unsigned char value;
};

unsigned char Holder::GetValue() const {
    if (object != 0) {
        return object->value;
    }
    return 0;
}
