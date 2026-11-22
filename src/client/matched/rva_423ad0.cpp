struct Legacy { unsigned int a; unsigned int b; unsigned int c; unsigned int target; void func(unsigned int); };

void Legacy::func(unsigned int x) { target |= x; }
