struct Legacy {
    short get() const;
};

short Legacy::get() const {
    return *(const short*)((const char*)this + 0x104);
}
