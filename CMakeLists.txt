####################################
# Create target and set properties #
####################################

add_library(
  facilities SHARED
  src/Clock.cxx
  src/commonUtilities.cxx
  src/ScheduledEvent.cxx
  src/Scheduler.cxx
  src/Timestamp.cxx
  src/Util.cxx
  src/XGetopt.cxx
)

target_include_directories(
  facilities PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:>
)

###### Tests ######
add_executable(test_env src/test/test_env.cxx)
add_executable(test_time src/test/test_time.cxx)
add_executable(test_Util src/test/testUtil.cxx)

target_link_libraries(test_env PRIVATE facilities)
target_link_libraries(test_time PRIVATE facilities)
target_link_libraries(test_Util PRIVATE facilities)


### SWIG generates the python wrapper library
include(UseSWIG)

set_property(SOURCE src/py_facilities.i PROPERTY CPLUSPLUS ON)

swig_add_library(
  py_facilities
  TYPE SHARED
  LANGUAGE python
  SOURCES src/py_facilities.i
)

target_include_directories(
  py_facilities PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:>
)

target_link_libraries(py_facilities PUBLIC facilities Python3::Python)

###############################################################
# Installation
###############################################################
install(DIRECTORY facilities DESTINATION ${FERMI_INSTALL_INCLUDEDIR})
install(DIRECTORY python/ DESTINATION ${PYTHON_SITE_PKGDIR})

install(
  TARGETS facilities py_facilities
  EXPORT fermiTargets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
