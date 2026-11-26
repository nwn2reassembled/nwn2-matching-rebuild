struct Widget {
    void* pad[0x72];      // 0x000..0x1C7
    void* slots[4];       // 0x1C8..0x1D7

    int __fastcall getActiveValue();
};

int __fastcall Widget::getActiveValue()
{
    for (int i = 0; i < 4; ++i) {
        if (this->slots[i] != 0) {
            if (*(int*)((char*)this->slots[i] + 0xDC) > 0) {
                return *(int*)(*(int*)((char*)this->slots[i] + 0xD4));
            }
            return 0x119;
        }
    }
    return 0;
}
