class Legacy {
public:
    static int __stdcall GetValue(const Legacy* p);
private:
    char padding[192];
    int value;
};

int __stdcall Legacy::GetValue(const Legacy* p) {
    return p->value;
}
