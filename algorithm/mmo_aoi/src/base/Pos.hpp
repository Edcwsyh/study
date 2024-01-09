/******************************************************
  > File Name : Pos.hpp
  > Author : Edcwsyh
  > Create time : Fri Dec 29 10:47:52 2023
*******************************************************/

#ifndef __POS_HPP__
#define __POS_HPP__

#include <cstdint>
#include "ConcatNum.hpp"

namespace Edc {

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

    ConcatPosType hash() const noexcept {
        return concat_pos( m_iAxisX, m_iAxisY );
    }

    BasePosType x() const noexcept { return m_iAxisX; }
    void set_x( BasePosType x ) { m_iAxisX = x; }
    BasePosType y() const noexcept { return m_iAxisY; }
    void set_y( BasePosType y ) { m_iAxisY = y; }
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

