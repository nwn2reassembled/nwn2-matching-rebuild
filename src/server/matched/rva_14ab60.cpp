struct MyClass {
    float getValue();
};

float MyClass::getValue()
{
    return *reinterpret_cast<float*>(0x7ed1ec);
}
