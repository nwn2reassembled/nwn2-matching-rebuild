struct Element { char data[28]; };

class Container {
public:
    Element* __stdcall GetElementAt(int index);
private:
    char pad_0x00[0x10];
    Element* elements;
    char pad_0x14[0x04];
    int count;
};

Element* __stdcall Container::GetElementAt(int index) {
    if (index < 0 || index >= this->count) {
        return 0;
    }
    return &this->elements[index];
}
