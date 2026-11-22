struct SubObject {};

class MyClass {
public:
    SubObject& getSub();
};

SubObject& MyClass::getSub() {
    return *reinterpret_cast<SubObject*>( reinterpret_cast<char*>(this) + 0x398 );
}

