class Legacy {
public:
    int addConst(int x);
private:
    int dummy;
};

int Legacy::addConst(int x) { return x + 0x184; }
