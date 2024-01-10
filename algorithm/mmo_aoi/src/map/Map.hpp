/******************************************************
  > File Name : Map.hpp
  > Author : Edcwsyh
  > Create time : Wed Dec 27 17:36:23 2023
*******************************************************/

#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <unordered_map>
#include <utility>
#include <vector>
#include "MapArea.hpp"
#include "base/Pos.hpp"

namespace Edc {

class Map {
//Type
public:
    using AreaMap = std::unordered_map<Pos::ConcatPosType, MapArea>;
    using AreaSet = std::unordered_set<MapArea*>;
    
//Constant
public:
protected:
    
//Member Variables
protected:
    AreaMap m_mapArea;
    int m_iWideX;
    int m_iWideY;
    
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

    MapArea* get_area( Pos::ConcatPosType ullPosID ) noexcept {
        if ( auto pTarget = m_mapArea.find( ullPosID ); pTarget != m_mapArea.end() ) {
            return &pTarget->second;
        }
        return nullptr;
    }

    MapArea* get_area( const Pos& oPos ) noexcept { return get_area( oPos.hash() ); }

    int wide_x() const noexcept { return m_iWideX; }
    int wide_y() const noexcept { return m_iWideY; }

    // return Pos id array, this array be ordered
    // 'vecPos' can be static variables and no call 'clear', it will perform better
    void collect_adjacent_area( const Pos& oPos, std::vector<Pos::ConcatPosType> vecPos ) const noexcept {
        std::size_t nVecSize = ( wide_x() * 2 + 1 ) * ( wide_y() * 2 + 1 );
        int idx = 0;
        vecPos.resize( nVecSize );
        for ( int x = oPos.x() - m_iWideX, xMax = oPos.x() + m_iWideX; x <= xMax; ++x ) {
            for ( int y = oPos.y() - m_iWideY, yMax = oPos.y() + m_iWideY; y <= yMax; ++y ) {
                vecPos[idx++] = Pos::concat_pos( x, y );
            }
        }
    }

//Static Member Function
public:
    
};
}

#endif
