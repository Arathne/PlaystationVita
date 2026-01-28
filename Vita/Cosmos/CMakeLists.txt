cmake_minimum_required(VERSION 3.23)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	if(DEFINED ENV{VITASDK})
		set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
	else()
		message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
	endif()
endif()

project(cosmos)

include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Cosmos")
set(VITA_TITLEID "ET0000020")
set(VITA_VERSION "01.00")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(path.cmake)
include_directories(include)

set(DATA_FOLDER "ux0:/data/cosmos")

add_executable(${PROJECT_NAME} ${SRC_FILES})

add_compile_definitions(
  DATA_FOLDER="${DATA_FOLDER}"
  TEMP_FILE="${DATA_FOLDER}/temp"
  #DEVELOPER_MODE
)

target_link_libraries(${PROJECT_NAME}
  vitaGL
  vitashark
  SceShaccCg_stub
  SceShaccCgExt
  taihen_stub
  SceGxm_stub
  SceAppMgr_stub
  SceDisplay_stub 
  SceCommonDialog_stub
  SceKernelDmacMgr_stub 
  mathneon
)

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME} UNSAFE)
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
)