/***************************************************************************//**
 *   @file   ad9361_api.h
 *   @brief  Header file of AD9361 API Driver.
 *   @author DBogdan (dragos.bogdan@analog.com)
********************************************************************************
 * Copyright 2013(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/
#ifndef AD9361_API_H_
#define AD9361_API_H_

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/
#include "no_os_port.h"

/******************************************************************************/
/*************************** Types Declarations *******************************/
/******************************************************************************/
typedef struct
{
	/* Mode Setup */
	uint8_t		two_rx_two_tx_mode_enable;
	uint8_t		frequency_division_duplex_mode_enable;
	uint8_t		split_gain_table_mode_enable;
	uint8_t		tdd_use_fdd_vco_tables_enable;
	uint8_t		tdd_use_dual_synth_mode_enable;
	uint32_t	dcxo_coarse_and_fine_tune[2];
	uint8_t		ensm_enable_pin_pulse_mode_enable;
	uint8_t		ensm_enable_txnrx_control_enable;
	uint32_t	rx_rf_port_input_select;
	uint32_t	tx_rf_port_output_select;
	uint32_t	rx_path_clock_frequencies[6];
	uint32_t	tx_path_clock_frequencies[6];
	uint64_t	rx_synthesizer_frequency_hz;
	uint64_t	tx_synthesizer_frequency_hz;
	uint32_t	rf_rx_bandwidth_hz;
	uint32_t	rf_tx_bandwidth_hz;
	uint8_t		update_tx_gain_in_alert_enable;
	int32_t		tx_attenuation_mdB;
	/* Gain Control */
	uint8_t		gc_rx1_mode;
	uint8_t		gc_rx2_mode;
	uint8_t		gc_adc_ovr_sample_size;
	uint8_t		gc_adc_small_overload_thresh;
	uint8_t		gc_adc_large_overload_thresh;
	uint16_t	gc_lmt_overload_high_thresh;
	uint16_t	gc_lmt_overload_low_thresh;
	uint8_t		gc_analog_settling_time;
	uint16_t	gc_dec_pow_measurement_duration;
	uint8_t		gc_low_power_thresh;
	uint8_t		gc_dig_gain_enable;
	uint8_t		gc_max_dig_gain;
	/* Manual Gain Control Setup */
	uint8_t		mgc_rx1_ctrl_inp_enable;
	uint8_t		mgc_rx2_ctrl_inp_enable;
	uint8_t		mgc_inc_gain_step;
	uint8_t		mgc_dec_gain_step;
	uint8_t		mgc_split_table_ctrl_inp_gain_mode;
	/* Automatic Gain Control Setup */
	uint8_t		agc_attack_delay_us;
	uint8_t		agc_settling_delay;
	uint8_t		agc_outer_thresh_high;
	uint8_t		agc_outer_thresh_high_dec_steps;
	uint8_t		agc_inner_thresh_high;
	uint8_t		agc_inner_thresh_high_dec_steps;
	uint8_t		agc_inner_thresh_low;
	uint8_t		agc_inner_thresh_low_inc_steps;
	uint8_t		agc_outer_thresh_low;
	uint8_t		agc_outer_thresh_low_inc_steps;
	uint8_t		agc_adc_small_overload_exceed_counter;
	uint8_t		agc_adc_large_overload_exceed_counter;
	uint8_t		agc_adc_large_overload_inc_steps;
	uint8_t		agc_adc_lmt_small_overload_prevent_gain_inc_enable;
	uint8_t		agc_lmt_overload_large_exceed_counter;
	uint8_t		agc_lmt_overload_small_exceed_counter;
	uint8_t		agc_lmt_overload_large_inc_steps;
	uint8_t		agc_dig_saturation_exceed_counter;
	uint8_t		agc_dig_gain_step_size;
	uint8_t		agc_sync_for_gain_counter_enable;
	uint32_t	agc_gain_update_counter;
	uint8_t		agc_immed_gain_change_if_large_adc_overload_enable;
	uint8_t		agc_immed_gain_change_if_large_lmt_overload_enable;
	/* RSSI */
	uint8_t		rssi_restart_mode;
	uint8_t		rssi_unit_is_rx_samples_enable;
	uint32_t	rssi_delay;
	uint32_t	rssi_wait;
	uint32_t	rssi_duration;
	/* Control Outputs */
	uint8_t		ctrl_outs_index;
	uint8_t		ctrl_outs_enable_mask;
	/* AuxADC Temp Sense Control */
	uint16_t	temp_sense_measurement_interval_ms;
	int8_t		temp_sense_offset_signed;
	uint8_t		temp_sense_periodic_measurement_enable;
}AD9361_InitParam;

typedef struct
{
	uint32_t rx;
	int32_t rx_gain;
	uint32_t rx_dec;
	int16_t rx_coef[64];
}AD9361_RXFIRConfig;

typedef struct
{
	uint32_t tx;
	int32_t tx_gain;
	uint32_t tx_int;
	int16_t tx_coef[64];
}AD9361_TXFIRConfig;

/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/
struct ad9361_rf_phy *ad9361_init (AD9361_InitParam *init_param);
int32_t ad9361_set_en_state_machine_mode (struct ad9361_rf_phy *phy, uint32_t mode);
int32_t ad9361_get_en_state_machine_mode (struct ad9361_rf_phy *phy, uint32_t *mode);
int32_t ad9361_set_rx_rf_gain (struct ad9361_rf_phy *phy, uint8_t ch, int32_t gain_db);
int32_t ad9361_get_rx_rf_gain (struct ad9361_rf_phy *phy, uint8_t ch, int32_t *gain_db);
int32_t ad9361_set_rx_rf_bandwidth (struct ad9361_rf_phy *phy, uint32_t bandwidth_hz);
int32_t ad9361_get_rx_rf_bandwidth (struct ad9361_rf_phy *phy, uint32_t *bandwidth_hz);
int32_t ad9361_set_rx_sampling_freq (struct ad9361_rf_phy *phy, uint32_t sampling_freq_hz);
int32_t ad9361_get_rx_sampling_freq (struct ad9361_rf_phy *phy, uint32_t *sampling_freq_hz);
int32_t ad9361_set_rx_lo_freq (struct ad9361_rf_phy *phy, uint64_t lo_freq_hz);
int32_t ad9361_get_rx_lo_freq (struct ad9361_rf_phy *phy, uint64_t *lo_freq_hz);
int32_t ad9361_get_rx_rssi (struct ad9361_rf_phy *phy, uint8_t ch, struct rf_rssi *rssi);
int32_t ad9361_set_rx_gain_control_mode (struct ad9361_rf_phy *phy, uint8_t ch, uint8_t gc_mode);
int32_t ad9361_get_rx_gain_control_mode (struct ad9361_rf_phy *phy, uint8_t ch, uint8_t *gc_mode);
int32_t ad9361_set_rx_fir_config (struct ad9361_rf_phy *phy, AD9361_RXFIRConfig fir_cfg);
int32_t ad9361_set_rx_fir_en_dis (struct ad9361_rf_phy *phy, uint8_t en_dis);
int32_t ad9361_get_rx_fir_en_dis (struct ad9361_rf_phy *phy, uint8_t *en_dis);
int32_t ad9361_set_tx_attenuation (struct ad9361_rf_phy *phy, uint8_t ch, uint32_t attenuation_mdb);
int32_t ad9361_get_tx_attenuation (struct ad9361_rf_phy *phy, uint8_t ch, uint32_t *attenuation_mdb);
int32_t ad9361_set_tx_rf_bandwidth (struct ad9361_rf_phy *phy, uint32_t  bandwidth_hz);
int32_t ad9361_get_tx_rf_bandwidth (struct ad9361_rf_phy *phy, uint32_t *bandwidth_hz);
int32_t ad9361_set_tx_sampling_freq (struct ad9361_rf_phy *phy, uint32_t sampling_freq_hz);
int32_t ad9361_get_tx_sampling_freq (struct ad9361_rf_phy *phy, uint32_t *sampling_freq_hz);
int32_t ad9361_set_tx_lo_freq (struct ad9361_rf_phy *phy, uint64_t lo_freq_hz);
int32_t ad9361_get_tx_lo_freq (struct ad9361_rf_phy *phy, uint64_t *lo_freq_hz);
int32_t ad9361_set_tx_fir_config (struct ad9361_rf_phy *phy, AD9361_TXFIRConfig fir_cfg);
int32_t ad9361_set_tx_fir_en_dis (struct ad9361_rf_phy *phy, uint8_t en_dis);
int32_t ad9361_get_tx_fir_en_dis (struct ad9361_rf_phy *phy, uint8_t *en_dis);

#endif
