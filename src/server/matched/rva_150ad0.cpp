struct Table384 {
    unsigned char reserved[0x384];
    unsigned int* data;
    unsigned int getAt(unsigned int index);
};
unsigned int Table384::getAt(unsigned int index) { return data[index]; }
