extern "C" unsigned int __cdecl strlen(const char*);

struct LegacyObject {
    char* buffer;
    void modify(int index, char value);
};

void LegacyObject::modify(int index, char value) {
    char* p = buffer;
    if (p && index < static_cast<int>(strlen(p)))
        p[index] = value;
}
