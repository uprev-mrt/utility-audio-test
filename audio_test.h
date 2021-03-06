/*
 * audio_test.h
 *
 *  Created on: Feb 4, 2020
 *      Author: jason Berger
 */

#ifndef AUDIO_TEST_H_
#define AUDIO_TEST_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "Utilities/Fifo/fifo.h"


/**
 * @brief Pushes sin wave into fifo
 * @param fifo ptr to fifo
 * @param freq freq of sin wave
 * @param sampleRate sample rate of audio
 * @param amp amplitude
 * @param len number of samples to push
 */
void audio_test_push_sin(fifo_t* fifo, float freq, int16_t amp, float sampleRate, int len);

/**
 * @brief Pushes stereo sin wave into fifo
 * @param fifo ptr to fifo
 * @param freq freq of sin wave
 * @param sampleRate sample rate of audio
 * @param amp amplitude
 * @param len number of samples to push
 */
void audio_test_push_sin_stereo(fifo_t* fifo, float freqa,float freqb, int16_t ampa, int16_t ampb,float sampleRate, int len);

/**
 * @brief pushed data from audio_test_clip into fifo
 * @param fifo ptr to fifo
 * @param len number of samples to push
 */
void audio_test_push_data(fifo_t* fifo, int len);

#ifdef __cplusplus
}
#endif



#endif /* AUDIO_TEST_H_ */
