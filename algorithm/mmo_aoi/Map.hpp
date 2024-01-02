/******************************************************
  > File Name : Map.hpp
  > Author : Edcwsyh
  > Create time : Wed Dec 27 17:36:23 2023
*******************************************************/

#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "MapArea.hpp"
#include <unordered_map>

namespace Edc {

class Map {
//Type
public:
    using AreaMap = std::unordered_map<uint32_t, MapArea>;
    
//Constant
public:
protected:
    
//Member Variables
protected:
    
//Static Member Variables
protected:
    
//Member Function
public:
    Map() = default;
    explicit Map( const Map& ) = default;
    explicit Map( Map&& ) = default;
    ~Map() = default;
    Map& operator=( const Map& ) = default;
    Map& operator=( Map&& ) = default;

    AreaMap m_mapArea;

//Static Member Function
public:
    
};
}

#endif
