struct LegacyObject {
    char dummy[0x2F8];
    int field;
};

class LegacyClass {
public:
    int getField(LegacyObject* p);
};

int LegacyClass::getField(LegacyObject* p) { return p->field; }

