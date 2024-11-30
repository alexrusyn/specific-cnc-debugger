

template <class T>
T Flags<T>::get()
{
    return buffer;
};

// template <class T>
// void Flags<T>::set(const T x)
// {
//     buffer |= x;
// }

// template <class T>
// T Flags<T>::mask(const T x)
// {
//     return buffer & x;
// }

// template <class T>
// bool Flags<T>::read(const T x)
// {
//     return buffer & x;
// }
