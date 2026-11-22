struct Legacy {
    unsigned short field();
};

unsigned short Legacy::field() {
    return *(unsigned short*)((char*)this + 0x3d0);
}

