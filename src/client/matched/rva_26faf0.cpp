struct MyStruct{void* reset();};

void* MyStruct::reset(){
    unsigned* p=reinterpret_cast<unsigned*>(this);
    p[0]=0; p[1]=0; p[2]=0; p[3]=0; p[4]=0;
    p[5]=0; p[6]=0; p[7]=0; p[8]=0; p[9]=0;
    p[10]=0; p[11]=0; p[12]=0; p[13]=0; p[14]=0;
    p[15]=0; p[16]=0; p[17]=0; p[18]=0; p[19]=0;
    p[20]=0; p[21]=0; p[22]=0; p[23]=0;
    return this;
}

