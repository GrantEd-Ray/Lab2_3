#include <iostream>

class Complex
{
private:
    double m_a;
    double m_b;

public:
    explicit Complex(double a = 0.0, double b = 0.0) : m_a(a), m_b(b){}

    Complex(const Complex& z)
    {
        std::cout << "Copy constructor" << std::endl;
        m_a = z.m_a;
        m_b = z.m_b;
    }

    Complex& operator=(Complex z)
    {
        std::swap(m_a, z.m_a);
        std::swap(m_b, z.m_b);
        return *this;
    }

    Complex& operator+=(const Complex& z)
    {
        (*this).m_b += z.m_b;
        (*this).m_a += z.m_a;
        return *this;
    }

    Complex operator+(const Complex& z)
    {
        Complex temp = *this;
        temp += z;
        return temp;
    }

    Complex operator+(double a)
    {
        Complex temp = *this;
        temp.m_a += a;
        return temp;
    }

    Complex& operator*=(const Complex& z)
    {
        (*this).m_a = (*this).m_a * z.m_a - (*this).m_b * z.m_b;
        (*this).m_b = (*this).m_a * z.m_b - (*this).m_b * z.m_a;
        return *this;
    }

    Complex operator*(const Complex& z)
    {
        Complex temp = *this;
        temp *= z;
        return temp;
    }

    void Print()
    {
        std::cout << m_a << ", " << m_b << std::endl;
    }

    // prefix
    Complex& operator++()
    {
        this->m_a += 1;
        return *this;
    }

    // postfix
    Complex& operator++(int)
    {
        Complex temp = *this;
        this->m_a += 1;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& z);
    friend std::istream& operator>>(std::istream& in, Complex& z);

};

Complex operator+(const Complex& z1, const Complex& z2)
{
    Complex temp = z1;
    temp += z2;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Complex& z)
{
    out << z.m_a << " " << z.m_b << "i";
    return out;
}

std::istream& operator>>(std::istream& in, Complex& z)
{
    in >> z.m_a >> z.m_b;
    return in;
}

int main()
{
    Complex z1(1, 1), z2(2, 1);
    Complex z = z1 * z2;
    std::cout << z;
    return 0;
}
