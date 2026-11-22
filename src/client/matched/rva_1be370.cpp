struct Legacy {
    char* getField();
};

char* Legacy::getField() {
    return (char*)((char*)this + 0x314);
}
