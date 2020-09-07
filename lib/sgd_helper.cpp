// Copyright (c) 2019 Andreas Atteneder, All Rights Reserved.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//    http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include "ktx.h"
#include "ktxint.h"
#include "texture2.h"
#include "basis_sgd.h"
#include "basisu/transcoder/basisu_file_headers.h"

bool ktxTexture2_getHasAlpha(ktxTexture2* This) {
    ktxTexture2_private* priv = This->_private;
    uint8_t* bgd = priv->_supercompressionGlobalData;
    ktxBasisLzGlobalHeader* bgdh = (ktxBasisLzGlobalHeader*) bgd;
    return (basist::cBASISHeaderFlagHasAlphaSlices) != 0;
}
