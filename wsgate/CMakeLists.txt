# Default to release build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# set git revision
execute_process(COMMAND git describe --match initial --long
		COMMAND cut -d - -f2
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
		OUTPUT_VARIABLE GITREV
		ERROR_QUIET)

if(NOT GITREV)
	set(GITREV "Unknown")
endif()

# strip newline from GITREV
STRING(REGEX REPLACE "(\r?\n)+$" "" GITREV "${GITREV}")

set(BINDHELPER_LINK_FLAGS "-fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

if(GCC_ENABLE_WARNINGS)
    # set compiler warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wchar-subscripts")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wcomment")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wformat")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wformat-security")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-braces")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wparentheses")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wreturn-type")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wswitch")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wuninitialized")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wctor-dtor-privacy")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Woverloaded-virtual")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weffc++")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

set(USE_BFD True)

set(SRCS 
    base64.cpp 
    btexception.cpp 
    logging.cpp
    sha1.cpp
#	wsgate_main.cpp 
    RDP.cpp 
    Update.cpp 
    Primary.cpp
# 	myBindHelper.cpp 
#   myWsHandler.cpp 
#   myrawsocket.cpp
	wsendpoint.cpp 
#   wsgateEHS.cpp 
#   wshandler.cpp
	Png.cpp 
#   nova_token_auth.cpp

    lib_freerdp_helper.cpp  
    lib_wshandler.cpp
    
    libwsgate.cpp
  )

add_library( wsgate SHARED ${SRCS} )
target_link_libraries(wsgate freerdp2 winpr2 boost_system bfd)