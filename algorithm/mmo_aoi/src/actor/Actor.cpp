/******************************************************
  > File Name : Actor.cpp
  > Author : Edcwsyh
  > Create time : Thu Jan 25 10:19:08 2024
*******************************************************/

#include "Actor.hpp"
#include "actor/Action.hpp"
#include "base/BaseDef.h"
#include "base/Pos.hpp"
#include "map/BaseMap.hpp"

namespace Edc {

int Actor::enter_map(BaseMap& stMap) {
    int iRet = 0;
    ASSERT_RET( m_pCurMap != &stMap, 0 );
    // leave cur map;
    ASSERT_RET( ( iRet = leave_map() ) == 0, iRet );
    m_pCurMap = &stMap;
    m_oPos = m_pCurMap->birth_pos();
    m_pCurMap->enter_map( *this );
    return 0;
}

int Actor::leave_map() 
{
    CHECK_NULL_RET( m_pCurMap, 0 );
    m_pCurMap->leave_map( *this );
    m_oPos.set_x(0), m_oPos.set_y(0);
    return 0;
}

int Actor::move(PosMoveParam& oMoveParam) {
    ASSERT_RET( m_pCurMap, -1 );
    m_pCurMap->before_actor_move( *this, oMoveParam );
    Pos oOldPos(pos());
    int iStep = oMoveParam.iStep;
    if ( ( oMoveParam.enmDirectType & PosMoveParam::ENM_DIRECT_OPERATE ) == PosMoveParam::ENM_AXIS_SUB ) {
        iStep *= -1;
    }
    switch( oMoveParam.enmDirectType & PosMoveParam::ENM_DIRECT_AXIS_TYPE )
    {
        case PosMoveParam::ENM_AXIS_TYPE_X : m_oPos.move_x( iStep ); break;
        case PosMoveParam::ENM_AXIS_TYPE_Y : m_oPos.move_y( iStep ); break;
        default : return -1;
    }
    m_pCurMap->after_actor_move( *this, oOldPos );
    return 0;
}

void Actor::other_actor_move(const Actor& oOtherActor) {
    // do something
}

void Actor::other_actor_enter_view(const Actor& oOtherActor) {
}

void Actor::other_actor_leave_view(const Actor& oOtherActor) {
}

}
