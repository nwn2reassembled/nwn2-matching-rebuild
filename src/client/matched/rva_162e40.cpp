struct Legacy {
    unsigned short get_value() const;
private:
    char pad[0x104];
    unsigned short value;
};

unsigned short Legacy::get_value() const { return value; }
