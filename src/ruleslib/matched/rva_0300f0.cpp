struct Object {
    unsigned char padding[0x5c];
    unsigned int value;
};

unsigned int __stdcall ReadValue(const Object* object) {
    return object->value;
}
