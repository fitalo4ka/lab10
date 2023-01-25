#include <iostream>

template<typename type>
class MyPriorityQueue{
private:
    size_t k = 0;
public:
    struct que {
        type elem;
        que *next;
    };
    que *first = nullptr;
    que *last = nullptr;
    void push(type item) {
        que *new_el = new que;
        new_el->elem = item;
        if (size() == 0) {
            new_el->next = nullptr;
            first = new_el;
            last = new_el;
        }
        if (size() == 1) {
            if (item > first->elem) {
                new_el->next = last;
                first = new_el;
            }
            else {
                new_el->next = nullptr;
                last = new_el;
                first->next = last;
            }
        } if (size() > 1) {
            que *more = first;
            first = new_el;
            first->next = more;
            que *one_more = first;
            while (one_more->next != nullptr) {
                if (one_more->elem < one_more->next->elem) {
                    type a = one_more->elem;
                    type b = one_more->next->elem;
                    std::swap(a, b);
                }
                one_more = one_more->next;
            }
        }
        ++k;
    }

    void pop()  {
        MyPriorityQueue<type>::que *next = first->next;
        delete first;
        first = next;
        --k;
    }
    type peek() {
        return first->elem;
    }

    size_t size() {
        return k;
    }

    ~MyPriorityQueue() {
        que *el = first->next;
        delete first;
        while(el != nullptr) {
            first = el;
            el = el->next;
            delete first;
        }
        first = nullptr;
        last = nullptr;
        }
    }
};

template<typename type>
std::ostream & operator<< (std::ostream &ost, MyPriorityQueue<type> &q) {
    auto nw = q.first;
    ost<< "Elems: ";
    while (nw != nullptr) {
        ost << nw->elem << " ";
        nw = nw->next;
    }
    ost << "| number of elements: " << q.size() << std::endl;
    return ost;
}

int main() {
    MyPriorityQueue<int> a;
    a.push(4);
    a.push(3);
    a.push(6);
    std::cout << a;
    std::cout << "Peek element is " << a.peek() << "\n";
    a.pop();
    std::cout << "*happened pop* \n";
    std::cout << a << "\n";

    MyPriorityQueue<float> b;
    b.push(356.7);
    b.push(36.2);
    b.push(634.1);
    b.push(657.22);
    std::cout << b;
    std::cout << "Peek element is " << b.peek() << "\n";
    b.pop();
    std::cout << "*happened pop* \n";
    std::cout << "Peek element is " << b.peek() << "\n";
    b.pop();
    std::cout << "*happened pop* \n";
    b.pop();
    std::cout << "*happened pop* \n";
    std::cout << b << "\n";

    MyPriorityQueue<char> c;
    c.push('t');
    c.push('7');
    c.push('n');
    c.push('Q');
    c.push('#');
    std::cout << c;
    std::cout << "Peek element is " << c.peek() << "\n";
    c.pop();
    std::cout << "*happened pop* \n";
    std::cout << c << "\n";
    return 0;
}
