if(KTX_FEATURE_UPLOAD)
    message(WARNING "KTX_UNITY_LIB does not support KTX_FEATURE_UPLOAD")
    return()
endif()

if(UNITY_PACKAGE_PATH)
    set( DEST_PLUGIN_PATH "${UNITY_PACKAGE_PATH}/Runtime/Plugins")

    if(ANDROID)
    set(UNITY_PLUGIN_DIR ${DEST_PLUGIN_PATH}/Android/libs/${ANDROID_ABI})
    elseif(IOS)
    set(UNITY_PLUGIN_DIR ${DEST_PLUGIN_PATH}/iOS)
    elseif(EMSCRIPTEN)
    set(UNITY_PLUGIN_DIR ${DEST_PLUGIN_PATH}/WebGL)
    else()
    if(bitness EQUAL 32)
    set(UNITY_PLUGIN_DIR ${DEST_PLUGIN_PATH}/x86)
    else()
    set(UNITY_PLUGIN_DIR ${DEST_PLUGIN_PATH}/x86_64)
    endif()
    endif()
    
    message(STATUS "Will install Unity native lib to ${UNITY_PLUGIN_DIR}")
    
    if( NOT EXISTS ${UNITY_PLUGIN_DIR})
        message(SEND_ERROR "Invalid Unity package path!")
    endif()
endif()

set(UNITY_TYPE MODULE)
if(IOS OR EMSCRIPTEN)
    set(UNITY_TYPE STATIC)
endif()

add_library(ktx_unity ${UNITY_TYPE}
    dummy.c
    $<TARGET_OBJECTS:ktx>
    $<TARGET_OBJECTS:obj_ktx_cbind>
)

target_include_directories(ktx_unity PUBLIC ${objKtxRead_include_dirs} ${basisu_include_dirs})

if(KTX_UNITY_LIB_BASISU)
    target_sources(ktx_unity PRIVATE $<TARGET_OBJECTS:obj_basisu_cbind>)
endif()

if(APPLE)
    set_target_properties(ktx_unity PROPERTIES BUNDLE true)
endif()

if(UNITY_PLUGIN_DIR)
    install(TARGETS ktx_unity DESTINATION ${UNITY_PLUGIN_DIR})
endif()
