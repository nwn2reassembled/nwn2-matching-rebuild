struct MyClass{int dummy; int divisor; int remainder(int const* ptr);};
int MyClass::remainder(int const* ptr){return (*ptr)%divisor;}

