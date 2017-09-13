# Levitics Arkhe Core Flight System Software

## Versioning

For transparency of our release cycle and in striving to maintain backward compatibility, **LACFSS** is maintained under [the Semantic Versioning guidelines](http://semver.org/) [![Semver](http://img.shields.io/SemVer/2.0.0.png)](http://semver.org/spec/v2.0.0.html). Sometimes we screw up, but we'll adhere to those rules whenever possible.

## Boards Suport Package

| Target Board     | Linux | Xenomai  | Linux RT | Nuttx | FreeRTOS | RTEMS | Picos18 |
|:----------------:|:-----:|----------|----------|:-----:|:--------:|:-----:|---------|
|   Fox Board G20  |       |          |          |       |          |       |         |
|  Fox Board LX832 |       |          |          |       |          |       |         |
|  Raspberry PI 2  |       |          |          |       |          |       |         |
|  RaspBerry PI 3  |       |          |          |       |          |       |         |
|      Pic32MZ     |       |          |          |       |          |       |         |
| ARM Cortex M4/M7 |       |          |          |       |          |       |         |
| Intel Edisson    |       |          |          |       |          |       |         |

## Host cros copilation

| Version/Architecture        | Build Status |
| --------------------------- | ------------ |
| Debian 8 - x86_64           | [![Build Status](https://ci.centos.org/buildStatus/icon?job=CentOS-Core-QA-t_functional-c7-64)](https://ci.centos.org/job/CentOS-Core-QA-t_functional-c7-64/) |
| Windows - x86_64            | [![Build Status](https://ci.centos.org/job/CentOS-Core-QA-t_functional-c6-64/badge/icon)](https://ci.centos.org/job/CentOS-Core-QA-t_functional-c6-64/) |
| Ubuntu core - x86_64        | [![Build Status](https://ci.centos.org/job/CentOS-Core-QA-t_functional-c6-32/badge/icon)](https://ci.centos.org/job/CentOS-Core-QA-t_functional-c6-32/) |
| IOS/MacOS - x86_64          | [![Build Status](https://ci.centos.org/job/CentOS-Core-QA-t_functional-c5-64/badge/icon)](https://ci.centos.org/job/CentOS-Core-QA-t_functional-c5-64/) |

## Status

| Branch              | Build status  |
|:------------------- |:------------- |
| master              | [![Build status](https://travis-ci.org/Levitics/levitics-arkhe-gcs.svg?branch=master "Build status of branch master")](https://travis-ci.org/Levitics/levitics-arkhe-gcs) |
| develop             | [![Build status](https://travis-ci.org/Levitics/levitics-arkhe-gcs.svg?branch=develop "Build status of branch develop")](https://travis-ci.org/Levitics/levitics-arkhe-gcs) |
| releases            | [![Build status](https://travis-ci.org/Levitics/levitics-arkhe-gcs.svg?branch=develop "Build status of branch develop")](https://travis-ci.org/Levitics/levitics-arkhe-gcs) |

## Binaries Distribution management
| Distribution  Chanel         | Description                                                                                                                                                                                   |
|------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [__Nightly__](#www.tbd.acme) | Builds created out of the central repository every night. These are not qualified by QA.                                                                                                      |
| [__Aurora__](#www.tbd.acme)  | Builds created out of the aurora repository, which is synced from mozilla-central every weeks.There is a small amount of QA at the start of the 1 week period before the updates are offered. |
| [__Beta__](#www.tbd.acme)    | Builds created out of the master repository, qualified by QA as being of sufficient quality to release to beta users.                                                                         |
| [__Release__](#www.tbd.acme) | Builds created out of the release repository, qualified by QA as being of sufficient quality to release to hundreds of millions of people.                                                    |

## Libraries Dependencies  and Installation Ubuntu/Debian

cucumber-cpp
    > sudo apt-get install libboost1.63-dev libboost1.63-all-dev libboost1.63-tools-dev
    > git clone https://github.com/cucumber/cucumber-cpp.git
    > cd cucumber-cpp
    > gem install bundler
    > bundle install
    > git submodule init
    > git submodule update
    > cmake -E chdir build cmake -DCUKE_ENABLE_EXAMPLES=on -DCMAKE_INSTALL_PREFIX=/usr/ ..
    > cmake --build build
    > cmake --build build --target test
    > cmake --build build --target features
    > cmake --build build --target install

googletest
    > git clone https://github.com/google/googletest.git
    > cd googletest
    > cmake -E chdir build cmake -DCMAKE_INSTALL_PREFIX=/usr/ ..
    > cmake --build build
    > cmake --build build --target install

microbenchmark 
    > git clone https://github.com/google/benchmark.git
    > cd benchmark
    > cmake -E chdir build cmake -DCMAKE_INSTALL_PREFIX=/usr/ ..
    > cmake --build build
    > cmake --build build --target install

## Contributions

Any contributions you make to this effort **are of course greatly appreciated**.


## Copyright and license

-	Code and documentation copyright 2011-2017 ACME SYSTEMS, Inc. 
-	Code released under [Apache License](LICENSE). 
-	Docs released under [Creative Commons](https://github.com/twbs/bootstrap/blob/master/docs/LICENSE). 

## Contact

*   [![Email](https://img.shields.io/badge/mailto-sabertazimi-brightgreen.svg?style=flat-square)](mailto:happyman@hotmail.fr)
*   [![GitHub](https://img.shields.io/badge/contact-github-000000.svg?style=flat-square)](https://github.com/doevelopper)
