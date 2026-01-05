
#pragma once

#include "ez_dirt_dsp.h"

#include "ez_parameter.h"

class processor : public ez::processor {
public:
    EZ_AUTOREG_PARAM(juce::AudioParameterFloat, gain    , 0.f, 100.f,  .5f);
    EZ_AUTOREG_PARAM(juce::AudioParameterFloat, volume  , 0.f,   2.f, 1.f);
    EZ_AUTOREG_PARAM(juce::AudioParameterInt  , hardness, 0  ,   3  , 0);

    processor()  {
        ez_parameter_init();
    } ////

    bool hasEditor() const override { return false; }
    juce::AudioProcessorEditor* createEditor() override { return nullptr; }

    void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) override {
        auto g = gain.get();
        auto v = volume.get();
        auto h = hardness.get();

        for(int channel_i = 0; channel_i < buffer.getNumChannels(); ++channel_i) {
            auto write = buffer.getWritePointer(channel_i);
            auto read  = buffer.getReadPointer (channel_i);

            for(int sample_i = 0; sample_i < buffer.getNumSamples(); ++sample_i) {
                write[sample_i] = v*clipping_funcs[h](g*read[sample_i]);
            }
        }
    }
};

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new processor();
}
