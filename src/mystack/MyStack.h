// Файл MyStack.h
// Шаблонный класс MyStack на основе односвязного списка.
#ifndef MyStack_h           // защита от повторной компиляции
#define MyStack_h           // модуль подключен

// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode              // узел списка
{
private:
    INF d;                  // информационная часть узла
    ListNode *next;         // указатель на следующий узел списка
    ListNode(void) { next = nullptr; } //конструктор
    friend FRIEND;
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    MyStack(void);           // конструктор
    ~MyStack(void);          // освободить динамическую память
    bool empty(void);        // стек пустой?
    bool push(INF n);        // добавить узел в вершину стека
    bool pop(void);          // удалить узел из вершины стека
    INF top_inf(void);      // считать информацию из вершины стека
};


#endif
