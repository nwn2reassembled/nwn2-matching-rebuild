struct MyClass { short getField(); }; short MyClass::getField() { return *reinterpret_cast<short*>(reinterpret_cast<char*>(this)+0x68); }
