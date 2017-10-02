
#ifndef CFS_HAL_RESOURCEUSAGE_HPP
#define CFS_HAL_RESOURCEUSAGE_HPP

#include <cfs/hal/ResourceLimit.hpp>

class ResourceUsage
{
    public:

        ResourceUsage();
        ResourceUsage( int );
        virtual ~ResourceUsage() = default;

        long maximumResidentSetSize () const;
        long sharingOfTextSegmentMemory () const;
        long dataSegmentMemoryUsed () const;
        long numberOfSoftPageFaults () const;
        long numberOfHardPageFaults () const;
        long timesAProcessWasSwapped () const;
        long numberOfInputOperationsViaTheFileSystem () const;
        long numberOfOutputOperationsViaTheFileSystem () const;
        long numberOfIPCMessagesSent () const;
        long numberOfIPCMessagesReceived () const;
        long numberOfSignalsDelivered () const;
        long numberOfVoluntaryContextSwitches () const;
        long numberOfInvoluntaryContextSwitches () const;
        long stackMemoryUsed () const;
        timeval amountOfUserTimeUsed () const;
        timeval amountOfSystemTimeUsed () const;

    private:

        int m_appUser;
        timeval m_tv;
        rusage m_rsrcUsage;
};

#endif
