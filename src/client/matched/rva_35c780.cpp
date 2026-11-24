class LegacyClass {
public:
    void* getField();
};

void* LegacyClass::getField() { return reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x194); }
