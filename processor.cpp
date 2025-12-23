

#pragma once

#include "ez_parameter.h"

class processor : public ez::processor {
public:
    EZ_AUTOREG_PARAM(              juce::AudioParameterFloat , gain, 0.f, 1.f, .5f);
    EZ_AUTOREG_PARAM(ez::parameter<juce::AudioParameterFloat>, time, 0.f, 1.f, .5f);

    processor() {
        ez_parameter_init();
    } ////

    bool hasEditor() const override { return false; }
    juce::AudioProcessorEditor* createEditor() override { return nullptr; }

    void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) override {
        auto g = gain.get();
        for(unsigned channel_i = 0; channel_i < buffer.getNumChannels(); ++channel_i) {
            auto write = buffer.getWritePointer(channel_i);
            auto read  = buffer.getReadPointer (channel_i);

            for(unsigned sample_i = 0; sample_i < buffer.getNumSamples(); ++sample_i) {
                write[sample_i] = g*read[sample_i];
            }
        }
    }
};

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new processor();
}
