struct Obj3 {
    unsigned char pad_0000[0x12c];
    struct Obj2* field_12c;

    void* get_tail();
};

struct Obj2 {
    unsigned char pad_0000[0xbb4];
    struct Obj1* field_bb4;
};

struct Obj1 {
    unsigned char pad_0000[0x30];
    unsigned char* field_30;
};

void* Obj3::get_tail() {
    if (field_12c != 0) {
        Obj2* b = field_12c;
        if (b->field_bb4 != 0) {
            return b->field_bb4->field_30 + 0x150;
        }
    }
    return 0;
}
