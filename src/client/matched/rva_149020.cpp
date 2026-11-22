struct Legacy{int dummy;void* ptr;void func(int);};

void Legacy::func(int value){*((int*)((char*)ptr+0x10058))=value;}

