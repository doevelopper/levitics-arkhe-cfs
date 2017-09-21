# Levitics Arkhe Core Flight System Software

## Links

* [Web site](http://www.tbd.acme/)
* [Project forums](http://services.tbd.acme/)
* [Wiki, docs and manuals](http://documentations.tbd.acme/)
* [Bug and issue tracker](http://defects.tbd.acme/)
* [Project build server](http://cicd.tbd.acme/)
* [Repository browser](http://code.tbd.acmeg/)
* [Read/write git repository](ssh://git@code.tbd.acme)
* [Read-only official mirror](https://github.com/doevelopper/levitics-arkhe-cfs)
* [Toolchain downloads](http://downloads.tbd.acme)

## Versioning

For transparency of our release cycle and in striving to maintain backward compatibility, **LACFSS** is maintained under the Semantic Versioning guidelines [![Semver](http://img.shields.io/SemVer/2.0.0.png)](http://semver.org/spec/v2.0.0.html). Sometimes we screw up, but we'll adhere to those rules whenever possible.

## Code Review
Here are some resources to learn more about
code reviews:

* <a href="https://blog.scottnonnenberg.com/top-ten-pull-request-review-mistakes/">Top 10 Pull Request Review Mistakes</a>
* <a href="https://smartbear.com/SmartBear/media/pdfs/best-kept-secrets-of-peer-code-review.pdf">Best Kept Secrets of Peer Code Review (pdf)</a>
* <a href="http://support.smartbear.com/support/media/resources/cc/11_Best_Practices_for_Peer_Code_Review.pdf">11 Best Practices for Peer Code Review (pdf)</a>
* <a href="http://www.evoketechnologies.com/blog/code-review-checklist-perform-effective-code-reviews/">Code Review Checklist – To Perform Effective Code Reviews</a>
* <a href="https://www.codeproject.com/Articles/524235/Codeplusreviewplusguidelines">Code review guidelines</a>
* <a href="https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md">C++ Core Guidelines</a>
* <a href="https://doc.lagout.org/programmation/C/CPP101.pdf">C++ Coding Standards (Sutter & Andrescu)</a>


## Boards Suport Package

| Target Board     | Linux | Xenomai  | Linux RT | Nuttx | FreeRTOS | RTEMS | Picos18 |
|:----------------:|:-----:|----------|----------|:-----:|:--------:|:-----:|---------|
|   Qemu arm-x64   |  [ ]  |     [ ]  |     [ ]  |  [ ]  |     [ ]  |  [ ]  |    [ ]  |
|   Fox Board G20  |  [ ]  |     [ ]  |     [ ]  |  [ ]  |     [ ]  |  [ ]  |    [ ]  |
|  Fox Board LX832 |  [ ]  |     [ ]  |     [ ]  |  [ ]  |     [ ]  |  [ ]  |    [ ]  |
|  Raspberry PI 2  |  [ ]  |     [ ]  |     [ ]  |  [ ]  |     [ ]  |  [ ]  |    [ ]  |
|  RaspBerry PI 3  |  [ ]  |     [ ]  |     [ ]  |  [ ]  |     [ ]  |  [ ]  |    [ ]  |
|      Pic32MZ     |  [ ]  |     [ ]  |     [ ]  |  [ ]  |     [ ]  |  [ ]  |    [ ]  |
|  STM32 Discovery |  [ ]  |     [ ]  |     [ ]  |  [ ]  |     [ ]  |  [ ]  |    [ ]  |
| ARM Cortex M4/M7 |  [ ]  |     [ ]  |     [ ]  |  [ ]  |     [ ]  |  [ ]  |    [ ]  |
| Intel Edisson    |  [ ]  |     [ ]  |     [ ]  |  [ ]  |     [ ]  |  [ ]  |    [ ]  |

## Host cross copilation

Branch      | Linux/OSX | Windows | Coverage | Documentation | Test |
------------|-----------|---------|----------|---------------|--------|
[master](https://github.com/doevelopper/levitics-arkhe-cfs/tree/master)   | [![Build Status](https://travis-ci.org/Levitics/levitics-arkhe-gcs.svg?branch=master "Build status of branch master")](https://travis-ci.org/Levitics/levitics-arkhe-gcs)  | [![Build status](https://ci.appveyor.com/api/projects/status/g0llpbvhpjuxjnlw/branch/master?svg=true)](https://ci.appveyor.com/project/vinniefalco/beast/branch/master)   | [![codecov](https://codecov.io/gh/boostorg/Beast/branch/master/graph/badge.svg)](https://codecov.io/gh/boostorg/beast/branch/master)   | [![Documentation](https://img.shields.io/badge/documentation-master-brightgreen.svg)](http://www.boost.org/doc/libs/master/libs/beast/doc/html/beast.html)  | [![Matrix](https://img.shields.io/badge/matrix-master-brightgreen.svg)](http://www.boost.org/development/tests/master/developer/beast.html)
[develop](https://github.com/doevelopper/levitics-arkhe-cfs/tree/develop) | [![Build Status](https://travis-ci.org/Levitics/levitics-arkhe-gcs.svg?branch=develop "Build status of branch develop")](https://travis-ci.org/Levitics/levitics-arkhe-gcs) | [![Build status](https://ci.appveyor.com/api/projects/status/g0llpbvhpjuxjnlw/branch/develop?svg=true)](https://ci.appveyor.com/project/vinniefalco/beast/branch/develop) | [![codecov](https://codecov.io/gh/boostorg/Beast/branch/develop/graph/badge.svg)](https://codecov.io/gh/boostorg/beast/branch/develop) | [![Documentation](https://img.shields.io/badge/documentation-develop-brightgreen.svg)](http://www.boost.org/doc/libs/develop/libs/beast/) | [![Matrix](https://img.shields.io/badge/matrix-develop-brightgreen.svg)](http://www.boost.org/development/tests/develop/developer/beast.html)
[releases](https://github.com/doevelopper/levitics-arkhe-cfs/tree/releases) | [![Build Status](https://travis-ci.org/Levitics/levitics-arkhe-gcs.svg?branch=releases "Build status of branch releases")](https://travis-ci.org/Levitics/levitics-arkhe-gcs) | [![Build status](https://ci.appveyor.com/api/projects/status/g0llpbvhpjuxjnlw/branch/develop?svg=true)](https://ci.appveyor.com/project/vinniefalco/beast/branch/releases) | [![codecov](https://codecov.io/gh/boostorg/Beast/branch/develop/graph/badge.svg)](https://codecov.io/gh/boostorg/beast/branch/releases) | [![Documentation](https://img.shields.io/badge/documentation-develop-brightgreen.svg)](http://www.boost.org/doc/libs/develop/libs/beast/) | [![Matrix](https://img.shields.io/badge/matrix-develop-brightgreen.svg)](http://www.boost.org/development/tests/develop/developer/beast.html)

## Binaries Distribution management
| Distribution  Chanel         | Description                                                                                                                                                                                   |
|------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [__Nightly__](#www.tbd.acme) | Builds created out of the central repository every night, packaged up every night for bleeding-edge testers to install and test.These are not qualified by QA.                                                                                                      |
| [__Aurora__](#www.tbd.acme)  | Builds created out of the aurora repository, which is synced from central repository every weeks.There is a small amount of QA at the start of the 1 week period before the updates are offered.as such its status is roughly "experimental".  |
| [__Beta__](#www.tbd.acme)    | Builds created out of the master repository, qualified by QA as being of sufficient quality to release to beta users.                                                                         |
| [__Release__](#www.tbd.acme) | Builds created out of the release repository, qualified by QA as being of sufficient quality to release to hundreds of millions of people.                                                    |

## Libraries Dependencies  and Installation Ubuntu/Debian
![Dependencies](https://img.shields.io/badge/dependencies-up%20to%20date-brightgreen.svg)

> * _Build tools_

```sh
    # Intall boost libraries
    $ sudo apt-get install libboost1.63-dev libboost1.63-all-dev libboost1.63-tools-dev
    $ sudo apt-get install
    # Intall make and cmake 3.8 or later
    $ sudo apt-get install  make cmake  cmake-extra cmake-data 
```

* _D-Bus_
>
> [dbus interprocess messaging system](https://dbus.freedesktop.org/releases/dbus/dbus-1.10.22.tar.gz) `[sudo] apt-get install libdbus-cpp-dev/libdbus-cpp5/ libdbusmenu-jsonloader-dev`


* _cucumber-cpp_

```sh
    $ git clone https://github.com/cucumber/cucumber-cpp.git
    $ cd cucumber-cpp
    $ gem install bundler
    $ bundle install
    $ git submodule init
    $ git submodule update
    $ cmake -E chdir build cmake -DCUKE_ENABLE_EXAMPLES=on -DCMAKE_INSTALL_PREFIX=/usr/ ..
    $ cmake --build build
    $ cmake --build build --target test
    $ cmake --build build --target features
    $ cmake --build build --target install
```

* _googletest_

```sh
    $ git clone https://github.com/google/googletest.git
    $ cd googletest
    $ cmake -E chdir build cmake -DCMAKE_INSTALL_PREFIX=/usr/ ..
    $ cmake --build build
    $ cmake --build build --target install
```

* _microbenchmark_

```sh
    $ git clone https://github.com/google/benchmark.git
    $ cd benchmark
    $ cmake -E chdir build cmake -DCMAKE_INSTALL_PREFIX=/usr/ ..
    $ cmake --build build
    $ cmake --build build --target install
```

* _Style and coverage_ [![XO code style](https://img.shields.io/badge/code_style-XO-5ed9c7.svg)](https://github.com/google/styleguide)
>
> [Automated C++ style guide checker](https://pypi.python.org/pypi/cpplint). `[sudo] pip install cpplint`
>
> [Cyclomatic Complexity Analyzer](https://pypi.python.org/pypi/lizard) `[sudo] pip install lizard`
>
> [Source Code Beautifier](http://uncrustify.sourceforge.net) `[sudo] apt-get install Uncrustify`
>
> [Static analysis tool ](http://uncrustify.sourceforge.net) `[sudo] apt-get install  cppcheck`
>
> [Converts cpplint output to JUnit format.](https://pypi.python.org/pypi/cpplint-junit) `[sudo] apt-get install/--upgrade  cpplint-junit`


## Contributions

Any contributions you make to this effort **are of course greatly appreciated**.
![Contributions welcome](https://img.shields.io/badge/contributions-welcome-orange.svg)
### Copyright Notice and License

© 2011-2017 ACME SYSTEMS, Inc.All Rights Reserved.

No Warranty: THE SUBJECT SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY OF ANY KIND, EITHER EXPRESSED, IMPLIED, OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, ANY WARRANTY THAT THE SUBJECT SOFTWARE WILL CONFORM TO SPECIFICATIONS, ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR FREEDOM FROM INFRINGEMENT, ANY WARRANTY THAT THE SUBJECT SOFTWARE WILL BE ERROR FREE, OR ANY WARRANTY THAT DOCUMENTATION, IF PROVIDED, WILL CONFORM TO THE SUBJECT SOFTWARE. THIS AGREEMENT DOES NOT, IN ANY MANNER, CONSTITUTE AN ENDORSEMENT BY GOVERNMENT AGENCY OR ANY PRIOR RECIPIENT OF ANY RESULTS, RESULTING DESIGNS, HARDWARE, SOFTWARE PRODUCTS OR ANY OTHER APPLICATIONS RESULTING FROM USE OF THE SUBJECT SOFTWARE.  FURTHER, GOVERNMENT AGENCY DISCLAIMS ALL WARRANTIES AND LIABILITIES REGARDING THIRD-PARTY SOFTWARE, IF PRESENT IN THE ORIGINAL SOFTWARE, AND DISTRIBUTES IT "AS IS."

Waiver and Indemnity: RECIPIENT AGREES TO WAIVE ANY AND ALL CLAIMS AGAINST THE UNITED STATES GOVERNMENT, ITS CONTRACTORS AND SUBCONTRACTORS, AS WELL AS ANY PRIOR RECIPIENT.  IF RECIPIENT'S USE OF THE SUBJECT SOFTWARE RESULTS IN ANY LIABILITIES, DEMANDS, DAMAGES, EXPENSES OR LOSSES ARISING FROM SUCH USE, INCLUDING ANY DAMAGES FROM PRODUCTS BASED ON, OR RESULTING FROM, RECIPIENT'S USE OF THE SUBJECT SOFTWARE, RECIPIENT SHALL INDEMNIFY AND HOLD HARMLESS THE UNITED STATES GOVERNMENT, ITS CONTRACTORS AND SUBCONTRACTORS, AS WELL AS ANY PRIOR RECIPIENT, TO THE EXTENT PERMITTED BY LAW.  RECIPIENT'S SOLE REMEDY FOR ANY SUCH MATTER SHALL BE THE IMMEDIATE, UNILATERAL TERMINATION OF THIS AGREEMENT.

- Code and documentation copyright 2011-2017 ACME SYSTEMS, Inc. 
- Code released under [Apache License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)(https://opensource.org/licenses/Apache-2.0). 
- Docs released under [Creative Commons](https://github.com/twbs/bootstrap/blob/master/docs/LICENSE). 
- [![License: LGPL v3](https://img.shields.io/badge/License-LGPL%20v3-blue.svg)](http://www.gnu.org/licenses/lgpl-3.0)  
- [![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png)](https://creativecommons.org/publicdomain/zero/1.0/)
### Contact

* [![Email](https://img.shields.io/badge/mailto-sabertazimi-brightgreen.svg?style=flat-square)](mailto:happyman@hotmail.fr)
* [![GitHub](https://img.shields.io/badge/contact-github-000000.svg?style=flat-square)](https://github.com/doevelopper)

---

> [tbd.acme](https://www.tbd.acme) &nbsp;&middot;&nbsp;
> GitHub [@doevelopper](https://github.com/doevelopper) &nbsp;&middot;&nbsp;
> Twitter [@doevelopper](https://twitter.com/doevelopper)