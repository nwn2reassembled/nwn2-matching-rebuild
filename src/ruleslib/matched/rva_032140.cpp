class Legacy {
public:
    static void __stdcall setField(Legacy* obj, int value);
private:
    char padding[0x78];
    int field;
};

void Legacy::setField(Legacy* obj, int value) { obj->field = value; }

