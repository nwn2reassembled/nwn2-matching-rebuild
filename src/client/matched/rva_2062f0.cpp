struct LegacyObject {
    int* getOffsetPointer();
};

int* LegacyObject::getOffsetPointer() {
    return reinterpret_cast<int*>(reinterpret_cast<char*>(this) - 0x30);
}
