
#ifndef CFS_OSGI_EDAC_RESULT_HPP
#define CFS_OSGI_EDAC_RESULT_HPP

#include <cfs/Config.hpp>

/*!
 * @brief  C++ Result<Type, Error> Rust's like.

 *
 * @code{cpp}
 *      Result<int> my_func1();
 *      Result<int> my_func2()
 *      {
 *          int i = TRY(my_func1());
 *          return i % 2;
 *      }
 * @encode
 */

#include <variant>
#include <iostream>
#include <functional>
#include <type_traits>
#include <exception>
#include <stdexcept>
#include <utility>

// https://doc.rust-lang.org/std/result/
namespace cfs
{
    namespace osgi
    {
        namespace edac
        {
            template < class T >
            struct CFSOkay
            {
                static_assert( !std::is_reference_v < T >, "cfs::osgi::edac::CFSOkay<T> cannot contain reference as T" );
                T data;
                explicit CFSOkay( T && t )
                    : data( std::forward < T > ( t ))
                {
                }
            };

            template < class T >
            struct CFSErr
            {
                static_assert( !std::is_reference_v < T >, "cfs::osgi::edac::CFSErr<T> cannot contain reference as T" );
                T data;
                explicit CFSErr( T && t )
                    : data( std::forward < T > ( t ))
                {
                }
            };

            template < class T >
            CFSOkay < T > Ok ( T && t )
            {
                static_assert( std::is_nothrow_move_constructible < T >::value, "cfs::osgi::edac::Ok<T> requires nothrow move constructor for T" );

                return ( CFSOkay < T > { std::move( t ) }
                         );
            }

            template < class T >
            CFSErr < T > Err ( T && t )
            {
                static_assert( std::is_nothrow_move_constructible < T >::value, "cfs::osgi::edac::Err<T> requires nothrow move constructor for T" );

                return ( CFSErr < T > { std::move( t ) }
                         );
            }

            template < typename R, typename E = std::exception >
            class Result
            {
                public:

                    using returnType = R;
                    using errorType = E;

                    Result();
                    Result( Result const & ) = delete;
                    Result( Result && ) = default;
                    Result & operator= ( Result const & ) = delete;
                    Result & operator= ( Result && ) = default;
                    virtual ~Result() = default;

                    Result( returnType && );
                    Result( returnType & );
                    Result( errorType && );

/*!
 *  @brief Check if the given Result contains a result.
 */
                    bool
                    isOk () const noexcept;
/*!
 *  @brief Check if the given Result contains an error.
 */
                    bool
                    isError () const noexcept;

                private:
            };
        }
    }
}

#endif
