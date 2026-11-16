struct Dummy{
    static void __stdcall setByte(unsigned char* ptr,unsigned char value);
};

void Dummy::setByte(unsigned char* ptr,unsigned char value){
    ptr[2]=value;
}

