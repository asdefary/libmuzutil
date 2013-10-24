cmake_minimum_required(VERSION 2.6)

project(muzutil)

FILE(GLOB SOURCES src/*.cc)

find_library(MUZDB muzdb)
find_library(BOOST_FS boost_filesystem)

add_library(muzutil SHARED ${SOURCES})
add_executable(muztdump example/muztdump.cc)

target_link_libraries(muzutil ${BOOST_FS} ${MUZDB})
target_link_libraries(muztdump muzutil)

set(MUZUTIL_VERSION_MAJOR "0")
set(MUZUTIL_VERSION_MINOR "0.1")

set_target_properties(muzutil PROPERTIES VERSION
	"${MUZUTIL_VERSION_MAJOR}.${MUZUTIL_VERSION_MINOR}")
set_target_properties(muzutil PROPERTIES SOVERSION ${MUZUTIL_VERSION_MAJOR})

INSTALL(FILES include/muzutil.hpp
	DESTINATION include)

INSTALL(DIRECTORY include/muzutil
	DESTINATION include)

INSTALL(TARGETS muzutil
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)

