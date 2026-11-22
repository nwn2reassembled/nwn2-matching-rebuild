struct Inner;

struct Outer {
    Inner* ptr;
    void getValues(unsigned int* out1, unsigned short* out2);
};

struct Inner {};

void Outer::getValues(unsigned int* out1, unsigned short* out2) {
    Inner* p = this->ptr;
    *out1 = *(unsigned int*)((char*)p + 0x1390);
    *out2 = *(unsigned short*)((char*)p + 0x139c);
}

