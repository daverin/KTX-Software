add_library(obj_basisu_cbind OBJECT
    src/basisu_c_binding.cpp
    )

if(KTX_UNITY_LIB_BASISU)
    target_compile_definitions(
        obj_basisu_cbind
        PRIVATE
        KTX_BASISU_C_BINDINGS
        )
endif()

get_property(objKtxRead_include_dirs TARGET ktx PROPERTY INCLUDE_DIRECTORIES)
get_property(basisu_include_dirs TARGET ktx PROPERTY INCLUDE_DIRECTORIES)

target_include_directories(
    obj_basisu_cbind
    PUBLIC
    inc
    PRIVATE
    ${objKtxRead_include_dirs}
    ${basisu_include_dirs}
    )

add_library(obj_ktx_cbind OBJECT
    src/ktx_c_binding.cpp
    )

target_include_directories(
    obj_ktx_cbind
    PRIVATE
    ${objKtxRead_include_dirs}
    )

if(WIN32)
    target_compile_definitions(
        obj_basisu_cbind
        PRIVATE
        DLL_EXPORT_FLAG
        )
    target_compile_definitions(
        obj_ktx_cbind
        PRIVATE
        DLL_EXPORT_FLAG
        )
endif()
