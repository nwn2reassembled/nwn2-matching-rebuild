struct Inner{char pad[0x36c]; int val;};

struct Outer{
    int dummy;
    Inner* innerPtr;
    void method(int param);
};

void Outer::method(int param){
    innerPtr->val = param;
}
