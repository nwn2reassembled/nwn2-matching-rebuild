class Legacy {
public:
    int compute(int);
private:
    int limit;
    int base;
};

int Legacy::compute(int value) {
    int result = 0;
    if (value != 0) {
        unsigned mask = 1u;
        for (int i = 1; i < 25; ++i, mask <<= 1) {
            if (value & mask) {
                result = i;
                break;
            }
        }
    }
    int baseVal = base;
    if (!baseVal) return 0;
    if (result < 0 || result >= limit) return 0;
    return result * 92 + baseVal;
}
