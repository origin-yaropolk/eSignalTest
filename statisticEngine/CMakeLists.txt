cmake_minimum_required(VERSION 3.2)
project(${StatisticEngineName})

set(StatisticEngineSourcesDir src)
set(StatisticEngineHeadersDir include)

aux_source_directory(${StatisticEngineSourcesDir} StatisticEngineSourcesList)
file(GLOB_RECURSE StatisticEngineHeadersList "include/*.h")

qt5_wrap_cpp(StatisticEngineHeadersMocList ${StatisticEngineFormsHeadersList})

list(REMOVE_ITEM StatisticEngineSourcesList src/stdafx.cpp)

add_msvc_precompiled_header("stdafx.h" "src/stdafx.cpp" StatisticEngineSourcesList)

source_group(
	"Generated Files" FILES 
	${StatisticEngineHeadersMocList} 
	${StatisticEngineFormsHeadersList}
)

source_group("Precompiled Headers" FILES include/stdafx.h src/stdafx.cpp)

add_library(
	${StatisticEngineName} 
	${StatisticEngineSourcesList}
	${StatisticEngineHeadersList}
	${StatisticEngineHeadersMocList}
	${StatisticEngineFormsHeadersList}
)

add_definitions(
	${QT_DEFINITIONS}
	-DQUAZIP_STATIC
)

if(MSVC)
	add_definitions(
		/EHsc
		/MP
		/permissive-
		/std:c++latest
		/Zi
		/W4
		/WX
	)
	
	set_target_properties(
		${StatisticEngineName}
		PROPERTIES COMPILE_FLAGS "/FI\"stdafx.h\""
		LINK_FLAGS /DEBUG
	)	
endif()

include_directories(
	${StatisticEngineHeadersDir}
	${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(
	${StatisticEngineName}
	Qt5::Core
)