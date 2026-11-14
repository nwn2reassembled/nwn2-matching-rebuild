struct Target {
    char padding[16];
    unsigned int value;
};

class Processor {
public:
    void setValue(Target* dst, unsigned int src);
};

void Processor::setValue(Target* dst, unsigned int src) {
    if (dst)
        dst->value = src;
}

