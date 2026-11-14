struct MyClass{ unsigned char method(void*); }; unsigned char MyClass::method(void* arg){ return *reinterpret_cast<unsigned char*>(static_cast<char*>(arg)+0x18); }
