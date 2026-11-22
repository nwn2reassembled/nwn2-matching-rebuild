class Legacy {
public:
    static int __stdcall addConstant(int value);
};

int Legacy::addConstant(int value) { return value + 0x122; }
