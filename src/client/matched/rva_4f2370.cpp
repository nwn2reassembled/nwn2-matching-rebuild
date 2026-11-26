struct ArrayHolder{int* data; int get(int index);};
int ArrayHolder::get(int index){return data[index];}
