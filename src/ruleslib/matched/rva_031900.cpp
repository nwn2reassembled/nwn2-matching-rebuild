struct MyStruct {
    char pad[0x264];
    unsigned short array[256];

    static unsigned short __stdcall GetValue(MyStruct* thisptr, unsigned char idx);
};

unsigned short __stdcall MyStruct::GetValue(MyStruct* thisptr, unsigned char idx) {
    return thisptr->array[idx];
}

