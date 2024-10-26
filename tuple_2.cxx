#include "tuple_2.h"

template<typename T, typename V>
Tuple2<T,V>::Tuple2(T value1, V value2){
    this->value1 = value1;
    this->value2 = value2;
}

template<typename T, typename V>
T Tuple2<T,V>::getValue1(){
    return this->value1;
}

template<typename T, typename V>
V Tuple2<T,V>::getValue2(){
    return this->value2;
}