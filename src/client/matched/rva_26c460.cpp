struct Foo {
    int* items;
    int pad1;
    int count;

    int Find(int value) const;
};

int Foo::Find(int value) const {
    int count = this->count;
    int i = 0;
    if (count > 0) {
        const int* p = this->items;
        do {
            if (*p == value) {
                return 1;
            }
            ++i;
            ++p;
        } while (i < count);
    }
    return 0;
}
