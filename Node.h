#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    private:
        T  data;
        Node* prev;
        Node* next;
    public:
        T& get_data();
        Node* get_prev();
        Node* get_next();
        void set_data(T);
        void set_prev(Node*);
        void set_next(Node*);
        Node(T=T(),Node* = nullptr,Node* =nullptr);
        ~Node();
        Node(const Node&);


};

#endif // NODE_H
