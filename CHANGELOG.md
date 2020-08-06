Release Notes        {#relnotes}
=============

## Version 4.0.0-beta4

### Changes since v4.0.0-beta3 (by part)
### libktx

* Don't set dllexport outside libktx. (32a1a287) (msc-)

  Fixes export of default etc1s compression level global from DLL.
  Rename KTX_APICALL to KTX_API to reflect expanded usage.

* Require explicit setting of ktxBasisParams.compressionLevel. (46bdc7cc) (MarkCallow)

  Callers of CompressBasisEx() will have to be modified in light of the removal of
  the default value for this field.

  Fixes #287.

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Check support of enough levels & layers for format. (10ce7454) (MarkCallow)

* Return early on empty hashlist. (fc73f886) (MarkCallow)

  Fixes #113.

* Fix compile and Doxygen warnings. (2c40ba4d) (MarkCallow)



### Tools

* Don't set dllexport outside libktx. (32a1a287) (msc-)

  Fixes export of default etc1s compression level global from DLL.
  Rename KTX_APICALL to KTX_API to reflect expanded usage.

* Require explicit setting of ktxBasisParams.compressionLevel. (46bdc7cc) (MarkCallow)

  Callers of CompressBasisEx() will have to be modified in light of the removal of
  the default value for this field.

  Fixes #287.

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Check support of enough levels & layers for format. (10ce7454) (MarkCallow)

* Return early on empty hashlist. (fc73f886) (MarkCallow)

  Fixes #113.

* Fix compile and Doxygen warnings. (2c40ba4d) (MarkCallow)

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Fix more MSVS compile warnings. (e6cc8963) (MarkCallow)

* Support 16-bit and paletted images. (8283ea50) (MarkCallow)

  Fixes #252. Fixes #253. Fixes #255.

* Remove PreAllocator<> and std::vector hacks from ImageT (d1e1b8f7) (Arseny Kapoulkine)

  This change is necessary because the existing code crashes in MSVC 2019
  when debug iterators are enabled (in Debug) on Image destruction.

  This happens because Image<T> frees the backing store before destroying
  std::vector, and std::vector destructor accesses memory from the backing
  store as part of debug iterator code.

  The existing code seems error prone and unsafe for other reasons, and
  I'm not sure std::vector is justified here.

  The change removes std::vector and ImageTBase/ImageT distinction; ImageT
  now just uses a plain C array. resize()/crop() weren't used and are
  removed as a result to keep the change simpler.

* Fix assertion in MSVC Debug (cd62c227) (Arseny Kapoulkine)

  It's invalid to access pixels[0] when pixels has size==0. Since the
  functions are de-facto static we make them static instead.

* Derive toktx from scapp/ktxapp & capture sc args in metadata (#256) (67855d1e) (Mark Callow)

  Also
  
  * Add --no_multithreading on RDO users.
  
  * Ignore more possible build directories.

* Fix compile and Doxygen warnings. (2c40ba4d) (MarkCallow)



### Tests

* Don't set dllexport outside libktx. (32a1a287) (msc-)

  Fixes export of default etc1s compression level global from DLL.
  Rename KTX_APICALL to KTX_API to reflect expanded usage.

* Require explicit setting of ktxBasisParams.compressionLevel. (46bdc7cc) (MarkCallow)

  Callers of CompressBasisEx() will have to be modified in light of the removal of
  the default value for this field.

  Fixes #287.

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Check support of enough levels & layers for format. (10ce7454) (MarkCallow)

* Return early on empty hashlist. (fc73f886) (MarkCallow)

  Fixes #113.

* Fix compile and Doxygen warnings. (2c40ba4d) (MarkCallow)

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Fix more MSVS compile warnings. (e6cc8963) (MarkCallow)

* Support 16-bit and paletted images. (8283ea50) (MarkCallow)

  Fixes #252. Fixes #253. Fixes #255.

* Remove PreAllocator<> and std::vector hacks from ImageT (d1e1b8f7) (Arseny Kapoulkine)

  This change is necessary because the existing code crashes in MSVC 2019
  when debug iterators are enabled (in Debug) on Image destruction.

  This happens because Image<T> frees the backing store before destroying
  std::vector, and std::vector destructor accesses memory from the backing
  store as part of debug iterator code.

  The existing code seems error prone and unsafe for other reasons, and
  I'm not sure std::vector is justified here.

  The change removes std::vector and ImageTBase/ImageT distinction; ImageT
  now just uses a plain C array. resize()/crop() weren't used and are
  removed as a result to keep the change simpler.

* Fix assertion in MSVC Debug (cd62c227) (Arseny Kapoulkine)

  It's invalid to access pixels[0] when pixels has size==0. Since the
  functions are de-facto static we make them static instead.

* Derive toktx from scapp/ktxapp & capture sc args in metadata (#256) (67855d1e) (Mark Callow)

  Also
  
  * Add --no_multithreading on RDO users.
  
  * Ignore more possible build directories.

* Fix compile and Doxygen warnings. (2c40ba4d) (MarkCallow)

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Add Abort & Continue buttons to loadtests test loop error popups. (bb45e747) (MarkCallow)

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Check support of enough levels & layers for format. (10ce7454) (MarkCallow)

* Fix more MSVS compile warnings. (e6cc8963) (MarkCallow)

* Fix es3loadtests.html build. (#269) (72d16888) (Mark Callow)

  GLLoadTests.cpp was missing a -s DISABLE_EXCEPTION_CATCHING=0.
  Testimages were not being put into the virtual file system.
  
  Also includes:
  *  Make optimization flags global.
  *  Remove errant printf from GLLoadTests.cpp.

* Don't use TextureCubemap in web version. (eed98763) (MarkCallow)

  It needs a web version of libassimp.

* fixed macOS post build commands that copy ktx library into the app bundle (921197ba) (Andreas Atteneder)

* Support 16-bit and paletted images. (8283ea50) (MarkCallow)

  Fixes #252. Fixes #253. Fixes #255.

* Make loadtests usable as simple viewer (#261) (0ac74ffd) (Mark Callow)

  Not intended as a general viewer. Doesn't support 3d textures or cubemap arrays.

* Change name of scparams custom metadata item. (08ec113a) (MarkCallow)

* Derive toktx from scapp/ktxapp & capture sc args in metadata (#256) (67855d1e) (Mark Callow)

  Also
  
  * Add --no_multithreading on RDO users.
  
  * Ignore more possible build directories.

* Sign loadtests for iOS. (70785bbd) (MarkCallow)

* Link es tests with *only* the appropriate library. (4490c72e) (msc-)

* Define __IPHONEOS__. (5bc3c416) (MarkCallow)

* Explicitly include SDL_platform.h. (681e237b) (MarkCallow)

  Caught out again by Xcode's oh so helpful (not) search of all the include
  files in a project.

* Use COLOR_ATTACHMENT0 not BACK on iOS. (3cbba65c) (MarkCallow)



### JS Wrappers

* Don't set dllexport outside libktx. (32a1a287) (msc-)

  Fixes export of default etc1s compression level global from DLL.
  Rename KTX_APICALL to KTX_API to reflect expanded usage.

* Require explicit setting of ktxBasisParams.compressionLevel. (46bdc7cc) (MarkCallow)

  Callers of CompressBasisEx() will have to be modified in light of the removal of
  the default value for this field.

  Fixes #287.

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Check support of enough levels & layers for format. (10ce7454) (MarkCallow)

* Return early on empty hashlist. (fc73f886) (MarkCallow)

  Fixes #113.

* Fix compile and Doxygen warnings. (2c40ba4d) (MarkCallow)

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Fix more MSVS compile warnings. (e6cc8963) (MarkCallow)

* Support 16-bit and paletted images. (8283ea50) (MarkCallow)

  Fixes #252. Fixes #253. Fixes #255.

* Remove PreAllocator<> and std::vector hacks from ImageT (d1e1b8f7) (Arseny Kapoulkine)

  This change is necessary because the existing code crashes in MSVC 2019
  when debug iterators are enabled (in Debug) on Image destruction.

  This happens because Image<T> frees the backing store before destroying
  std::vector, and std::vector destructor accesses memory from the backing
  store as part of debug iterator code.

  The existing code seems error prone and unsafe for other reasons, and
  I'm not sure std::vector is justified here.

  The change removes std::vector and ImageTBase/ImageT distinction; ImageT
  now just uses a plain C array. resize()/crop() weren't used and are
  removed as a result to keep the change simpler.

* Fix assertion in MSVC Debug (cd62c227) (Arseny Kapoulkine)

  It's invalid to access pixels[0] when pixels has size==0. Since the
  functions are de-facto static we make them static instead.

* Derive toktx from scapp/ktxapp & capture sc args in metadata (#256) (67855d1e) (Mark Callow)

  Also
  
  * Add --no_multithreading on RDO users.
  
  * Ignore more possible build directories.

* Fix compile and Doxygen warnings. (2c40ba4d) (MarkCallow)

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Add Abort & Continue buttons to loadtests test loop error popups. (bb45e747) (MarkCallow)

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Check support of enough levels & layers for format. (10ce7454) (MarkCallow)

* Fix more MSVS compile warnings. (e6cc8963) (MarkCallow)

* Fix es3loadtests.html build. (#269) (72d16888) (Mark Callow)

  GLLoadTests.cpp was missing a -s DISABLE_EXCEPTION_CATCHING=0.
  Testimages were not being put into the virtual file system.
  
  Also includes:
  *  Make optimization flags global.
  *  Remove errant printf from GLLoadTests.cpp.

* Don't use TextureCubemap in web version. (eed98763) (MarkCallow)

  It needs a web version of libassimp.

* fixed macOS post build commands that copy ktx library into the app bundle (921197ba) (Andreas Atteneder)

* Support 16-bit and paletted images. (8283ea50) (MarkCallow)

  Fixes #252. Fixes #253. Fixes #255.

* Make loadtests usable as simple viewer (#261) (0ac74ffd) (Mark Callow)

  Not intended as a general viewer. Doesn't support 3d textures or cubemap arrays.

* Change name of scparams custom metadata item. (08ec113a) (MarkCallow)

* Derive toktx from scapp/ktxapp & capture sc args in metadata (#256) (67855d1e) (Mark Callow)

  Also
  
  * Add --no_multithreading on RDO users.
  
  * Ignore more possible build directories.

* Sign loadtests for iOS. (70785bbd) (MarkCallow)

* Link es tests with *only* the appropriate library. (4490c72e) (msc-)

* Define __IPHONEOS__. (5bc3c416) (MarkCallow)

* Explicitly include SDL_platform.h. (681e237b) (MarkCallow)

  Caught out again by Xcode's oh so helpful (not) search of all the include
  files in a project.

* Use COLOR_ATTACHMENT0 not BACK on iOS. (3cbba65c) (MarkCallow)

* Add missing BC7_RGBA enum. Deprecate others. (571973e5) (MarkCallow)

  Fixes #280.



### Build System

* Don't set dllexport outside libktx. (32a1a287) (msc-)

  Fixes export of default etc1s compression level global from DLL.
  Rename KTX_APICALL to KTX_API to reflect expanded usage.

* Require explicit setting of ktxBasisParams.compressionLevel. (46bdc7cc) (MarkCallow)

  Callers of CompressBasisEx() will have to be modified in light of the removal of
  the default value for this field.

  Fixes #287.

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Check support of enough levels & layers for format. (10ce7454) (MarkCallow)

* Return early on empty hashlist. (fc73f886) (MarkCallow)

  Fixes #113.

* Fix compile and Doxygen warnings. (2c40ba4d) (MarkCallow)

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Fix more MSVS compile warnings. (e6cc8963) (MarkCallow)

* Support 16-bit and paletted images. (8283ea50) (MarkCallow)

  Fixes #252. Fixes #253. Fixes #255.

* Remove PreAllocator<> and std::vector hacks from ImageT (d1e1b8f7) (Arseny Kapoulkine)

  This change is necessary because the existing code crashes in MSVC 2019
  when debug iterators are enabled (in Debug) on Image destruction.

  This happens because Image<T> frees the backing store before destroying
  std::vector, and std::vector destructor accesses memory from the backing
  store as part of debug iterator code.

  The existing code seems error prone and unsafe for other reasons, and
  I'm not sure std::vector is justified here.

  The change removes std::vector and ImageTBase/ImageT distinction; ImageT
  now just uses a plain C array. resize()/crop() weren't used and are
  removed as a result to keep the change simpler.

* Fix assertion in MSVC Debug (cd62c227) (Arseny Kapoulkine)

  It's invalid to access pixels[0] when pixels has size==0. Since the
  functions are de-facto static we make them static instead.

* Derive toktx from scapp/ktxapp & capture sc args in metadata (#256) (67855d1e) (Mark Callow)

  Also
  
  * Add --no_multithreading on RDO users.
  
  * Ignore more possible build directories.

* Fix compile and Doxygen warnings. (2c40ba4d) (MarkCallow)

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (MarkCallow)

  * All 4 options set by --qlevel now take precendence.
  * Use --threads 1 instead of --no_multithreading.

* Add Abort & Continue buttons to loadtests test loop error popups. (bb45e747) (MarkCallow)

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Check support of enough levels & layers for format. (10ce7454) (MarkCallow)

* Fix more MSVS compile warnings. (e6cc8963) (MarkCallow)

* Fix es3loadtests.html build. (#269) (72d16888) (Mark Callow)

  GLLoadTests.cpp was missing a -s DISABLE_EXCEPTION_CATCHING=0.
  Testimages were not being put into the virtual file system.
  
  Also includes:
  *  Make optimization flags global.
  *  Remove errant printf from GLLoadTests.cpp.

* Don't use TextureCubemap in web version. (eed98763) (MarkCallow)

  It needs a web version of libassimp.

* fixed macOS post build commands that copy ktx library into the app bundle (921197ba) (Andreas Atteneder)

* Support 16-bit and paletted images. (8283ea50) (MarkCallow)

  Fixes #252. Fixes #253. Fixes #255.

* Make loadtests usable as simple viewer (#261) (0ac74ffd) (Mark Callow)

  Not intended as a general viewer. Doesn't support 3d textures or cubemap arrays.

* Change name of scparams custom metadata item. (08ec113a) (MarkCallow)

* Derive toktx from scapp/ktxapp & capture sc args in metadata (#256) (67855d1e) (Mark Callow)

  Also
  
  * Add --no_multithreading on RDO users.
  
  * Ignore more possible build directories.

* Sign loadtests for iOS. (70785bbd) (MarkCallow)

* Link es tests with *only* the appropriate library. (4490c72e) (msc-)

* Define __IPHONEOS__. (5bc3c416) (MarkCallow)

* Explicitly include SDL_platform.h. (681e237b) (MarkCallow)

  Caught out again by Xcode's oh so helpful (not) search of all the include
  files in a project.

* Use COLOR_ATTACHMENT0 not BACK on iOS. (3cbba65c) (MarkCallow)

* Add missing BC7_RGBA enum. Deprecate others. (571973e5) (MarkCallow)

  Fixes #280.

* Don't set dllexport outside libktx. (32a1a287) (msc-)

  Fixes export of default etc1s compression level global from DLL.
  Rename KTX_APICALL to KTX_API to reflect expanded usage.

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (Mark Callow)

  This also:
  
  * Fixes a build issue in vkloadtests (InstancedSampleBase.cpp) on Windows that CI did not spot because it was in the middle an all target build.
  
  * Fixes a deeply hidden bug in tests/toktx_tests.cmake that caused ctest to not spot failed comparisons with the reference image.

* Fix: CMake build issues and dirty workarea after Appveyor build. (#274) (3957f116) (Mark Callow)

  * Don't run unix2dox on non-DOS. Remove SOURCE from custom targets.
  
  * fix(CMake): Bash is required by version.cmake and mkvk.cmake. Thus it needs to be detected before they are run in order to work upon initial configuration.
  
  * fix(CMake): corrected command logs
  
  * Change global core.autocrlf setting for Appveyor CI to match Git for Windows default.
  
  Co-authored-by: Andreas Atteneder <andreas.atteneder@gmail.com>

* Include BC7 & EAC_RG11 transcoders in wasm modules. (c7b58cd2) (MarkCallow)

  BC7 adds 66kb, EAC_RG11 4kb. There are WebGL extensions for these formats.

* Fix es3loadtests.html build. (#269) (72d16888) (Mark Callow)

  GLLoadTests.cpp was missing a -s DISABLE_EXCEPTION_CATCHING=0.
  Testimages were not being put into the virtual file system.
  
  Also includes:
  *  Make optimization flags global.
  *  Remove errant printf from GLLoadTests.cpp.

* Fix optimization flags and reduced emscripten size (#263) (a5e9fbaf) (Andreas Atteneder)

  * fixed CMake optimization flags
  
  * fix: Reduced emscripten build file size by not including unused functionality

* Export GL from module and pre-initialize GL context. (e77ab86e) (MarkCallow)

* fix(CMake): Copy results of emscripten builds to tests/webgl after build. (948e196a) (Andreas Atteneder)

* Sign loadtests for iOS. (70785bbd) (MarkCallow)



## Build System Changes since v4.0.0-beta3

