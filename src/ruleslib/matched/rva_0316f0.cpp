struct Legacy {
    int getField(const void* obj);
};

int Legacy::getField(const void* obj) {
    return *(reinterpret_cast<const int*>(reinterpret_cast<const char*>(obj)+0x614));
}

