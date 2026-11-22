struct Legacy {
    int getValue() const;
};

int Legacy::getValue() const { return *reinterpret_cast<const int*>(reinterpret_cast<const char*>(this) + 0x64); }
