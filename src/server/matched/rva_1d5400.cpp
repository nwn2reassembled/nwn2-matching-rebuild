struct Legacy {
    void setField(unsigned short val);
};

void Legacy::setField(unsigned short val) {
    *(unsigned short*)((char*)this + 0x3d0) = val;
}

