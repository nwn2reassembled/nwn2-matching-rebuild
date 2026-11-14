class MyClass{public: static unsigned int __stdcall GetValue(unsigned char *p);};

unsigned int MyClass::GetValue(unsigned char *p){
    return *(reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(p)+0x610));
}
