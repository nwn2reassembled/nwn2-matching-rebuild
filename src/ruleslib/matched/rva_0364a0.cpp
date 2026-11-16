class Legacy{public: void setWord(void* base, unsigned int idx, unsigned short val);};

void Legacy::setWord(void* base, unsigned int idx, unsigned short val){
    *reinterpret_cast<unsigned short*>(static_cast<char*>(base)+8+(idx<<1))=val;
}
