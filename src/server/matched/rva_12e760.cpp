struct Ctx {
  unsigned char pad0[0x24];
  int field24;
  int __cdecl GetField24();
};

int __cdecl Ctx::GetField24() {
  return this->field24;
}
