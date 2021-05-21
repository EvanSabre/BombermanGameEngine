/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Vector
*/

#include "Vector.hpp"

template <typename T>
Vector<T>::Vector(T x, T y)
{
    _x = x;
    _y = y;
}

template <typename T>
bool Vector<T>::operator==(Vector<T> const &other) const
{
    if (_x == other._x && _y == other._y)
        return true;
    return false;
}

template<typename T>
bool Vector<T>::operator!=(Vector<T> const &other) const
{
    if (_x != other._x && _y != other._y)
        return true;
    return false;
}

template<typename T>
Vector<T> Vector<T>::operator+(Vector<T> const &other)
{
    Vector<T> newVec(_x, _y);

    newVec._x += other._x;
    newVec._y += other._y;
    return newVec;
}

template<typename T>
Vector<T> Vector<T>::operator-(Vector<T> const &other)
{
    Vector<T> newVec(_x, _y);

    newVec._x -= other._x;
    newVec._y -= other._y;
    return newVec;
}

template<typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &other)
{
    _x = other._x;
    _y = other._y;
    return &this;
}
