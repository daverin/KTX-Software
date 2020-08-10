Release Notes
=============
## Version 4.0.0-beta4
### New Features

* `toktx` now supports 16-bit per component images as input for
Basis Universal encoding. Previously they could previously only be
used to create 16-bit format textures. It also supports using
paletted images as input. These will be expanded to RGB8 or RGBA8
depending on presence of alpha.

* The WASM modules for the libktx and msc_basis_transcoder JS
bindings now include the BC7 and ETC_RG11 transcoders.

### Notable Changes

* `CompressBasisEx` in `libktx` now requires explicit setting of
the `compressionLevel` in its `params` argument. To get the same
behavior as before callers should set this field to
`KTX_DEFAULT_ETC1S_COMPRESSION_LEVEL`.

### Known Issues

* Users making Basisu encoded or block compressed textures for WebGL
must be aware of WebGL restrictions with regard to texture size and
may need to resize images appropriately using the --resize feature of `toktx`.
In general the dimensions of block compressed textures must be a
multiple of the block size and, if `WEBGL_compressed_texture_s3tc` on WebGL 1.0 is expected to be
one of the targets, then the dimensions must be a power of 2.

* Basis Universal encoding results (both ETC1S/LZ and UASTC) are
non-deterministic across platforms. Results are valid but level
sizes and data will differ slightly.
See [issue #60](https://github.com/BinomialLLC/basis_universal/issues/60) in
the basis_universal repository.

* UASTC RDO results differ from run to run unless multi-threading
is disabled. As with the preceeding issue results are valid but
level sizes will differ slightly.
See [issue #151](https://github.com/BinomialLLC/basis_universal/issues/151)
in the basis_universal repository.
### Changes since v4.0.0-beta3 (by part)
### libktx

* Don't set dllexport outside libktx. (32a1a287) (@MarkCallow)

* Require explicit setting of ktxBasisParams.compressionLevel. (46bdc7cc) (@MarkCallow)

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (@MarkCallow)

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (@MarkCallow)

* Check support of enough levels & layers for format. (10ce7454) (@MarkCallow)

* Return early on empty hashlist. (fc73f886) (@MarkCallow)

* Fix compile and Doxygen warnings. (2c40ba4d) (@MarkCallow)
### Tools

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (@MarkCallow)

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (@MarkCallow)

* Fix more MSVS compile warnings. (e6cc8963) (@MarkCallow)

* Support 16-bit and paletted images. (8283ea50) (@MarkCallow)

* Remove PreAllocator<> and std::vector hacks from ImageT (d1e1b8f7) (@zeux)

* Fix assertion in MSVC Debug (cd62c227) (@zeux)

* Derive toktx from scapp/ktxapp & capture sc args in metadata (#256) (67855d1e) (@MarkCallow)

* Fix compile and Doxygen warnings. (2c40ba4d) (@MarkCallow)
### Tests

* Simplify --qlevel. Remove --no_multithreading. Fixes #275. (da5c204a) (@MarkCallow)

* Add Abort & Continue buttons to loadtests test loop error popups. (bb45e747) (@MarkCallow)

* Support PNG files with only gAMA and cHRM chunks. (#282) (0d851050) (@MarkCallow)

* Check support of enough levels & layers for format. (10ce7454) (@MarkCallow)

* Fix more MSVS compile warnings. (e6cc8963) (@MarkCallow)

* Fix es3loadtests.html build. (#269) (72d16888) (@MarkCallow)

* Don't use TextureCubemap in web version. (eed98763) (@MarkCallow)

* fixed macOS post build commands that copy ktx library into the app bundle (921197ba) (@atteneder)

* Support 16-bit and paletted images. (8283ea50) (@MarkCallow)

* Make loadtests usable as simple viewer (#261) (0ac74ffd) (@MarkCallow)

* Change name of scparams custom metadata item. (08ec113a) (@MarkCallow)

* Derive toktx from scapp/ktxapp & capture sc args in metadata (#256) (67855d1e) (@MarkCallow)

* Sign loadtests for iOS. (70785bbd) (@MarkCallow)

* Link es tests with *only* the appropriate library. (4490c72e) (@MarkCallow)

* Define __IPHONEOS__. (5bc3c416) (@MarkCallow)

* Explicitly include SDL_platform.h. (681e237b) (@MarkCallow)

* Use COLOR_ATTACHMENT0 not BACK on iOS. (3cbba65c) (@MarkCallow)
### JS Wrappers

* Add missing BC7_RGBA enum. Deprecate others. (571973e5) (@MarkCallow)

