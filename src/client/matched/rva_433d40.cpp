struct Legacy {
    char padding[32];
    int value;
    int getAndClear();
};

int Legacy::getAndClear() {
    int tmp = value;   // load [this+0x20]
    value = 0;         // store 0 to [this+0x20]
    return tmp;        // eax holds the original value
}

