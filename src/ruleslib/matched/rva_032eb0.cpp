struct LegacyParam {
    char padding[6];
    short value;
};

class LegacyClass {
public:
    short getValue(const LegacyParam* p);
};

short LegacyClass::getValue(const LegacyParam* p) {
    return p->value;
}

