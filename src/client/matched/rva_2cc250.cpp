struct Inner { char pad[0x80]; int value; };
struct Outer { int dummy; Inner* inner; int GetValue() const; };
int Outer::GetValue() const { return inner->value; }

