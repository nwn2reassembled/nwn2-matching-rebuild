struct SomeStruct {
    char pad[416];
    unsigned int value;
};

struct Outer {
    unsigned int getValue(const SomeStruct* ptr);
};

unsigned int Outer::getValue(const SomeStruct* ptr) {
    return ptr->value;
}

