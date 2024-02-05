/*
    > File Name: BaseDef.h
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年10月17日 星期一 11时19分42秒
*/

#ifndef __MACROFUNC_EDC__
#define __MACROFUNC_EDC__

/**
 * @description ASSERT_EXEC 
 * 若表达式的值为0, 则执行代码段execcode
 * if expression value is 0, will exec code segment 'execcode'
 *
 * @param expr
 * @param execcode
 *
 * @return 
 */
#define ASSERT_EXEC( expr, execcode ) { \
    if ( !( expr ) ) { \
        execcode; \
    } \
}

/**
 * @description ASSERT_RET 
 * 若表达式的值为0, 则返回val
 * if expression value is 0, return val
 *
 * @param expr
 * @param val
 *
 * @return 
 */
#define ASSERT_RET( expr, val ) ASSERT_EXEC( expr, return val )

/**
 * @description ASSERT_RET_NO_VAL
 * 若表达式的值为0, 则返回
 * if expression value is 0, function will return
 *
 * @param expr
 *
 * @return 
 */
#define ASSERT_RET_NO_VAL( expr ) ASSERT_EXEC( expr, return )

/**
 * @description ASSERT_BREAK
 * 若表达式的值为0, 则break
 * if expression value is 0, will break
 *
 * @param expr
 *
 * @return 
 */
#define ASSERT_BREAK( expr ) ASSERT_EXEC( expr, break )

/**
 * @description ASSERT_BREAK
 * 若表达式的值为0, 则continue
 * if expression value is 0, will continue
 *
 * @param expr
 *
 * @return 
 */
#define ASSERT_CONTINUE( expr ) ASSERT_EXEC( expr, continue )

/**
 * @description CHECK_NULL_RET 
 * 检测指针是否为空, 为空直接返回RetCode
 * If pointer is null, return RetCode
 *
 * @param Pointer
 *
 * @return 
 */
#define CHECK_NULL_RET( p, val ) ASSERT_RET( p, val )

/**
 * @description CHECK_NULL_RET_NO_VAL
 * 检测指针是否为空, 为空直接返回
 * If pointer is null, function will return
 *
 * @param Pointer
 *
 * @return 
 */
#define CHECK_NULL_RET_NO_VAL( p ) ASSERT_RET_NO_VAL( p )

/**
 * @description CHECK_NULL_BREAK
 * 检测指针是否为空, 为空则break
 * If pointer is null, will run break
 *
 * @param Pointer
 *
 * @return 
 */
#define CHECK_NULL_BREAK( p ) ASSERT_BREAK( p )

/**
 * @description CHECK_NULL_BREAK
 * 检测指针是否为空, 为空则continue
 * If pointer is null, will run continue
 *
 * @param Pointer
 *
 * @return 
 */
#define CHECK_NULL_CONTINUE( p ) ASSERT_CONTINUE( p )

/**
 * @description CHECK_NULL_BREAK
 * 将obj所在的内存块填充为0
 * Fill zero to memory of obj
 *
 * @param Obj
 *
 * @return 
 */
#define FILL_ZERO( obj ) { \
    static_assert( std::is_pod<obj> );\
    static_assert( !std::is_pointer<obj> );\
    memset( &obj, 0, sizeof(obj) ); \
}

#endif
