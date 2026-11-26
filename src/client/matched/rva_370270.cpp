struct Legacy {
    char pad[0x1728];
    unsigned int value;
    unsigned int get() const;
};

unsigned int Legacy::get() const { return value; }
