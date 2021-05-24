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
        Vector() : _x(0), _y(0) {};
        Vector(T x, T y);
        ~Vector() = default;
        template<typename T> Vector(const Vector<T> &copy);

        bool operator==(Vector<T> const &) const;
        bool operator!=(Vector<T> const &) const;
        Vector operator+(Vector<T> const &);
        Vector operator-(Vector<T> const &);
        Vector &operator=(Vector<T> const &);
        T _x;
        T _y;
};

#endif /* !VECTOR_HPP_ */
