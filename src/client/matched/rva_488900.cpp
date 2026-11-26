struct Legacy {
    char pad[64];
    int val;
    int getVal() const;
};

int Legacy::getVal() const { return val; }
