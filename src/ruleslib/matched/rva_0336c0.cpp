struct Legacy {
    int getByte(void* arg);
};

int Legacy::getByte(void* arg) {
    return static_cast<const unsigned char*>(arg)[0xCB];
}
