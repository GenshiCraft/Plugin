cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)

aux_source_directory(. SRC_LIST)

add_library(${CMAKE_PROJECT_NAME} SHARED ${SRC_LIST})

target_include_directories(
    ${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/third_party/sdk/include
)

target_compile_definitions(
    ${CMAKE_PROJECT_NAME} PRIVATE
    -D"NDEBUG"
    -D"NOMINMAX"
    -D"TEMPLATE_EXPORTS"
    -D"UNICODE"
    -D"WIN32_LEAN_AND_MEAN"
    -D"_AMD64_"
    -D"_CRT_SECURE_NO_WARNINGS"
    -D"_UNICODE"
    -D"_USRDLL"
    -D"_WINDLL"
    -D"_WINDOWS"
)

target_compile_options(
    ${CMAKE_PROJECT_NAME} PRIVATE
    /diagnostics:column
    /EHsc
    /FC
    /GL
    /MD
    /nologo
    /permissive-
    /sdl
    /utf-8
    /Zc:inline
    /Zi
)

target_link_options(
    ${CMAKE_PROJECT_NAME} PRIVATE
    /DEBUG
    /DELAYLOAD:"bedrock_server.dll"
    /DLL
    /IGNORE:4199
    /INCREMENTAL:NO
    /LTCG:INCREMENTAL
    /MANIFESTUAC:NO
    /MACHINE:X64
    /NOLOGO
    /OPT:ICF
    /OPT:REF
    /SUBSYSTEM:CONSOLE
)

target_link_libraries(
    ${CMAKE_PROJECT_NAME} PRIVATE
	${CMAKE_SOURCE_DIR}/third_party/sdk/lib/LiteLoader.lib
	${CMAKE_SOURCE_DIR}/third_party/sdk/lib/bedrock_server_api.lib
	${CMAKE_SOURCE_DIR}/third_party/sdk/lib/bedrock_server_var.lib
	${CMAKE_SOURCE_DIR}/third_party/sdk/lib/SymDBHelper.lib
)

add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} PRE_BUILD
    COMMAND cmd /c ${CMAKE_SOURCE_DIR}/tools/bin/generate_libraries.cmd ${CMAKE_SOURCE_DIR}
)
