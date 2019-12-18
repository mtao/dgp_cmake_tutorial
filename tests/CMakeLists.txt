FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.9.1
)

# CMake 3.14+
FetchContent_GetProperties(catch)
if(NOT catch_POPULATED)
FetchContent_POPULATE(catch)
add_subdirectory(${catch_SOURCE_DIR} ${catch_BINARY_DIR})
endif()

include(CTest)

set(LANGS en fr es it zh)

add_custom_target(all_tests)

function(make_lang_test lang)
    set(TNAME ${lang}_test)

    add_executable(${TNAME} lang_test.cpp)
    add_test(NAME ${TNAME} COMMAND ${TNAME})
    target_compile_definitions(${TNAME} PUBLIC -DLANG_TEST_LANG=\"${lang}\")
    target_link_libraries(${TNAME} PUBLIC Catch2::Catch2 PUBLIC localization)
    add_dependencies(all_tests ${TNAME})
endfunction(make_lang_test)



foreach(MYLANG ${LANGS})
    make_lang_test(${MYLANG})
endforeach(MYLANG)


