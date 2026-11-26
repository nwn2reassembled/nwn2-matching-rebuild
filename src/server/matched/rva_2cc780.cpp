class SomeClass {
public:
    int* GetField();
    int field0;
};

int* SomeClass::GetField() {
    return (int*)this;
}
