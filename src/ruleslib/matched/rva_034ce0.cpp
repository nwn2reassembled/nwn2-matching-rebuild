struct MyClass{static unsigned char __stdcall foo(void* p);};

unsigned char MyClass::foo(void* p){return reinterpret_cast<unsigned char*>(p)[3];}
