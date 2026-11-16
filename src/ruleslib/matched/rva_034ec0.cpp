struct MyClass{ static void __stdcall setByte(void*,unsigned char); };
void MyClass::setByte(void* ptr,unsigned char val){ *(reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr)+0x1c))=val; }
