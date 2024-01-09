/******************************************************
  > File Name : ActorMgr.hpp
  > Author : Edcwsyh
  > Create time : Tue Jan  9 17:02:50 2024
*******************************************************/

#ifndef __ACTOR_MGR_HPP__
#define __ACTOR_MGR_HPP__

#include "Actor.hpp"
#include <memory>
#include <unordered_map>

namespace Edc {

using ActorPtr = std::unique_ptr<Actor>;
using ActorMap = std::unordered_map<ActorID, ActorPtr>;

class ActorMgr {
//Type
public:
    
//Constant
public:
protected:
    
//Member Variables
private:
    ActorMap m_oActorMap;
    
//Static Member Variables
protected:
    
//Member Function
public:
    ActorMgr() = default;
    explicit ActorMgr( const ActorMgr& ) = default;
    explicit ActorMgr( ActorMgr&& ) = default;
    ~ActorMgr() = default;
    ActorMgr& operator=( const ActorMgr& ) = default;
    ActorMgr& operator=( ActorMgr&& ) = default;

    Actor* get_actor( ActorID ullActorID ) noexcept { 
        if ( auto pTarget = m_oActorMap.find( ullActorID ); pTarget != m_oActorMap.end() ) {
            return pTarget->second.get();
        }
        return nullptr;
    }

    void erase_actor( ActorID ullActorID ) noexcept {
        m_oActorMap.erase( ullActorID );
    }

//Static Member Function
public:
    
};

}

#endif

