struct Legacy {
    float getValue(void* ptr);
};

float Legacy::getValue(void* ptr) {
    return *(float*)((char*)ptr + 0x30);
}

