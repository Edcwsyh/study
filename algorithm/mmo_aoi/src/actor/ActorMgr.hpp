/******************************************************
  > File Name : ActorMgr.hpp
  > Author : Edcwsyh
  > Create time : Tue Jan  9 17:02:50 2024
*******************************************************/

#ifndef __ACTOR_MGR_HPP__
#define __ACTOR_MGR_HPP__

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <utility>
#include "Actor.hpp"
#include "base/Singleton.hpp"

namespace Edc {

using ActorPtr = std::unique_ptr<Actor>;
using ActorMap = std::unordered_map<ActorID, ActorPtr>;

class ActorMgr : public Singleton<ActorMgr> {
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
    ~ActorMgr() = default;
    ActorMgr& operator=( const ActorMgr& ) = default;

    Actor* get_actor( ActorID ullActorID ) noexcept { 
        if ( auto pTarget = m_oActorMap.find( ullActorID ); pTarget != m_oActorMap.end() ) {
            return pTarget->second.get();
        }
        return nullptr;
    }

    void erase_actor( ActorID ullActorID ) noexcept {
        m_oActorMap.erase( ullActorID );
    }

    Actor* insert_actor( ActorPtr pActor ) noexcept {
        if ( pActor == nullptr ) {
            return nullptr;
        }
        Actor* pBaseActor = pActor.get();
        m_oActorMap.insert( std::make_pair( pBaseActor->id(), std::move( pActor ) ) );
        return pBaseActor;
    }

//Static Member Function
public:
    
};

}

#endif

