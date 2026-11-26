class Foo {
public:
  int GetField4();
private:
  int field0;
  int field4;
};

int Foo::GetField4() { return field4; }
