struct Legacy{int dummy;void* field4;int getField94() const;};
int Legacy::getField94() const{return *reinterpret_cast<int*>( reinterpret_cast<char*>(field4)+0x94 );}

