struct Legacy {
    int placeholder;
    unsigned int value; // offset 4
    static bool __stdcall CheckField(const Legacy* p);
};

bool __stdcall Legacy::CheckField(const Legacy* p) {
    return p->value == 16u;
}
