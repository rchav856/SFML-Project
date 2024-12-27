# Install script for directory: C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/flac-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/rchav/source/repos/SFML-Project/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FLAC/targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FLAC/targets.cmake"
         "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/flac-build/CMakeFiles/Export/baf7b64a9c1b56d368d1c4c52c93ff8a/targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FLAC/targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FLAC/targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FLAC" TYPE FILE FILES "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/flac-build/CMakeFiles/Export/baf7b64a9c1b56d368d1c4c52c93ff8a/targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FLAC" TYPE FILE FILES "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/flac-build/CMakeFiles/Export/baf7b64a9c1b56d368d1c4c52c93ff8a/targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FLAC" TYPE FILE FILES
    "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/flac-build/flac-config.cmake"
    "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/flac-build/flac-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FLAC" TYPE FILE FILES
    "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/flac-build/flac-config.cmake"
    "C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/flac-build/flac-config-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/flac-build/src/cmake_install.cmake")
  include("C:/Users/rchav/source/repos/SFML-Project/out/build/x64-Debug/_deps/flac-build/microbench/cmake_install.cmake")

endif()
