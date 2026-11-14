class Target { public: unsigned char data[0x5C0]; };

class MyClass { public: static void __stdcall setByte(Target* obj, unsigned char value); };

void MyClass::setByte(Target* obj, unsigned char value) {
    obj->data[0x5BF] = value;
}

