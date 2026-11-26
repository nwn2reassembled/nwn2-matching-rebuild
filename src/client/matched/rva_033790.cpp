struct _Node;

struct _Tree {
    _Node* _Dummy;
    _Node* _Myhead;
    void _Lrotate(_Node* _X);
};

struct _Node {
    _Node* _Left;
    _Node* _Parent;
    _Node* _Right;
    char _Pad[9];
    unsigned char _Isnil;
};

void _Tree::_Lrotate(_Node* _X)
{
    _Node* _Y = _X->_Right;
    _X->_Right = _Y->_Left;
    if (!_Y->_Left->_Isnil)
        _Y->_Left->_Parent = _X;
    _Y->_Parent = _X->_Parent;
    if (_X == _Myhead->_Parent)
        _Myhead->_Parent = _Y;
    else if (_X == _X->_Parent->_Left)
        _X->_Parent->_Left = _Y;
    else
        _X->_Parent->_Right = _Y;
    _Y->_Left = _X;
    _X->_Parent = _Y;
}
