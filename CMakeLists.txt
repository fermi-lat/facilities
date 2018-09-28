cmake_minimum_required(VERSION 3.11)
include(GNUInstallDirs)

project(facitlities
  VERSION 0.0.0
  LANGUAGES CXX
  )


###############################################################################
#
# facilities targets
#
###############################################################################

add_library(facilities STATIC
  src/ScheduledEvent.cxx
  src/Scheduler.cxx
  src/Timestamp.cxx
  src/Util.cxx
  src/commonUtilities.cxx
)
add_library(ST::facilities ALIAS facilities)
target_include_directories(facilities
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
target_compile_definitions(facilities PRIVATE HEADAS)

set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/facilities)

install(DIRECTORY facilities DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS facilities
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

install(TARGETS facilities
  EXPORT facilitiesTargets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

install(EXPORT facilitiesTargets
  NAMESPACE    ST::
  DESTINATION  ${INSTALL_CONFIGDIR}
  )

#Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/facilitiesConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/cmake/facilitiesConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/facilitiesConfig.cmake
  INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

install(
  FILES
  ${CMAKE_CURRENT_BINARY_DIR}/facilitiesConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/facilitiesConfigVersion.cmake
  DESTINATION ${INSTALL_CONFIGDIR}
)

export(EXPORT facilitiesTargets
  FILE ${CMAKE_CURRENT_BINARY_DIR}/facilitiesTargets.cmake
  NAMESPACE ST::
)

#Register package in user's package registry
export(PACKAGE facilities)

