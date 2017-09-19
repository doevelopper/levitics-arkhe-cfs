#ifndef CFS_OSAL_SEMAPHORE_HPP
#define CFS_OSAL_SEMAPHORE_HPP

#include <cstdio> 
#include <cstdlib>
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h>
#include <system_error>

namespace cfs
{
    namespace osal
    {
        class Semaphore 
        {
        public:
            Semaphore(sem_t semID);
            virtual ~Semaphore() = default;

            /*!
             * @brief Trys to get the semaphore, blocking
             *        Takes the semaphore by decreasing the counter by 1, will wait for the semaphore
             *        to be given if the counter = 0.
             */            
            int wait(sem_t * semaphore);
            /*!
             * @brief Trys to get the semaphore, non-blocking
             *        Takes the semaphore by decreasing the counter by 1, will return if the counter = 0.
             * @return bool false if semaphore was empty, true if semaphore was successfully acquired
            */
            int trywait(sem_t * semaphore);
            int post(sem_t * semaphore);
            int getvalue(sem_t * semaphore, int * sval);
            int destroy(sem_t * semaphore);
            /*!
            *  @brief Increases the semaphore by 1 
            */
            void post(); 
        private:
            Semaphore(const Semaphore& arg);/*!< Copy constructor made inaccessible by declaring it private */
            Semaphore& operator=(const Semaphore& rhs);/*!< Assignment constructor made inaccessible by declaring it private */
            sem_t m_semaphoreId; /*!< Internal semaphore handler */
        };        
    }
}
#endif

