/******************************************************
  > File Name : Animal.hpp
  > Author : Edcwsyh
  > Create time : Tue Jan  2 09:55:56 2024
*******************************************************/

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include "Actor.hpp"
#include "actor/Action.hpp"
#include "base/Pos.hpp"

namespace Edc {

class Animal : public Actor {
//Type
public:
    
//Constant
public:
private:
    
//Member Variables
private:
    uint32_t m_dwSpeed;
    
//Static Member Variables
private:
    
//Member Function
public:
    Animal() = default;
    explicit Animal( const Animal& ) = default;
    explicit Animal( Animal&& ) = default;
    ~Animal() = default;
    Animal& operator=( const Animal& ) = default;
    Animal& operator=( Animal&& ) = default;

    virtual int do_action( const ActionParam& oParam ) override;

    virtual int move( const Pos& oNextPos );
//Static Member Function
public:
    
};

}

#endif

