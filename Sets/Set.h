#ifndef Set_H
#define Set_H
#include <vector>

template <class E>
class Set
{
private:
    std::vector<E> newSet;
public:
    void add(E value);
    E get(int index) const;
    int size() const;
    void remove(E value);
    Set<E> operator|(Set<E> other) const; //Union (OR)
    Set<E> operator&(const Set<E> other) const; //Intersection (AND)
    Set<E> operator^(const Set<E> other) const; //Difference (XOR)
    void clear();
    std::string toString() const;
    ~Set() {};
};

#include "Set.cpp"
#endif
