struct MyClass {
    struct FieldType;
    FieldType* getField();
};

MyClass::FieldType* MyClass::getField() {
    return reinterpret_cast<MyClass::FieldType*>(reinterpret_cast<char*>(this) + 0x318);
}
