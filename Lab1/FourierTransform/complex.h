#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
    double real, image;

public:
    Complex();
    Complex(double real, double image);
    Complex operator+ (Complex c);
    Complex operator- (Complex c);
    Complex operator* (Complex c);
    Complex operator/ (double divisor);
    Complex conj (Complex c);



};

#endif // COMPLEX_H
