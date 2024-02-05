/******************************************************
  > File Name : BaseMap.cpp
  > Author : Edcwsyh
  > Create time : Thu Jan 25 10:34:07 2024
*******************************************************/

#include "BaseMap.hpp"
#include "base/BaseDef.h"
#include "base/Pos.hpp"
#include "map/MapArea.hpp"
#include <algorithm>
#include <vector>

namespace Edc
{


void Edc::BaseMap::leave_map(Actor& oActor) {
}

void Edc::BaseMap::enter_map(Actor& oActor) {
}

Pos Edc::BaseMap::birth_pos() {
    return Pos();
}

void BaseMap::after_actor_move(Actor& oActor, const Pos& oPrePos) {
    static std::vector<MapAreaID::ConcatPosType> oOldAreaVec, oNewAreaVec;
    MapAreaID oOldAreaID( calc_area_id( oPrePos ) ), oNewAreaID( calc_area_id( oActor.pos() ) );
    collect_adjacent_area( oOldAreaID, oOldAreaVec );
    if ( oOldAreaID == oNewAreaID ) {
        for ( auto& oMapAreaID : oOldAreaVec ) {
            MapArea* pArea = get_area( oMapAreaID );
            ASSERT_EXEC( pArea, pArea->notify_actor_move( oActor ) );
        }
    } else {
        collect_adjacent_area( oNewAreaID, oNewAreaVec );
        for ( auto& oMapAreaID : oNewAreaVec ) {
            MapArea* pArea = get_area( oMapAreaID );
            CHECK_NULL_CONTINUE( pArea );
            if ( auto pTarget = std::lower_bound( oOldAreaVec.begin(), oOldAreaVec.end(), oMapAreaID ); 
                pTarget != oOldAreaVec.end() && *pTarget == oMapAreaID 
            ) {
                *pTarget = 0;
                pArea->notify_actor_move( oActor );
            } else {
                pArea->notify_actor_enter_view( oActor );
            }
        }
        for ( auto& oMapAreaID : oOldAreaVec ) {
            ASSERT_CONTINUE( oMapAreaID != 0 );
            MapArea* pArea = get_area( oMapAreaID );
            CHECK_NULL_CONTINUE( pArea );
            pArea->notify_actor_leave_view( oActor );
        }
    }
}

void BaseMap::collect_adjacent_area(const MapAreaID& oCenterID, std::vector<Pos::ConcatPosType> vecPos) const noexcept {
    std::size_t nVecSize = ( wide_x() * 2 + 1 ) * ( wide_y() * 2 + 1 );
    int idx = 0;
    vecPos.resize( nVecSize );
    for ( int x = oCenterID.x() - m_iAreaWideX, xMax = oCenterID.x() + m_iAreaWideX; x <= xMax; ++x ) {
        for ( int y = oCenterID.y() - m_iAreaWideY, yMax = oCenterID.y() + m_iAreaWideY; y <= yMax; ++y ) {
            vecPos[idx++] = Pos::concat_pos( x, y );
        }
    }
}

}
