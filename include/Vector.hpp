/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

template<typename T>
class Vector {
    public:
        Vector(T x, T y) {
            _x = x;
            _y = y;
        }
        ~Vector() = default;
        template<typename T> Vector(const Vector<T> &copy);

        bool operator==(Vector<T> const &) const {
            if (_x == other._x && _y == other._y)
                return true;
            return false;
        }
        bool operator!=(Vector<T> const &) const {
            if (_x != other._x && _y != other._y)
                return true;
            return false;
        }
        Vector operator+(Vector<T> const &) {
            Vector<T> newVec(_x, _y);

            newVec._x += other._x;
            newVec._y += other._y;
            return newVec;
        }
        Vector operator-(Vector<T> const &) {
            Vector<T> newVec(_x, _y);

            newVec._x -= other._x;
            newVec._y -= other._y;
            return newVec;
        }
        Vector &operator=(Vector<T> const &) {
            _x = other._x;
            _y = other._y;
            return &this;
        }
        T _x;
        T _y;
};

#endif /* !VECTOR_HPP_ */
