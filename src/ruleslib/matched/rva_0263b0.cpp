struct Legacy{int foo(void*);};
int Legacy::foo(void* ptr){return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr)+0x220);}
