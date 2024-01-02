/******************************************************
  > File Name : StillLife.hpp
  > Author : Edcwsyh
  > Create time : Fri Dec 29 10:47:03 2023
*******************************************************/

#ifndef __STILL_LIFE_HPP__
#define __STILL_LIFE_HPP__

#include "Action.hpp"
#include "Actor.hpp"

namespace Edc {

class StillLife : public Actor {
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
    StillLife() = default;
    explicit StillLife( const StillLife& ) = default;
    explicit StillLife( StillLife&& ) = default;
    ~StillLife() = default;
    StillLife& operator=( const StillLife& ) = default;
    StillLife& operator=( StillLife&& ) = default;

    virtual int do_action( EnmAction enmAction ) override { return 0; }
//Static Member Function
public:
    
};

}

#endif

