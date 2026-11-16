// No includes or preprocessor directives
struct MyStruct {
    char pad[0x150];          // Pad to offset 0x150 where the array pointer lives
    unsigned short* array;   // Pointer to an array of WORDs

    static unsigned short __stdcall Get(const MyStruct*, unsigned short);
};

unsigned short MyStruct::Get(const MyStruct* obj, unsigned short idx) {
    return *(obj->array + idx);   // Return WORD at the given 16‑bit index
}

