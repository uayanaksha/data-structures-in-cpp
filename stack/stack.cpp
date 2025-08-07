#include <stdexcept>
template<typename T>
class Stack{
  private:
    struct node{
      T data;
      node* next;
      node(const T& _data, node* _next) : data(_data), next(_next) {}
      node(T&& _data, node* _next) : data(std::move(_data)), next(_next) {}
    };
    node* head = nullptr;
  public:
    Stack(): head(nullptr) {}
    ~Stack(){ clear(); }
    bool empty(){ return head == nullptr ; }
    T top() {
      if(empty()){
        throw std::out_of_range("Stack<>::top(): empty stack");
      }
      return head->data;
    }
    T top() const {
      if(empty()){
        throw std::out_of_range("Stack<>::top() const: empty stack");
      }
      return head->data;
    }
    void push(T&& _data){
      head = new node(std::move(_data), head);
    }
    void push(const T& _data){
      head = new node(_data, head);
    }
    void pop(){
      if(empty()){
        throw std::out_of_range("Stack<>::pop(): empty stack");
      }
      node* tmp = head;
      head = head->next;
      delete tmp;
    }
    void clear(){
      while(!empty()){
        pop();
      }
    }
};
