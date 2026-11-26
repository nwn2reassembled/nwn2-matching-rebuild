struct Table378 {
    unsigned char reserved[0x378];
    unsigned int* data;
    unsigned int getAt(unsigned int index);
};
unsigned int Table378::getAt(unsigned int index) { return data[index]; }
