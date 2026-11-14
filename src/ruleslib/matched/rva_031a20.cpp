class MyClass { public: unsigned char func(int); }; unsigned char MyClass::func(int arg) { return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(arg) + 0x62c); }
