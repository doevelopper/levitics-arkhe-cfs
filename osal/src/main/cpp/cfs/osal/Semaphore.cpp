#include <cfs/osal/Semaphore.hpp>
//http://jean-luc.massat.perso.luminy.univ-amu.fr/ens/docs/thread-sem.html
using namespace cfs::osal;

Semaphore::Semaphore(sem_t semID)
: m_semaphoreId(semID)
{
    ::sem_init(&semID, 0, 1);
}

//Semaphore::~Semaphore()
//{
//    int status = sem_close(&m_semaphoreId);
//}

int Semaphore::wait(sem_t * semaphore)
{
    return (::sem_wait(&this->m_semaphoreId));
}

int Semaphore::trywait(sem_t * semaphore)
{
    return (::sem_trywait(&this->m_semaphoreId));
}

int Semaphore::post(sem_t * semaphore)
{
    return (::sem_post(&this->m_semaphoreId));
}

int Semaphore::getvalue(sem_t * semaphore, int * sval)
{
    return (::sem_getvalue(&this->m_semaphoreId,sval));
}

int Semaphore::destroy(sem_t * semaphore)
{
    return (::sem_destroy(&this->m_semaphoreId));
}