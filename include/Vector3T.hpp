/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Vector3T
*/

#ifndef VECTOR3T_HPP_
#define VECTOR3T_HPP_

#include <iostream>

template <class T>
class Vector3T {
    public:
        Vector3T(T x, T y, T Z);
        Vector3T();
        ~Vector3T() = default;
        Vector3T(const Vector3T<T> &copy);

        bool operator==(Vector3T<T> const &other) const noexcept;
        bool operator!=(Vector3T<T> const &other) const noexcept;
        Vector3T<T> operator+(Vector3T<T> const &other) const noexcept;
        Vector3T<T> operator-(Vector3T<T> const &other) const noexcept;
        Vector3T<T> &operator=(Vector3T<T> const &other) noexcept;
        Vector3T<T> operator*(Vector3T<T> const &other) const noexcept;
        Vector3T<T> operator*(T const &ohter) const noexcept;


        T _x;
        T _y;
        T _z;
};

template <typename T>
std::ostream &operator<<(std::ostream &s, Vector3T<T> vec)
{
    s << "{" << vec._x << ", " << vec._y << ", " << vec._z << "}";
    return s;
}

//-------------------------

//CODE

template <class T>
Vector3T<T>::Vector3T(T x, T y, T z)
{
    _x = x;
    _y = y;
    _z = z;
}

template <class T>
Vector3T<T>::Vector3T()
{
    _x = 0;
    _y = 0;
    _z = 0;
}

template <class T>
Vector3T<T>::Vector3T(const Vector3T<T> &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

template <class T>
Vector3T<T> &Vector3T<T>::operator=(const Vector3T<T> &other) noexcept
{
    if (this == &other)
        return *this;
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return *this;
}

template <class T>
bool Vector3T<T>::operator==(Vector3T<T> const &other) const noexcept
{
    if (_x == other._x && _y == other._y && _z == other._z)
        return true;
    return false;
}

template <class T>
bool Vector3T<T>::operator!=(Vector3T<T> const &other) const noexcept
{
    if (_x == other._x && _y == other._y && _z == other._z)
        return false;
    return true;
}

template <class T>
Vector3T<T> Vector3T<T>::operator+(Vector3T<T> const &other) const noexcept
{
    Vector3T<T> new_vec{_x, _y, _z};

    new_vec._x += other._x;
    new_vec._y += other._y;
    new_vec._z += other._z;
    return new_vec;
}

template <class T>
Vector3T<T> Vector3T<T>::operator-(Vector3T<T> const &other) const noexcept
{
    Vector3T<T> new_vec{_x, _y, _z};

    new_vec._x -= other._x;
    new_vec._y -= other._y;
    new_vec._z -= other._z;
    return new_vec;
}

template <class T>
Vector3T<T> Vector3T<T>::operator*(Vector3T<T> const &other) const noexcept
{
    Vector3T<T> new_vec{_x, _y, _z};

    new_vec._x *= other._x;
    new_vec._y *= other._y;
    new_vec._z *= other._z;
    return new_vec;
}

template <class T>
Vector3T<T> Vector3T<T>::operator*(T const &other) const noexcept
{
    Vector3T<T> new_vec{_x, _y, _z};

    new_vec._x *= other;
    new_vec._y *= other;
    new_vec._z *= other;
    return new_vec;
}


#endif /* !VECTOR3T_HPP_ */
