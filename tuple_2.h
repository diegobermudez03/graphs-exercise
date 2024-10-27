#ifndef __TUPLE_2_H__
#define __TUPLE_2_H__

template<typename T, typename V>
class Tuple2{
    private:
        T value1;
        V value2;
    public:
        Tuple2(T value1, V value2);
        T getValue1();
        V getValue2();
};

#include "tuple_2.hxx"
#endif