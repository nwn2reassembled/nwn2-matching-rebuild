struct Legacy { int a; int b; int c; int* getC(); }; int* Legacy::getC() { return &c; }
