/******************************************************
  > File Name : Animal.hpp
  > Author : Edcwsyh
  > Create time : Tue Jan  2 09:55:56 2024
*******************************************************/

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include "Actor.hpp"

namespace Edc {

class Animal : public Actor {
//Type
public:
    
//Constant
public:
protected:
    
//Member Variables
protected:
    
//Static Member Variables
protected:
    
//Member Function
public:
    Animal() = default;
    explicit Animal( const Animal& ) = default;
    explicit Animal( Animal&& ) = default;
    ~Animal() = default;
    Animal& operator=( const Animal& ) = default;
    Animal& operator=( Animal&& ) = default;
//Static Member Function
public:
    
};

}

#endif

