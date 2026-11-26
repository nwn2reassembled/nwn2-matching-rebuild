class MyClass{public: void* getOffset(int); private: char padding[192]; void* data;};
void* MyClass::getOffset(int idx){return reinterpret_cast<void*>(reinterpret_cast<char*>(data)+(idx<<6)+48);} 
