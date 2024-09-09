/**
 * \file
 * \brief HAL_GetTick() definition
 *
 * \author Copyright (C) 2019-2024 Kamil Szczygiel https://distortec.com https://freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "stm32u5xx_hal.h"

#include "distortos/TickClock.hpp"

/*---------------------------------------------------------------------------------------------------------------------+
| global functions
+---------------------------------------------------------------------------------------------------------------------*/

/**
 * \brief Get current time.
 *
 * \return current time, milliseconds
 */

extern "C" uint32_t HAL_GetTick()
{
	return std::chrono::milliseconds{distortos::TickClock::now().time_since_epoch()}.count();
}
