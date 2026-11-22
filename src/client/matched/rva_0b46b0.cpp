struct Legacy {
    char pad[0x58];
    int value;
    int get() const;
};

int Legacy::get() const { return value; }

