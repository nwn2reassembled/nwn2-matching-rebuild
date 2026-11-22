struct Legacy {
    unsigned int getField(void* ptr) const;
};

unsigned int Legacy::getField(void* ptr) const
{
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr)+0x218);
}

