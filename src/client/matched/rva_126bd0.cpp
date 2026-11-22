struct MyStruct{char pad[56];int zero1;int zero2;int zero3;int zero4;int method();};int MyStruct::method(){this->zero1=0;this->zero2=0;this->zero3=0;this->zero4=0;return 1;}
