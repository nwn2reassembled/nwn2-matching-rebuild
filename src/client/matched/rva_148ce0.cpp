class MyClass {
public:
    void* placeholder;               // Offset 0
    struct Other* ptr;                // Offset 4 – matches mov eax,[ecx+0x4]
    unsigned short getField() const;
};

struct Other {
    char pad[0x10018];                // Padding to reach offset 0x10018
    unsigned short field;             // Field at [eax+0x10018]
};

unsigned short MyClass::getField() const {
    return ptr->field;               // mov ax,[eax+0x10018] and ret
}

