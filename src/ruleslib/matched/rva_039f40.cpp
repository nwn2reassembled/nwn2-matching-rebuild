class Foo {
public:
    // Padding to align member offsets with the original structure layout.
    char pad[0x108];
    int maxLimit;   // offset 0x108
    int current;    // offset 0x10C
    int delta;      // offset 0x110

    int func(int arg);
};

int Foo::func(int arg) {
    if (arg > this->maxLimit)
        return 0;
    if (this->current > arg) {
        int diff = this->current - arg;
        if (diff > this->delta)
            return 0;
        this->delta -= diff;
        this->current = arg;
        return 1;
    } else {
        int diff = arg - this->current;
        this->delta += diff;
        this->current = arg;
        return 1;
    }
}

