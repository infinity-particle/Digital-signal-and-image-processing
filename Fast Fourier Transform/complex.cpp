#include <complex.h>

Complex::Complex()
{

}

Complex::Complex(double real, double image)
{
    this->real = real;
    this->image = image;
}

Complex::Complex operator +(Complex c)
{
    return Complex (real + c.real, image + c.image);
}

Complex::Complex operator -(Complex c)
{
    return Complex (real - c.real, image - c.image);
}

Complex::Complex operator /(double divisor)
{
    return Complex (real/divisor, i/divisor);
}

Complex::Complex operator *(Complex c)
{
    return Complex (real * c.real- image * c.image,real * c.image + image * c.real);
}

Complex::Complex conj (Complex c)
{
    return Complex (c.real, -c.image);
}
