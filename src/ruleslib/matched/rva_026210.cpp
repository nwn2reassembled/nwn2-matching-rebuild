class MyClass {
public:
    unsigned int GetField(void* ptr) const;
};
unsigned int MyClass::GetField(void* ptr) const
{
    return *reinterpret_cast<unsigned int*>(static_cast<char*>(ptr)+0x1c4);
}

