struct Legacy{int getField(void* ptr) const;};
int Legacy::getField(void* ptr) const{return *reinterpret_cast<int*>(static_cast<char*>(ptr)+0xac);}
