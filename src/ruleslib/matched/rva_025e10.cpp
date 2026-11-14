class Legacy {
public:
    unsigned int getField(const void* obj) const;
};

unsigned int Legacy::getField(const void* obj) const {
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(obj)+0x148);
}
