class Legacy{public: unsigned char readByte() const;};
unsigned char Legacy::readByte() const
{
    return *(const unsigned char*)((const char*)this + 0x44);
}

