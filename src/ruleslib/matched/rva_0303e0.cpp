class MyClass {
public:
    void setValue(void* ptr, float value);
};

void MyClass::setValue(void* ptr, float value) {
    *reinterpret_cast<float*>(reinterpret_cast<char*>(ptr)+0x98) = value;
}

