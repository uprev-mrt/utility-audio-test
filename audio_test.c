/**
 * @file audio_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Utilities/Audio/TestData/audio_test.h"
#include "audio_test_data.h"
#include <math.h>

void audio_test_push_sin(fifo_t* fifo, float freq, float sampleRate, int len)
{
    static float idx =0;

    int16_t val;
    
    for(int i=0; i < len; i++)
    {
     val = sin((freq * (2 * 3.14159) * idx) / sampleRate);

     fifo_push(fifo, &val);
    }
    

}

void audio_test_push_data(fifo_t* fifo, int len)
{
    static int idx = 0;
    static uint16_t* data = (uint16_t*)audio_test_clip;

    for(int i=0; i < len; i++)
    {
        fifo_push(fifo, &data[idx++]);

        if(idx == AUDIO_TEST_CLIP_LEN)
        {
            idx =0;
        }
    }

}