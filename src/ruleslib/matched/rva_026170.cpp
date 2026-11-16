struct Legacy { int getField(const void* ptr); };

int Legacy::getField(const void* ptr) {
    return *reinterpret_cast<const int*>(reinterpret_cast<const char*>(ptr)+0x164);
}
