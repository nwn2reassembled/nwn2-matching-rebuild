struct LegacyFunctionHolder{void setValue(unsigned int* ptr,unsigned short val);};

void LegacyFunctionHolder::setValue(unsigned int* ptr,unsigned short val){
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(ptr)+0x6c)=val;
}
