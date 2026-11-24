class MyStruct{public: void* get_ptr();};
void* MyStruct::get_ptr(){return reinterpret_cast<void*>(reinterpret_cast<char*>(this)+0x184);}
