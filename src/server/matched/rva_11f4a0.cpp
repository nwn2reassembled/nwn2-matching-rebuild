struct Legacy {
    char padding[28];
    unsigned char value;

    unsigned char get_value() const;
};

unsigned char Legacy::get_value() const { return value; }
