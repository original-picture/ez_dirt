#pragma once

#include "ez_processor.h"

namespace ez {
    //==============================================================================
    class editor final : public juce::AudioProcessorEditor
    {
    public:
        explicit editor (juce::AudioProcessor&);
        ~editor() override;

        //==============================================================================
        void paint (juce::Graphics&) override;
        void resized() override;

    private:
        // This reference is provided as a quick way for your editor to
        // access the processor eated it.
        juce::AudioProcessor& processorRef;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (editor)
    };

}
