struct LegacyObj{void setVal(unsigned int ptr,unsigned short val);};

void LegacyObj::setVal(unsigned int ptr,unsigned short val){*((unsigned short*)((char*)ptr+0x61c))=val;}

