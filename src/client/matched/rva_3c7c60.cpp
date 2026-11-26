struct Legacy {
    int getField();
};

int Legacy::getField() {
    return *(int*)((char*)this + 0x7FC);
}
