struct ServerObject {
  void* field_00;

  void __thiscall SetWordIntoPointee(unsigned short value);
};

void __thiscall ServerObject::SetWordIntoPointee(unsigned short value) {
  void* p = this->field_00;
  if (p != 0) {
    *(unsigned short*)((char*)p + 0x7AC40) = value;
  }
}
