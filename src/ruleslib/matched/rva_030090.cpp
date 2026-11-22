class MyClass {
public:
    static unsigned short __stdcall readField(void* ptr);
};

struct Dummy { char pad[0x6e]; unsigned short value; };

unsigned short MyClass::readField(void* ptr) {
    return reinterpret_cast<Dummy*>(ptr)->value;
}
