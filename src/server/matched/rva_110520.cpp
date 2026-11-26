struct MyClass {
    char pad[44];
    int field;
    void clear();
};

void MyClass::clear() {
    this->field = 0;
}

