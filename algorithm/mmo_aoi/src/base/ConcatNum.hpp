/******************************************************
  > File Name : ConcatNum.hpp
  > Author : Edcwsyh
  > Create time : Fri Dec 29 10:49:39 2023
*******************************************************/

#ifndef __CONCAT_NUM_HPP__
#define __CONCAT_NUM_HPP__

#include <cstdint>
#include <type_traits>
#include <utility>
namespace Edc{

namespace _hidden{

template <typename TUpSigned, typename TUpUnsigned, typename TBaseType>
inline auto concatnum( TBaseType high, TBaseType low ) noexcept -> std::conditional_t<std::is_signed_v<TBaseType>, TUpSigned, TUpUnsigned> {
    static_assert(std::is_integral_v<TBaseType>, "Unsupported base type");
    static_assert(std::is_integral_v<TUpUnsigned> && std::is_integral_v<TUpSigned>, "Unsupported uplevel type");
    static_assert(sizeof(TBaseType) * 2 == sizeof( TUpUnsigned ), "Base type no match up type");
    static_assert(sizeof( TUpSigned ) == sizeof( TUpUnsigned ), "Up type no in same level");

    using ResultType = std::conditional_t<std::is_signed_v<TBaseType>, TUpSigned, TUpUnsigned>;
    ResultType result = high;

    result <<= 8 * sizeof(TBaseType);

    result |= low;

    return result;
}

template <typename TDownSigned, typename TDownUnsigned, typename TBaseType>
inline auto splitnum( TBaseType concat_num) noexcept -> 
    std::conditional_t<std::is_signed_v<TBaseType>, 
        std::pair<TDownSigned, TDownSigned>, 
        std::pair<TDownUnsigned, TDownUnsigned> 
    > 
{
    static_assert(std::is_integral_v<TBaseType>, "Unsupported base type");
    static_assert(std::is_integral_v<TDownUnsigned> && std::is_integral_v<TDownSigned>, "Unsupported uplevel type");
    static_assert(sizeof(TDownSigned) * 2 == sizeof(TBaseType), "Base type no match down type");
    static_assert(sizeof(TDownSigned) == sizeof(TDownUnsigned), "Down type no in same level");

    return { concat_num >> 8 * sizeof( TDownSigned ), concat_num };
}

}

#define CONCATE_DEF( bit_num ) \
template<typename TBaseType> \
inline auto concat##bit_num( TBaseType high, TBaseType low ) noexcept -> decltype( _hidden::concatnum<int##bit_num##_t, uint##bit_num##_t>( high, low ) ) { return _hidden::concatnum<int##bit_num##_t, uint##bit_num##_t>( high, low ); }

CONCATE_DEF( 64 )
CONCATE_DEF( 32 )
CONCATE_DEF( 16 )

#undef CONCATE_DEF

#define SPLITNUM_DEF(bit_num, down_bit_num)  \
template<typename TBaseType> \
inline auto split##bit_num( TBaseType num ) noexcept -> decltype( _hidden::splitnum<int##down_bit_num##_t, uint##down_bit_num##_t>( num ) ) { return _hidden::splitnum<int##down_bit_num##_t, uint##down_bit_num##_t>( num ); }

SPLITNUM_DEF( 64, 32 )
SPLITNUM_DEF( 32, 16 )
SPLITNUM_DEF( 16, 8 )

#undef SPLITNUM_DEF
}

#endif

