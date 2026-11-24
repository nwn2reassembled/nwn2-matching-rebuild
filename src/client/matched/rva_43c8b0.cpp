class MyClass{
public:
    void setField(unsigned int val);
private:
    char pad[48];
    unsigned int m_field;
};

void MyClass::setField(unsigned int val){
    m_field = val;
}

