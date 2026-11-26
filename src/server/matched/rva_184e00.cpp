struct Legacy {
    int GetField();
};

int Legacy::GetField() {
    return *(int*)((char*)this + 0xd0);
}
