cmake_minimum_required(VERSION 3.2)
project(${AppName})

set(AppSourcesDir src)
set(AppHeadersDir include)

# deps headers
set(StatisticEngineLibHeaderDir ../statisticEngine/include)

aux_source_directory(${AppSourcesDir} AppSourcesList)
file(GLOB_RECURSE AppCppList "src/*.cpp")
file(GLOB_RECURSE AppHeadersList "include/*.h")
file(GLOB_RECURSE AppFormsList "ui/*.ui")

qt5_wrap_ui(AppFormsHeadersList ${AppFormsList})
qt5_wrap_cpp(AppHeadersMocList ${AppFormsHeadersList})

list(REMOVE_ITEM AppSourcesList src/stdafx.cpp)

add_msvc_precompiled_header("stdafx.h" "src/stdafx.cpp" AppSourcesList)

source_group(
	"Generated Files" FILES 
	${AppHeadersMocList} 
	${AppFormsHeadersList}
)

source_group("Precompiled Headers" FILES include/stdafx.h src/stdafx.cpp)
source_group(Ui FILES ${AppFormsList})

if(WIN32)
	add_executable(
		${AppName} 
		${AppSourcesList}
		${AppHeadersList}
		${AppFormsList} 
		${AppFormsHeadersList}
		${AppHeadersMocList}
	)
else()
	add_executable(
		${AppName} 
		${AppSourcesList}
		${AppHeadersList}
		${AppFormsList} 
		${AppFormsHeadersList}
		${AppHeadersMocList}
	)
endif()

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
		${AppName}
		PROPERTIES COMPILE_FLAGS "/FI\"stdafx.h\""
	)
	
	set_target_properties(
		${AppName} 
		PROPERTIES WIN32_EXECUTABLE YES
		LINK_FLAGS "/DEBUG /ENTRY:mainCRTStartup"
	)
endif()

include_directories(
	${AppHeadersDir}
	${StatisticEngineLibHeaderDir}
	${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(
	${AppName}
	${StatisticEngineName}
	Qt5::Widgets
	Qt5::PrintSupport
)