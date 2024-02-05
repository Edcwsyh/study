/******************************************************
  > File Name : Actor.hpp
  > Author : Edcwsyh
  > Create time : Wed Dec 27 16:42:30 2023
*******************************************************/

#ifndef __ACTOR_HPP__
#define __ACTOR_HPP__

#include <cstdint>
#include "Action.hpp"
#include "base/Pos.hpp"

namespace Edc {

class BaseMap;

using ActorID = uint64_t;

class Actor {
//Type
public:
    
//Constant
public:
protected:
    
//Member Variables
private:
    // Actor model in map
    char m_cModel;
    // The position of player on the map
    Pos m_oPos;
    // Player map
    BaseMap* m_pCurMap;
    
//Static Member Variables
protected:
    
//Member Function
public:
    Actor() = default;
    explicit Actor( const Actor& ) = default;
    explicit Actor( Actor&& ) = default;
    ~Actor() = default;
    Actor& operator=( const Actor& ) = default;
    Actor& operator=( Actor&& ) = default;

    ActorID id() const noexcept  {
        return reinterpret_cast<uintptr_t>(this);
    }
    
    void set_model( char cModel ) noexcept { m_cModel = cModel; }
    char model() const noexcept { return m_cModel; }

    const Pos& pos() const noexcept { return m_oPos; }

    virtual int enter_map( BaseMap& stMap );

    virtual int leave_map() ;

    virtual int move( PosMoveParam& oMoveParam );

    virtual void other_actor_move( const Actor& oOtherActor );
    virtual void other_actor_enter_view( const Actor& oOtherActor );
    virtual void other_actor_leave_view( const Actor& oOtherActor );
//Static Member Function
public:
    
};

}

#endif

