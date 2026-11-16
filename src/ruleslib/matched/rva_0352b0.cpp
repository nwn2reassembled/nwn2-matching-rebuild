class Legacy{public: unsigned char getByte(void* p);};

unsigned char Legacy::getByte(void* p){
    return *reinterpret_cast<unsigned char*>(static_cast<char*>(p)+0x28);
}

