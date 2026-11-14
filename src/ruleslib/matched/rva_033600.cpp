class Legacy {public: unsigned char method(void* p);};

unsigned char Legacy::method(void* p){return *reinterpret_cast<unsigned char*>(static_cast<char*>(p)+0x41);}
