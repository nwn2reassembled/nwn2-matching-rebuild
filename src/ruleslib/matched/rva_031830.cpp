struct Legacy{ bool is_magic(const unsigned char *p); }; bool Legacy::is_magic(const unsigned char *p){ return *(const unsigned int *)p==0x27; }
