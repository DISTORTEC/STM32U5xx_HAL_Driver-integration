/**
 * \file
 * \brief MSIRangeTable definition
 *
 * \author Copyright (C) 2024 Kamil Szczygiel https://distortec.com https://freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "stm32u5xx_hal.h"

/*---------------------------------------------------------------------------------------------------------------------+
| global objects
+---------------------------------------------------------------------------------------------------------------------*/

/// MSI ranges table
const uint32_t MSIRangeTable[16] {48000000, 24000000, 16000000, 12000000, 4000000, 2000000, 1330000, 1000000, 3072000,
		1536000, 1024000, 768000, 400000, 200000, 133000, 100000};
