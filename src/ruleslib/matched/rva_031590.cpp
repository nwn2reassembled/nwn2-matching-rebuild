struct Target{unsigned char data[1536];};
class Foo{public: void setByte(Target* tgt,unsigned char val);};
void Foo::setByte(Target* tgt,unsigned char val){tgt->data[0x5f6]=val;}
