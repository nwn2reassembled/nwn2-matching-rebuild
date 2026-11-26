struct Legacy{ void clearField(); }; void Legacy::clearField(){ *(int*)((char*)this+0x1b8)=0; }
