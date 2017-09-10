#ifndef CFS_OSAL_SEMAPHORE_HPP
#define CFS_OSAL_SEMAPHORE_HPP

#include <cstdio> 
#include <cstdlib>
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h>

namespace cfs
{
    namespace osal
    {
        class Semaphore 
        {
        public:
            Semaphore(sem_t semID);
            virtual ~Semaphore() = default;
            
            int wait(sem_t * semaphore);
            int trywait(sem_t * semaphore);
            int post(sem_t * semaphore);
            int getvalue(sem_t * semaphore, int * sval);
            int destroy(sem_t * semaphore);
        private:
            sem_t m_semaphoreId;
        };        
    }
}
#endif

