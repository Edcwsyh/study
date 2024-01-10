/******************************************************
  > File Name : MapArea.hpp
  > Author : Edcwsyh
  > Create time : Wed Dec 27 16:44:15 2023
*******************************************************/

#ifndef __MAP_AREA_HPP__
#define __MAP_AREA_HPP__

#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "actor/Actor.hpp"

namespace Edc {

using ActorSet = std::unordered_set<ActorID>;
using ActorSection = std::pair<ActorSet::const_iterator, ActorSet::const_iterator>;

class MapArea {
//Type
public:
    
//Constant
public:
protected:
    
//Member Variables
protected:
    
//Static Member Variables
protected:
    // Actor of in this area
    std::unordered_set<ActorID> m_setActor;
    // (x, y) of this area
    Pos m_oPos;
    
//Member Function
public:
    MapArea( Pos pos ) : m_oPos( pos ) {  }
    explicit MapArea( const MapArea& ) = default;
    explicit MapArea( MapArea&& ) = default;
    ~MapArea() = default;
    MapArea& operator=( const MapArea& ) = delete;
    MapArea& operator=( MapArea&& ) = delete;

    // all actor of this area
    ActorSection actor_section() const noexcept { 
        return { m_setActor.cbegin(), m_setActor.cend() };
    }

    // check the actor is in this area
    bool has_actor( ActorID ullActorID ) const noexcept {
        return m_setActor.count( ullActorID );
    }

    // actor leave this area
    void actor_leave( ActorID ullActorID ) noexcept { 
        m_setActor.erase( ullActorID );
    }

    // actor enter this area
    void actor_enter( ActorID ullActorID ) noexcept { 
        m_setActor.insert( ullActorID );
    }

    Pos::BasePosType x() const noexcept { return m_oPos.x(); }
    void set_x( Pos::BasePosType dwAxisX ) noexcept { m_oPos.set_x( dwAxisX ); }
    Pos::BasePosType y() const noexcept { return m_oPos.y(); }
    void set_y( Pos::BasePosType dwAxisY ) noexcept { m_oPos.set_y( dwAxisY ); }

    const Pos& pos() const noexcept { return m_oPos; }
    template<typename TPos>
    void set_pos(TPos&& pos) noexcept { m_oPos = std::forward<Pos>( pos ); }
//Static Member Function
public:
    
};

}

#endif

