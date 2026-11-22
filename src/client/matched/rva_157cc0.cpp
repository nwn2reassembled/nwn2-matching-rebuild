class MyClass {
public:
    unsigned int getField() const;
};

unsigned int MyClass::getField() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xe68);
}

