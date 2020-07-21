Release Notes        {#relnotes}
=============

## Version 4.0.0-beta4

### New Features

* `toktx` now supports 16-bit per component images as input for Basis Universal
encoding. Previously they could previously only be used to create 16-bit format
textures. It also supports using paletted images as input. These will be expanded
to RGB8 or RGBA8 depending on presence of alpha.

* The WASM modules for the libktx and msc_basis_transcoder JS bindings now include
the BC7 and ETC_RG11 transcoders.

### Known Issues

* Users making Basisu encoded or block compressed textures for WebGL must be
aware of WebGL restrictions with regard to texture size and may need to
resize images appropriately --resize feature of `toktx`. In general the dimensions
of block compressed textures must be a multiple of the block size and, if
`WEBGL_compressed_texture_s3tc` is expected to be one of the targets, then the
dimensions must be a power of 2.

### Changes since v4.0.0-beta3 (by part)
### libktx

##### Check support of enough levels & layers for format.
commit 10ce7454 @n
Author: MarkCallow github@callow.im



--
##### Return early on empty hashlist.
commit fc73f886 @n
Author: MarkCallow github@callow.im

Fixes #113.


--
##### Fix compile and Doxygen warnings.
commit 2c40ba4d @n
Author: MarkCallow github@callow.im

### Tools

##### Fix more MSVS compile warnings.
commit e6cc8963 @n
Author: MarkCallow github@callow.im



--
##### Support 16-bit and paletted images.
commit 8283ea50 @n
Author: MarkCallow github@callow.im

Fixes #252. Fixes #253. Fixes #255.


--
##### Remove PreAllocator<> and std::vector hacks from ImageT
commit d1e1b8f7 @n
Author: Arseny Kapoulkine arseny.kapoulkine@gmail.com

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


--
##### Fix assertion in MSVC Debug
commit cd62c227 @n
Author: Arseny Kapoulkine arseny.kapoulkine@gmail.com

It's invalid to access pixels[0] when pixels has size==0. Since the
functions are de-facto static we make them static instead.


--
##### Derive toktx from scapp/ktxapp & capture sc args in metadata (#256)
commit 67855d1e @n
Author: Mark Callow 2244683+MarkCallow@users.noreply.github.com

Also

* Add --no_multithreading on RDO users.

* Ignore more possible build directories.

--
##### Fix compile and Doxygen warnings.
commit 2c40ba4d @n
Author: MarkCallow github@callow.im

### Tests

##### Check support of enough levels & layers for format.
commit 10ce7454 @n
Author: MarkCallow github@callow.im



--
##### Fix more MSVS compile warnings.
commit e6cc8963 @n
Author: MarkCallow github@callow.im



--
##### Fix es3loadtests.html build. (#269)
commit 72d16888 @n
Author: Mark Callow 2244683+MarkCallow@users.noreply.github.com

GLLoadTests.cpp was missing a -s DISABLE_EXCEPTION_CATCHING=0.
Testimages were not being put into the virtual file system.

Also includes:
*  Make optimization flags global.
*  Remove errant printf from GLLoadTests.cpp.


--
##### Don't use TextureCubemap in web version.
commit eed98763 @n
Author: MarkCallow github@callow.im

It needs a web version of libassimp.


--
##### fixed macOS post build commands that copy ktx library into the app bundle
commit 921197ba @n
Author: Andreas Atteneder andreas.atteneder@gmail.com



--
##### Support 16-bit and paletted images.
commit 8283ea50 @n
Author: MarkCallow github@callow.im

Fixes #252. Fixes #253. Fixes #255.


--
##### Make loadtests usable as simple viewer (#261)
commit 0ac74ffd @n
Author: Mark Callow 2244683+MarkCallow@users.noreply.github.com

Not intended as a general viewer. Doesn't support 3d textures or cubemap arrays.

--
##### Change name of scparams custom metadata item.
commit 08ec113a @n
Author: MarkCallow github@callow.im



--
##### Derive toktx from scapp/ktxapp & capture sc args in metadata (#256)
commit 67855d1e @n
Author: Mark Callow 2244683+MarkCallow@users.noreply.github.com

Also

* Add --no_multithreading on RDO users.

* Ignore more possible build directories.

--
##### Sign loadtests for iOS.
commit 70785bbd @n
Author: MarkCallow github@callow.im



--
##### Link es tests with *only* the appropriate library.
commit 4490c72e @n
Author: msc- github@callow.im



--
##### Define __IPHONEOS__.
commit 5bc3c416 @n
Author: MarkCallow github@callow.im



--
##### Explicitly include SDL_platform.h.
commit 681e237b @n
Author: MarkCallow github@callow.im

Caught out again by Xcode's oh so helpful (not) search of all the include
files in a project.


--
##### Use COLOR_ATTACHMENT0 not BACK on iOS.
commit 3cbba65c @n
Author: MarkCallow github@callow.im

