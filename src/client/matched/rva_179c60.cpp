class MyClass {
public:
    unsigned long getValue(unsigned index);
private:
    char pad[0x78];
    unsigned long array[10];
};

unsigned long MyClass::getValue(unsigned index) {
    return array[index];
}

