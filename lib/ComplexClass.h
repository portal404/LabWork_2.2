#pragma once
#include <iostream>
#include <cmath>
using namespace std;


template <typename T>
class TComplex
{
protected:
    T re;
    T im;
public:
    TComplex();
    TComplex(T re_, T im_);
    TComplex(const TComplex& p);
    ~TComplex();

    T GetRe() const;
    T GetIm() const;
    void SetRe(T r);
    void SetIm(T i);
    T ComplexAbs(); // 1-е дополнительное задание

    TComplex operator+ (const TComplex<T>& p);
    TComplex operator- (const TComplex<T>& p);
    TComplex operator* (const TComplex<T>& p);
    TComplex operator/ (const TComplex<T>& p);

    TComplex& operator+= (const TComplex<T>& p);
    TComplex& operator-= (const TComplex<T>& p);
    TComplex& operator*= (const TComplex<T>& p);
    TComplex& operator/= (const TComplex<T>& p);

    TComplex& operator=(const TComplex<T>& p);

    bool operator!=(const TComplex<T>& p);
    bool operator==(const TComplex<T>& p);

    template<class T1>
    friend ostream& operator<<(ostream& o, TComplex<T1>& b);

    template<class T1>
    friend istream& operator>>(istream& i, TComplex<T1>& b);
};


template <class T>
inline TComplex<T>::TComplex(): re(1), im(0)
{}

template <class T>
inline TComplex<T>::TComplex(T re_, T im_) : re(re_), im(im_)
{}

template <class T>
inline TComplex<T>::TComplex(const TComplex& p)
{
  re = p.GetRe();
  im = p.GetIm();
}

template <class T>
inline TComplex<T>::~TComplex()
{}

template <class T>
inline T TComplex<T>::GetRe() const
{
  return re;
}

template <class T>
inline T TComplex<T>::GetIm() const
{
  return im;
}

template<class T>
inline void TComplex<T>::SetRe(T r)
{
  re = r;
}

template<class T>
inline void TComplex<T>::SetIm(T i)
{
  im = i;
}

template<class T>
inline T TComplex<T>::ComplexAbs()
{
  return sqrt(re*re + im*im);
}

template<class T>
inline TComplex<T> TComplex<T>::operator+(const TComplex<T>& p)
{
  return TComplex(re + p.re, im + p.im);
}

template<class T>
inline TComplex<T> TComplex<T>::operator-(const TComplex<T>& p)
{
  return TComplex(re - p.re, im - p.im);
}

template<class T>
inline TComplex<T>& TComplex<T>::operator+=(const TComplex<T>& p)
{
  re+=p.re;
  im+=p.im;
  return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator*=(const TComplex<T>& p)
{
  const T re_ = re;
  const T im_ = im;
  T real = re = re_ * p.re - im_ * p.im;
  T img = im = re_ * p.im + im_ * p.re;
  re = real;
  im = img;
  return *this;
}

template<class T>
inline TComplex<T> TComplex<T>::operator*(const TComplex<T>& p)
{
  return TComplex(re * p.re - im * p.im, re * p.im + im * p.re);
}


template<class T>
inline TComplex<T> TComplex<T>::operator/(const TComplex<T>& p)
{
  return TComplex((re * p.re + im * p.im) / (p.re * p.re + p.im * p.im),
                  (im * p.re - re * p.im) / (p.re * p.re - p.im * p.im));
}


template<class T>
inline TComplex<T>& TComplex<T>::operator-=(const TComplex<T>& p)
{
  re -= p.re;
  im -= p.im;
  return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator /= (const TComplex<T>& p)
{
  T real = ((re * p.re) + (im * p.im)) / ((p.re * p.re) + (p.im * p.im));
  T img = ((im * p.re) - (re * p.im)) / ((p.re * p.re) - (p.im * p.im));

  re = real;
  im = img;
  return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator = (const TComplex<T>& p)
{
  re = p.re;
  im = p.im;
  return *this;
}

template<class T>
inline bool TComplex<T>::operator == (const TComplex<T>& p)
{
  return (re == p.re) && (im == p.im);
}

template<class T>
inline bool TComplex<T>::operator != (const TComplex<T>& p)
{
  return !(*this == p);
}

template<class T1>
inline ostream& operator<<(ostream& o, TComplex<T1>& b)
{
  o << b.GetRe() << "+" << b.GetIm() << "i" << '\n';
  return o;
}

template<class T1>
inline istream& operator>>(istream& i, TComplex<T1>& b)
{
  cout << "Real part:" << "\n";
  i >> b.re;
  cout << "Imaginary part:" << "\n";
  i >> b.im;
  return i;
}

