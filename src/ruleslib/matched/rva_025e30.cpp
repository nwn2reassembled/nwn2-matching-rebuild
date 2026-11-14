class Legacy { public: unsigned int readOffset(void* ptr) const; };

unsigned int Legacy::readOffset(void* ptr) const {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr)+0xBC);
}

