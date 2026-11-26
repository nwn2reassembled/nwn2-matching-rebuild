typedef unsigned long DWORD;

class SomeClass {
public:
    unsigned char bytes[0x68];
};

int IsFlagSet(SomeClass* obj)
{
    if (obj == 0)
        return 0;
    if (*(DWORD*)(obj->bytes + 0x48) == 0)
        return 0;
    DWORD bits = *(DWORD*)(obj->bytes + 0x64);
    return (bits & 0x30) == 0x30;
}
