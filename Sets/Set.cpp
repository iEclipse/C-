#include "Set.h"

template <class T>
void Set<T>::add(T value)
{
    for (int i = 0; i < newSet.size(); i++)
        if (newSet.at(i) == value)
            return;
    newSet.push_back(value);
}

template <class T>
T Set<T>::get(int index) const
{
    return newSet.at(index);
}

template <class T>
int Set<T>::size() const
{
    return newSet.size();
}

template <class T>
void Set<T>::remove(T value)
{
    for (int i = 0; i < newSet.size(); i++)
        if (newSet.at(i) == value)
            newSet.erase(newSet.begin() + i);
}

template <class T>
Set<T> Set<T>::operator|(Set<T> other) const
{
    for (int i = 0; i < newSet.size(); i++)
        other.add(newSet.at(i));
    return other;
}

template <class T>
Set<T> Set<T>::operator&(const Set<T> other) const
{
    Set<T> temp;
    for (int i = 0; i < other.size(); i++)
        for (int j = 0; j < newSet.size(); j++)
        {
            if (other.get(i) == newSet.at(j))
                temp.add(other.get(i));
        }
    return temp;
}

template <class T>
void Set<T>::clear()
{
    newSet.clear();
}

template <class T>
Set<T> Set<T>::operator^(const Set<T> other) const
{
    bool found;
    Set<T> temp;
    for (int i = 0; i < newSet.size(); i++)
    {
        found = false;
        for (int j = 0; j < other.size(); j++)
            if (newSet.at(i) == other.get(j))
            {
                found = true;
                break;
            }
        if (!found)
            temp.add(newSet.at(i));
    }
    return temp;
}

template <class T>
std::string Set<T>::toString() const
{
    std::string temp = "";
    if (newSet.size() == 0)
        return "Empty";
    for (int i = 0; i < newSet.size(); i++)
        temp += newSet.at(i) + " ";
    return temp;
}
