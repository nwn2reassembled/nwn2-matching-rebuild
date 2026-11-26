struct Legacy {
    int getField() const;
};

int Legacy::getField() const {
    return *(const int*)((const char*)this + 0x6C);
}

