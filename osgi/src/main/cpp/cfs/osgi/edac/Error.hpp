
#ifndef CFS_OSGI_EDAC_ERROR_HPP
#define CFS_OSGI_EDAC_ERROR_HPP

#include <cerrno>
#include <cstdint>
#include <string>
#include <exception>
#include <experimental/system_error>
#include <vector>


/*
 * 
|        | Sev   |  Res  |   Serv   |      Mission  Defined      |                       Code                      |
|:------:|:-----:|:-----:|:--------:|:--------------------------:|:-----------------------------------------------:|
| Class  | 3  3  | 2  2  | 2  2  2  | 2  2  2  2  2  1  1  1  1  | 1  1  1  1  1  1  -  -  -  -  -  -  -  -  -  -  |
| Index  | 1  0  | 9  8  | 7  6  5  | 4  3  2  1  0  9  8  7  6  | 5  4  3  2  1  0  9  8  7  6  5  4  3  2  1  0  |
| Bits   | 32 31 | 30 29 | 28 27 26 | 25 24 23 22 21 20 19 18 17 | 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 |

|     |        ServiceID        |     |    |    Severity   |      |    |    Reserved   |
|:---:|:-----------------------:|     |----|:-------------:|      |----|:-------------:|
| 000 |    Not a cFE Service    |     | 00 |    Success    |      | 00 |    -------    |
| 001 |    Events Services      |     | 01 | Informational |      | 01 |    -------    |
| 010 |    Executive Services   |     | 10 |     Error     |      | 10 |    -------    |
| 011 |    File Services        |     | 11 |    Critical   |      | 11 |    -------    |
| 100 |    OS API Services      |
| 101 |    Software Bus Services|
| 110 |    Tables Services      |
| 111 |    Time Services        |

|           |                                      Mission,Defined                                     |
|:---------:|:----------------------------------------------------------------------------------------:|
| 000000000 | Used to classify error codes   related  to mission specific library function calls, etc. |

|                  |                                      Error codes                                         |
|:----------------:|:----------------------------------------------------------------------------------------:|
| 0000000000000000 | Used to classify error codes   related  to mission specific library function calls, etc. |
 
* 
* 
*/

#define CFS_DECLARE(type)           type
#define CFS_SUCCESS                 (0x00000000L)    //! no error.
#define CFE_SUCCESS                 (0x00000000L)    //! no error.
#define CFE_ERROR                  ~(0x00000000L)    //! no error.
/// Macro for generating bit masks using bit index from the spec
#define CFE_BIT_MASK(bit_index,field_bit_count) ( (1 << ((field_bit_count) - 1)) >> (bit_index) )

namespace cfs
{
    /*!
     * @brief Type for specifying an error or status code.
     */
    using cfs_status_t = int8_t;

    enum CfsError : std::uint32_t 
    {
        LARGE_VALUE = 0x0e000000UL
    };
//https://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
    enum class CfsErrorSeverity : std::uint32_t 
    {
        CFE_SEVERITY_BITMASK =      (0xc0000000L),
        CFE_SEVERITY_SUCCESS =      (0x00000000L),
        CFE_SEVERITY_INFO =         (0x40000000L),
        CFE_SEVERITY_ERROR =        (0xc0000000L)
    };

    enum class CfeServiceIdentifiers : std::uint32_t 
    {
        CFE_SERVICE_BITMASK =       (0x0e000000L),
        CFE_EVENTS_SERVICE =        (0x02000000L),
        CFE_EXECUTIVE_SERVICE =     (0x04000000L),
        CFE_FILE_SERVICE =          (0x06000000L),
        CFE_OSAPI_SERVICE =         (0x08000000L),
        CFE_SOFTWARE_BUS_SERVICE =  (0x0a000000L),
        CFE_TABLE_SERVICE =         (0x0c000000L),
        CFE_TIME_SERVICE =          (0x0e000000L)
    };

    enum class CfeOperationStatus : std::uint32_t 
    {
        STATUS_OK                    = 0, ///< Operation has completed successfully.
        STATUS_FAILURE               = 1, ///< Operation has failed for some undefined reason.

        STATUS_UNIMPLEMENTED         = 2, ///< Given operation has not been implemented.
        STATUS_INVALID_ARGUMENT      = 3, ///< An argument to the operation is invalid.
        STATUS_INVALID_STATE         = 4, ///< This operation is invalid for the current device state.
        STATUS_INVALID_COMMAND       = 5, ///< This command is not recognized.
        STATUS_INVALID_INTERFACE     = 6, ///< This interface is not supported.
        STATUS_INTERNAL_ERROR        = 7, ///< An internal runtime error has occured.
        STATUS_SECURITY_ERROR        = 8, ///< A security/authentication error has occured.
        STATUS_PARSE_ERROR           = 9, ///< A error has occured while parsing the command.
        STATUS_IN_PROGRESS           = 10, ///< This operation is in progress.
        STATUS_NOMEM                 = 11, ///< Operation prevented due to memory pressure.
        STATUS_BUSY                  = 12, ///< The device is currently performing a mutually exclusive operation
        STATUS_PROP_NOT_FOUND        = 13, ///< The given property is not recognized.
        STATUS_DROPPED               = 14, ///< A/The packet was dropped.
        STATUS_EMPTY                 = 15, ///< The result of the operation is empty.
        STATUS_CMD_TOO_BIG           = 16, ///< The command was too large to fit in the internal buffer.
        STATUS_NO_ACK                = 17, ///< The packet was not acknowledged.
        STATUS_CCA_FAILURE           = 18, ///< The packet was not sent due to a CCA failure.
        STATUS_ALREADY               = 19, ///< The operation is already in progress.
        STATUS_ITEM_NOT_FOUND        = 20, ///< The given item could not be found.
        STATUS_INVALID_COMMAND_FOR_PROP
                                     = 21, ///< The given command cannot be performed on this property.
    };

    namespace osgi
    {
        namespace edac
        {
            class Exception;

            class Error : public std::exception 
            {
            public:
                /*!
                * @brief Constructs a new error with null as its detail message.
                */
                Error() noexcept(false);
                /*!
                * @brief Constructs a new error with null as its detail message.
                */
                Error(std::string & message);
                /*!
                 * @brief Constructs a new error with the specified detail message and cause.
                */
                Error(std::string & message, int code)  noexcept(false);
                /*!
                 * @brief Constructs a new error with the specified detail message, cause, 
                 *        suppression enabled or disabled, and writable stack trace enabled or disabled.
                 * @param[in,out] message - The detail message.
                 * @param[in] enableSuppression  - Whether or not suppression is enabled or disabled.
                 * @param[in] writableStackTrace   - Whether or not the stack trace should be writable.
                 */
                Error(std::string & message, bool enableSuppression, bool writableStackTrace) noexcept(false);
                Error(const std::error_code code) noexcept;
                Error(const std::error_code code , const char * const what) noexcept;
                Error(const int code , const std::error_category & category) noexcept;
                Error(const int code) noexcept;
                Error(const int code , const std::error_category & category , const char * const what) noexcept;
                /*!
                 * @brief Destructor.
                */
                virtual ~Error() = default;

                /*!
                 * @brief Return a description of the error
                 * @return Pointer to a string containing the error message
                 */
                virtual const char* what() const throw();

                /*!
                 * @brief Return the error location (file + line + function)
                 * @return String containing the error location
                 */
                virtual const char* where() const throw();
                /*!
                 * @brief Receive notification of a warning.
                 */
                virtual void onWarning () = 0;
                /*!
                 * @brief Receive notification of a recoverable error(system is in error conditions).
                 */
                virtual void error () = 0;
                /*!
                 * @brief Receive notification of a non-recoverable error.
                 */
                virtual void fatalError () = 0;
                /*!
                 * @brief Receive notification of a critical conditions.
                 */
                virtual void criticalError () = 0;
                /*!
                 * @brief Receive notification that an action must be taken immediately.
                 */
                virtual void alertError () = 0;
                /*!
                 * @brief Receive notification that system is unusable.
                 */
                virtual void emergencyError () = 0;
                /*!
                 * @brief Called when a Exception (or a subclass) caused the thread to terminate.
                 */
                virtual void exception (const Exception & exc);
                /*!
                 * @brief Called when a std::exception (or a subclass) caused the thread to terminate.
                 */
                virtual void exception (const std::exception & exc);
                /*!
                 * @brief Invokes the currently registered Error.
                 */
                static void handle (const Exception & exc);
                /*!
                 * @brief Invokes the currently registered Error.
                 */
                static void handle (const std::exception & exc);
                /*!
                 * @brief Registers the given handler as the current error handler.
                 * @return The previously registered handler.
                 */
                static Error* set(Error* handler);
                /*!
                 * @brief Returns a pointer to the currently registered.
                 */
                static Error* get();
                
                void throw_error[[noreturn]]();
                void throw_error[[noreturn]](const char* origin, const char* format = nullptr, ...);
                void throw_error[[noreturn]](int code);
                void throw_error[[noreturn]](int code, const char* origin, const char* format = nullptr, ...);
                void throw_error[[noreturn]](int code, const char* origin, const char* format, va_list args);
            protected:
                /*!
                * @brief Returns the default Error handler.
                */
                static Error* defaultHandler();
                /*!
                 * @brief Utility function translating numeric error code to string.
                 */
                static std::string getErrorDescription(int errorCode);

            private:
                std::string m_message;  ///< Error message
                std::string m_location; ///< Location of the error (file, line and function)
                std::vector<std::pair<std::string , std::string> > errorProperties;
            };            
        }
    }
}

#endif

