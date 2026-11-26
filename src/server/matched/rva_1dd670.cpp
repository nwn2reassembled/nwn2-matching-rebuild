struct Legacy {
    void process(float*);
};

void Legacy::process(float* dst) {
    *dst = *(float*)((char*)this + 0x182c) * *(float*)((char*)this + 0x200c);
    *(dst+1) = *(float*)((char*)this + 0x1830) * *(float*)((char*)this + 0x200c);
    *(dst+2) = *(float*)((char*)this + 0x1834) * *(float*)((char*)this + 0x200c);
}

