struct MyClass {
    int field0;
    int field1;
    void* targetField;

    void* getTarget();
};

void* MyClass::getTarget() { return &targetField; }

