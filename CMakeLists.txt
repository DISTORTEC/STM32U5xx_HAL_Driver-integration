#
# file: CMakeLists.txt
#
# This is the main CMakeLists.txt for STM32U5xx_HAL_Driver integration with distortos
#
# author: Copyright (C) 2020-2024 Kamil Szczygiel https://distortec.com https://freddiechopin.info
#
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
# distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#

cmake_minimum_required(VERSION 3.8)
project(STM32U5xx_HAL_Driver-integration)

if(NOT DEFINED STM32U5XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY)
	message(SEND_ERROR "Variable with path to STM32U5xx_HAL_Driver-configuration.h - "
			"STM32U5XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY - is not defined")
endif()
if(NOT IS_DIRECTORY "${STM32U5XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY}")
	message(SEND_ERROR "Path to STM32U5xx_HAL_Driver-configuration.h - "
			"STM32U5XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY = ${STM32U5XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY} - is "
			"not valid")
endif()
if(NOT EXISTS "${STM32U5XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY}/STM32U5xx_HAL_Driver-configuration.h")
	message(SEND_ERROR "Path to STM32U5xx_HAL_Driver-configuration.h - "
			"STM32U5XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY = ${STM32U5XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY} - does "
			"not contain STM32U5xx_HAL_Driver-configuration.h")
endif()

if(NOT DEFINED STM32U5XX_HAL_DRIVER_DIRECTORY)
	message(SEND_ERROR "Variable with path to STM32U5xx_HAL_Driver directory - STM32U5XX_HAL_DRIVER_DIRECTORY - is not "
			"defined")
endif()
if(NOT IS_DIRECTORY "${STM32U5XX_HAL_DRIVER_DIRECTORY}")
	message(SEND_ERROR "Path to STM32U5xx_HAL_Driver directory - "
			"STM32U5XX_HAL_DRIVER_DIRECTORY = ${STM32U5XX_HAL_DRIVER_DIRECTORY} - is not valid")
endif()
if(NOT EXISTS "${STM32U5XX_HAL_DRIVER_DIRECTORY}/Inc/stm32u5xx_hal.h")
	message(SEND_ERROR "Path to STM32U5xx_HAL_Driver directory - "
			"STM32U5XX_HAL_DRIVER_DIRECTORY = ${STM32U5XX_HAL_DRIVER_DIRECTORY} - does not contain Inc/stm32u5xx_hal.h")
endif()

if(STM32U5xx_HAL_Driver_ADC)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's ADC")
endif()

if(STM32U5xx_HAL_Driver_CORDIC)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's CORDIC")
endif()

if(STM32U5xx_HAL_Driver_DAC)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's DAC")
endif()

if(STM32U5xx_HAL_Driver_DCMI)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's DCMI")
endif()

if(STM32U5xx_HAL_Driver_FMAC)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's FMAC")
endif()

if(STM32U5xx_HAL_Driver_HASH)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's HASH")
endif()

if(STM32U5xx_HAL_Driver_LPTIM)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's LPTIM")
endif()

if(STM32U5xx_HAL_Driver_MDF)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's MDF")
endif()

if(STM32U5xx_HAL_Driver_MMC)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's MMC")
endif()

if(STM32U5xx_HAL_Driver_OSPI)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's OSPI")
endif()

if(STM32U5xx_HAL_Driver_SAI)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's SAI")
endif()

if(STM32U5xx_HAL_Driver_SPI)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's SPI")
endif()

if(STM32U5xx_HAL_Driver_SRAM)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's SRAM")
endif()

if(STM32U5xx_HAL_Driver_TIM)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's TIM")
endif()

if(STM32U5xx_HAL_Driver_XSPI)
	list(APPEND STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS "STM32U5xx_HAL_Driver's XSPI")
endif()

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_Full_LL_driver
		OFF
		HELP "Enable \"full\" LL driver."
		OUTPUT_NAME USE_FULL_LL_DRIVER)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_ADC
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's ADC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_COMP
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's COMP module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_CORDIC
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's CORDIC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_CRC
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's CRC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_CRYP
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's CRYP module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_DAC
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's DAC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_DCACHE
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's DCACHE module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_DCMI
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's DCMI module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_DMA
		OFF
		DEPENDENTS ${STM32U5XX_HAL_DRIVER_DMA_DEPENDENTS}
		HELP "Enable STM32U5xx_HAL_Driver's DMA module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_DMA2D
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's DMA2D module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_DSI
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's DSI module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_EXTI
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's EXTI module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_FDCAN
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's FDCAN module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_FMAC
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's FMAC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_GFXMMU
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's GFXMMU module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_GFXTIM
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's GFXTIM module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_GPU2D
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's GPU2D module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_GTZC
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's GTZC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_HASH
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's HASH module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_HCD
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's HCD module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_I2C
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's I2C module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_ICACHE
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's ICACHE module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_IRDA
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's IRDA module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_IWDG
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's IWDG module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_JPEG
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's JPEG module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_LPTIM
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's LPTIM module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_LTDC
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's LTDC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_MDF
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's MDF module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_MMC
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's MMC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_NAND
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's NAND module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_NOR
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's NOR module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_OPAMP
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's OPAMP module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_OSPI
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's OSPI module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_OTFDEC
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's OTFDEC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_PCD
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's PCD module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_PKA
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's PKA module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_PSSI
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's PSSI module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_RAMCFG
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's RAMCFG module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_RNG
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's RNG module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_RTC
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's RTC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_SAI
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's SAI module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_SD
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's SD module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_SDIO
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's SDIO module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_SMARTCARD
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's SMARTCARD module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_SMBUS
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's SMBUS module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_SPI
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's SPI module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_SRAM
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's SRAM module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_TIM
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's TIM module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_TSC
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's TSC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_UART
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's UART module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_USART
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's USART module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_WWDG
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's WWDG module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32U5xx_HAL_Driver_XSPI
		OFF
		HELP "Enable STM32U5xx_HAL_Driver's XSPI module."
		NO_OUTPUT)

message(STATUS "Generating ${CMAKE_CURRENT_BINARY_DIR}/include/stm32u5xx_hal_conf.h")
string(TIMESTAMP timestamp "%Y-%m-%d %H:%M:%S")
configure_file(stm32u5xx_hal_conf.h.in
		${CMAKE_CURRENT_BINARY_DIR}/include/stm32u5xx_hal_conf.h)

add_library(STM32U5xx_HAL_Driver STATIC
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_cortex.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_flash.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_flash_ex.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_gpio.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_pwr.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_pwr_ex.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_rcc.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_rcc_ex.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_adc.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_comp.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_cordic.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_crc.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_crs.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_dac.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_dlyb.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_dma.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_dma2d.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_exti.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_fmac.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_fmc.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_gpio.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_i2c.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_icache.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_lpgpio.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_lptim.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_lpuart.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_opamp.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_pka.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_pwr.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_rcc.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_rng.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_rtc.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_sdmmc.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_spi.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_tim.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_ucpd.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_usart.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_usb.c
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_ll_utils.c)
target_compile_options(STM32U5xx_HAL_Driver PRIVATE
		-Wno-unused-function)
target_include_directories(STM32U5xx_HAL_Driver BEFORE PUBLIC
		include)
target_include_directories(STM32U5xx_HAL_Driver PUBLIC
		${CMAKE_CURRENT_BINARY_DIR}/include
		${STM32U5XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY}
		${STM32U5XX_HAL_DRIVER_DIRECTORY}/Inc)
target_link_libraries(STM32U5xx_HAL_Driver PUBLIC
		distortos::distortos)

if(STM32U5xx_HAL_Driver_Full_LL_driver)
	target_compile_definitions(STM32U5xx_HAL_Driver PRIVATE
			USE_FULL_LL_DRIVER)
	target_compile_options(STM32U5xx_HAL_Driver PRIVATE
			-Wno-unused-parameter)
endif(STM32U5xx_HAL_Driver_Full_LL_driver)

if(STM32U5xx_HAL_Driver_ADC)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_adc.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_adc_ex.c)
endif(STM32U5xx_HAL_Driver_ADC)

if(STM32U5xx_HAL_Driver_COMP)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_comp.c)
endif(STM32U5xx_HAL_Driver_COMP)

if(STM32U5xx_HAL_Driver_CORDIC)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_cordic.c)
endif(STM32U5xx_HAL_Driver_CORDIC)

if(STM32U5xx_HAL_Driver_CRC)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_crc.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_crc_ex.c)
endif(STM32U5xx_HAL_Driver_CRC)

if(STM32U5xx_HAL_Driver_CRYP)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_cryp.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_cryp_ex.c)
endif(STM32U5xx_HAL_Driver_CRYP)

if(STM32U5xx_HAL_Driver_DAC)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_dac.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_dac_ex.c)
endif(STM32U5xx_HAL_Driver_DAC)

if(STM32U5xx_HAL_Driver_DCACHE)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_dcache.c)
endif(STM32U5xx_HAL_Driver_DCACHE)

if(STM32U5xx_HAL_Driver_DCMI)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_dcmi.c)
endif(STM32U5xx_HAL_Driver_DCMI)

if(STM32U5xx_HAL_Driver_DMA)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_dma.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_dma_ex.c)
endif(STM32U5xx_HAL_Driver_DMA)

if(STM32U5xx_HAL_Driver_DMA2D)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_dma2d.c)
endif(STM32U5xx_HAL_Driver_DMA2D)

if(STM32U5xx_HAL_Driver_DSI)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_dsi.c)
endif(STM32U5xx_HAL_Driver_DSI)

if(STM32U5xx_HAL_Driver_EXTI)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_exti.c)
endif(STM32U5xx_HAL_Driver_EXTI)

if(STM32U5xx_HAL_Driver_FDCAN)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_fdcan.c)
endif(STM32U5xx_HAL_Driver_FDCAN)

if(STM32U5xx_HAL_Driver_FMAC)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_fmac.c)
endif(STM32U5xx_HAL_Driver_FMAC)

if(STM32U5xx_HAL_Driver_GFXMMU)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_gfxmmu.c)
endif(STM32U5xx_HAL_Driver_GFXMMU)

if(STM32U5xx_HAL_Driver_GFXTIM)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_gfxtim.c)
endif(STM32U5xx_HAL_Driver_GFXTIM)

if(STM32U5xx_HAL_Driver_GPU2D)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_gpu2d.c)
endif(STM32U5xx_HAL_Driver_GPU2D)

if(STM32U5xx_HAL_Driver_GTZC)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_gtzc.c)
endif(STM32U5xx_HAL_Driver_GTZC)

if(STM32U5xx_HAL_Driver_HASH)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_hash.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_hash_ex.c)
endif(STM32U5xx_HAL_Driver_HASH)

if(STM32U5xx_HAL_Driver_HCD)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_hcd.c)
endif(STM32U5xx_HAL_Driver_HCD)

if(STM32U5xx_HAL_Driver_I2C)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_i2c.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_i2c_ex.c)
endif(STM32U5xx_HAL_Driver_I2C)

if(STM32U5xx_HAL_Driver_ICACHE)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_icache.c)
endif(STM32U5xx_HAL_Driver_ICACHE)

if(STM32U5xx_HAL_Driver_IRDA)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_irda.c)
endif(STM32U5xx_HAL_Driver_IRDA)

if(STM32U5xx_HAL_Driver_IWDG)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_iwdg.c)
endif(STM32U5xx_HAL_Driver_IWDG)

if(STM32U5xx_HAL_Driver_JPEG)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_jpeg.c)
endif(STM32U5xx_HAL_Driver_JPEG)

if(STM32U5xx_HAL_Driver_LPTIM)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_lptim.c)
endif(STM32U5xx_HAL_Driver_LPTIM)

if(STM32U5xx_HAL_Driver_LTDC)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_ltdc.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_ltdc_ex.c)
endif(STM32U5xx_HAL_Driver_LTDC)

if(STM32U5xx_HAL_Driver_MDF)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_mdf.c)
endif(STM32U5xx_HAL_Driver_MDF)

if(STM32U5xx_HAL_Driver_MMC)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_mmc.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_mmc_ex.c)
endif(STM32U5xx_HAL_Driver_MMC)

if(STM32U5xx_HAL_Driver_NAND)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_nand.c)
endif(STM32U5xx_HAL_Driver_NAND)

if(STM32U5xx_HAL_Driver_NOR)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_nor.c)
endif(STM32U5xx_HAL_Driver_NOR)

if(STM32U5xx_HAL_Driver_OPAMP)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_opamp.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_opamp_ex.c)
endif(STM32U5xx_HAL_Driver_OPAMP)

if(STM32U5xx_HAL_Driver_OSPI)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_ospi.c)
endif(STM32U5xx_HAL_Driver_OSPI)

if(STM32U5xx_HAL_Driver_OTFDEC)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_otfdec.c)
endif(STM32U5xx_HAL_Driver_OTFDEC)

if(STM32U5xx_HAL_Driver_PCD)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_pcd.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_pcd_ex.c)
endif(STM32U5xx_HAL_Driver_PCD)

if(STM32U5xx_HAL_Driver_PKA)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_pka.c)
endif(STM32U5xx_HAL_Driver_PKA)

if(STM32U5xx_HAL_Driver_PSSI)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_pssi.c)
endif(STM32U5xx_HAL_Driver_PSSI)

if(STM32U5xx_HAL_Driver_RAMCFG)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_ramcfg.c)
endif(STM32U5xx_HAL_Driver_RAMCFG)

if(STM32U5xx_HAL_Driver_RNG)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_rng.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_rng_ex.c)
endif(STM32U5xx_HAL_Driver_RNG)

if(STM32U5xx_HAL_Driver_RTC)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_rtc.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_rtc_ex.c)
endif(STM32U5xx_HAL_Driver_RTC)

if(STM32U5xx_HAL_Driver_SAI)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_sai.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_sai_ex.c)
endif(STM32U5xx_HAL_Driver_SAI)

if(STM32U5xx_HAL_Driver_SD)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_sd.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_sd_ex.c)
endif(STM32U5xx_HAL_Driver_SD)

if(STM32U5xx_HAL_Driver_SDIO)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_sdio.c)
endif(STM32U5xx_HAL_Driver_SDIO)

if(STM32U5xx_HAL_Driver_SMARTCARD)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_smartcard.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_smartcard_ex.c)
endif(STM32U5xx_HAL_Driver_SMARTCARD)

if(STM32U5xx_HAL_Driver_SMBUS)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_smbus.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_smbus_ex.c)
endif(STM32U5xx_HAL_Driver_SMBUS)

if(STM32U5xx_HAL_Driver_SPI)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_spi.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_spi_ex.c)
endif(STM32U5xx_HAL_Driver_SPI)

if(STM32U5xx_HAL_Driver_SRAM)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_sram.c)
endif(STM32U5xx_HAL_Driver_SRAM)

if(STM32U5xx_HAL_Driver_TIM)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_tim.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_tim_ex.c)
endif(STM32U5xx_HAL_Driver_TIM)

if(STM32U5xx_HAL_Driver_TSC)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_tsc.c)
endif(STM32U5xx_HAL_Driver_TSC)

if(STM32U5xx_HAL_Driver_UART)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_uart.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_uart_ex.c)
endif(STM32U5xx_HAL_Driver_UART)

if(STM32U5xx_HAL_Driver_USART)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_usart.c
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_usart_ex.c)
endif(STM32U5xx_HAL_Driver_USART)

if(STM32U5xx_HAL_Driver_WWDG)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_wwdg.c)
endif(STM32U5xx_HAL_Driver_WWDG)

if(STM32U5xx_HAL_Driver_XSPI)
	target_sources(STM32U5xx_HAL_Driver PRIVATE
			${STM32U5XX_HAL_DRIVER_DIRECTORY}/Src/stm32u5xx_hal_xspi.c)
endif(STM32U5xx_HAL_Driver_XSPI)

add_library(STM32U5xx_HAL_Driver-object-library OBJECT
		APBPrescTable.cpp
		HAL_Delay.cpp
		HAL_GetTick.cpp
		MSIRangeTable.cpp
		SystemCoreClock.cpp)
target_include_directories(STM32U5xx_HAL_Driver-object-library PRIVATE
		$<TARGET_PROPERTY:STM32U5xx_HAL_Driver,INTERFACE_INCLUDE_DIRECTORIES>)

target_sources(STM32U5xx_HAL_Driver INTERFACE
		$<TARGET_OBJECTS:STM32U5xx_HAL_Driver-object-library>)
