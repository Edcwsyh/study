/******************************************************
  > File Name : Pos.hpp
  > Author : Edcwsyh
  > Create time : Fri Dec 29 10:47:52 2023
*******************************************************/

#ifndef __POS_HPP__
#define __POS_HPP__

#include <algorithm>
#include <cstdint>
#include "ConcatNum.hpp"
#include "base/BaseDef.h"

namespace Edc {

struct PosMoveParam {

    enum EnmAxisOperate {
        ENM_AXIS_ADD = 0b10000000, 
        ENM_AXIS_SUB = 0b00000000, 
    };

    enum EnmAxisType {
        ENM_AXIS_TYPE_X = 0b001, 
        ENM_AXIS_TYPE_Y = 0b010, 
    };

    enum EnmDirectDataType {
        ENM_DIRECT_OPERATE      = 0b10000000, 
        ENM_DIRECT_AXIS_TYPE    = 0b00000111, 
    };

    enum EnmDirectType {
        ENM_LEFT    = ENM_AXIS_SUB | ENM_AXIS_TYPE_X, 
        ENM_RIGHT   = ENM_AXIS_ADD | ENM_AXIS_TYPE_X, 
        ENM_UP      = ENM_AXIS_ADD | ENM_AXIS_TYPE_Y, 
        ENM_DOWN    = ENM_AXIS_SUB | ENM_AXIS_TYPE_Y, 
    };

    EnmDirectType enmDirectType;
    int32_t iStep;
};

class Pos {
//Type
public:
    using BasePosType = int32_t;
    using ConcatPosType = int64_t;
    
//Constant
public:
protected:
    
//Member Variables
protected:
    // x axis index of coordinate system
    BasePosType m_iAxisX;
    // y axis index of coordinate system
    BasePosType m_iAxisY;
    
//Static Member Variables
protected:
    
//Member Function
public:
    Pos(ConcatPosType oConcatPos) {
        auto oRes = split_pos( oConcatPos );
        m_iAxisX = oRes.first, m_iAxisY = oRes.second;
    }
    Pos(BasePosType x, BasePosType y) : m_iAxisX( x ), m_iAxisY( y ) {  }
    Pos() = default;
    explicit Pos( const Pos& ) = default;
    explicit Pos( Pos&& ) = default;
    ~Pos() = default;
    Pos& operator=( const Pos& ) = default;
    Pos& operator=( Pos&& ) = default;
    template<typename TPos>
    bool operator==( TPos&& oPos ) const noexcept { 
        return x() == oPos.x() && y() == oPos.y();
    }
    template<typename TPos>
    bool operator!=( TPos&& oPos ) const noexcept { 
        return !( *this == oPos );
    }

    ConcatPosType hash() const noexcept {
        return concat_pos( m_iAxisX, m_iAxisY );
    }

    BasePosType x() const noexcept { return m_iAxisX; }
    void set_x( BasePosType x ) { m_iAxisX = x; }
    void move_x( BasePosType step ) { set_x( std::max( x() + step, 0 ) ); }
    BasePosType y() const noexcept { return m_iAxisY; }
    void set_y( BasePosType y ) { m_iAxisY = y; }
    void move_y( BasePosType step ) { set_y( std::max( y() + step, 0 ) ); }
//Static Member Function
public:
    static inline auto concat_pos( BasePosType x, BasePosType y ) noexcept -> decltype( concat64( x, y ) ) {
        return concat64( x, y );
    }

    static inline auto split_pos( ConcatPosType pos ) noexcept -> decltype( split64( pos ) ) {
        return split64( pos );
    }
    
};

}

#endif

