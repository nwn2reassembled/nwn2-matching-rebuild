struct Legacy {
    char pad[16];
    int a,b,c,d,e,f,g,h,i,j,k;
    void Zero();
};

void Legacy::Zero() {
    this->a = 0;
    this->b = 0;
    this->c = 0;
    this->f = 0;
    this->g = 0;
    this->h = 0;
    this->i = 0;
    this->d = 0;
    this->e = 0;
    this->j = 0;
    this->k = 0;
}

