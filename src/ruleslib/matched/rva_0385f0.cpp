struct MyClass {
    float getField(void* p);
};

float MyClass::getField(void* p) {
    return *reinterpret_cast<const float*>(reinterpret_cast<const char*>(p)+0x8C);
}
