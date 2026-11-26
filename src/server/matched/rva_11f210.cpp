struct Outer{ struct Inner; Inner* inner; int getVal() const; };

struct Outer::Inner{ char pad[0x38]; int value; };

int Outer::getVal() const { return inner->value; }
