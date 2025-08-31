#pragma once

#include <JuceHeader.h>

class FlangerProcessor : public foleys::MagicProcessor
{
public:
    FlangerProcessor();
    ~FlangerProcessor() override = default;

    bool isBusesLayoutSupported (const juce::AudioProcessor::BusesLayout& layouts) const override;
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    void releaseResources() override {}

private:
    cgo::Flanger::Params parameters;
    juce::AudioProcessorValueTreeState vts;
    cgo::Flanger flanger;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FlangerProcessor)
};
