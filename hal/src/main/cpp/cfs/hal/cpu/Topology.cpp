#include <cfs/hal/cpu/Topology.hpp>

#include "Topology.hpp"

Topology::Topology() {
}

Topology::processorList const& 
Topology::processors() const 
{ 
    return (this->m_processors); 
}