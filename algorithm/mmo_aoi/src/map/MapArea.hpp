/******************************************************
  > File Name : MapArea.hpp
  > Author : Edcwsyh
  > Create time : Wed Dec 27 16:44:15 2023
*******************************************************/

#ifndef __MAP_AREA_HPP__
#define __MAP_AREA_HPP__

#include <algorithm>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "actor/Actor.hpp"
#include "actor/ActorMgr.hpp"

namespace Edc {

using ActorSet = std::unordered_set<ActorID>;
using ActorSection = std::pair<ActorSet::const_iterator, ActorSet::const_iterator>;
using MapAreaID = Pos;

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
    MapAreaID m_oAreaID;
    
//Member Function
public:
    MapArea( MapAreaID oAreaID ) : m_oAreaID( oAreaID ) {  }
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

    Pos::BasePosType x() const noexcept { return m_oAreaID.x(); }
    void set_x( Pos::BasePosType dwAxisX ) noexcept { m_oAreaID.set_x( dwAxisX ); }
    Pos::BasePosType y() const noexcept { return m_oAreaID.y(); }
    void set_y( Pos::BasePosType dwAxisY ) noexcept { m_oAreaID.set_y( dwAxisY ); }

    const MapAreaID& pos() const noexcept { return m_oAreaID; }
    template<typename TMapAreaID>
    void set_pos(TMapAreaID&& oAreaID) noexcept { m_oAreaID = std::forward<MapAreaID>( oAreaID ); }

    void notify_actor_move( const Actor& oActor ) {
        for ( ActorID ullActorID : m_setActor ) {
            if ( Actor* pActor = ActorMgr::instance().get_actor( ullActorID ); pActor != nullptr ) {
                pActor->other_actor_move( oActor );
            }
        }
    }
    void notify_actor_enter_view( const Actor& oActor ) {
        for ( ActorID ullActorID : m_setActor ) {
            if ( Actor* pActor = ActorMgr::instance().get_actor( ullActorID ); pActor != nullptr ) {
                pActor->other_actor_enter_view( oActor );
            }
        }
    }
    void notify_actor_leave_view( const Actor& oActor ) {
        for ( ActorID ullActorID : m_setActor ) {
            if ( Actor* pActor = ActorMgr::instance().get_actor( ullActorID ); pActor != nullptr ) {
                pActor->other_actor_leave_view( oActor );
            }
        }
    }
//Static Member Function
public:
    
};

}

#endif

