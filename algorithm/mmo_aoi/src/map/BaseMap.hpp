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
#include "actor/Action.hpp"
#include "actor/Actor.hpp"
#include "base/Pos.hpp"

namespace Edc {

class BaseMap {
//Type
public:
    using AreaMap = std::unordered_map<MapAreaID::ConcatPosType, MapArea>;
    using AreaSet = std::unordered_set<MapArea*>;
    
//Constant
public:
protected:
    
//Member Variables
private:
    AreaMap m_mapArea;
    int m_iAreaWideX;
    int m_iAreaWideY;
    
//Static Member Variables
protected:
    
//Member Function
public:
    BaseMap() = default;
    explicit BaseMap( const BaseMap& ) = default;
    explicit BaseMap( BaseMap&& ) = default;
    ~BaseMap() = default;
    BaseMap& operator=( const BaseMap& ) = default;
    BaseMap& operator=( BaseMap&& ) = default;

    MapArea* get_area( Pos::ConcatPosType ullPosID ) noexcept {
        if ( auto pTarget = m_mapArea.find( ullPosID ); pTarget != m_mapArea.end() ) {
            return &pTarget->second;
        }
        return nullptr;
    }

    MapArea* get_area( const Pos& oPos ) noexcept { return get_area( oPos.hash() ); }

    inline MapAreaID calc_area_id( const Pos& pos ) const noexcept {
        return MapAreaID( pos.x() / wide_x(), pos.y() / wide_y() );
    }

    inline MapAreaID::ConcatPosType calc_concat_area_id( const Pos& pos ) const noexcept {
        return MapAreaID::concat_pos( pos.x() / wide_x(), pos.y() / wide_y() );
    }

    int wide_x() const noexcept { return m_iAreaWideX; }
    int wide_y() const noexcept { return m_iAreaWideY; }

    // return Pos id array, this array be ordered
    // 'vecPos' can be static variables and no call 'clear', it will perform better
    void collect_adjacent_area( const MapAreaID& oCenterAreaID, std::vector<Pos::ConcatPosType> vecPos ) const noexcept; 

    virtual void before_actor_move( Actor& oActor, PosMoveParam& oMoveParam ) {  };
    virtual void after_actor_move( Actor& oActor, const Pos& oPrePos );
    virtual Pos birth_pos();
    virtual void leave_map( Actor& oActor );
    virtual void enter_map( Actor& oActor );

//Static Member Function
public:
    
};

}

#endif
