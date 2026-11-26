struct Legacy{void set(int idx,const float* src);};
void Legacy::set(int idx,const float* src){float* dest=reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0x188+idx*3*sizeof(float));dest[0]=src[0];dest[1]=src[1];dest[2]=src[2];}
