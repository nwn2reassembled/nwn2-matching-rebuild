struct MyStruct{static void __stdcall setByte(void* ptr,unsigned char val);};

void MyStruct::setByte(void* ptr,unsigned char val){
    static_cast<unsigned char*>(ptr)[0x1D]=val;
}
