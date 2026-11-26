class ServerObject {
public:
    unsigned long GetSomething();

private:
    unsigned char pad[0x358];
    unsigned long field_358;
};

unsigned long ServerObject::GetSomething() {
    return this->field_358;
}
