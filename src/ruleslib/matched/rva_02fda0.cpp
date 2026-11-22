struct MyStruct {
    void setByte(void* ptr, unsigned int index, unsigned char val);
};

void MyStruct::setByte(void* ptr, unsigned int index, unsigned char val)
{
    *reinterpret_cast<unsigned char*>(static_cast<char*>(ptr) + index + 8) = val;
}

