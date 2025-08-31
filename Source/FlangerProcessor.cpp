#include "FlangerProcessor.h"

FlangerProcessor::FlangerProcessor()
    : foleys::MagicProcessor (BusesProperties().withInput ("Input", juce::AudioChannelSet::stereo(), true)
                                               .withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
    vts (*this, nullptr, "PARAMS", { parameters.delay.release(),
                                     parameters.feedback.release(),
                                     parameters.flipFeedback.release(),
                                     parameters.shape.release(),
                                     parameters.sync.release(),
                                     parameters.rateFree.release(),
                                     parameters.rateSync.release(),
                                     parameters.depth.release(),
                                     parameters.offset.release(),
                                     parameters.cutoff.release(),
                                     parameters.output.release(),
                                     parameters.mix.release() }),
    flanger (parameters)
{
    magicState.setGuiValueTree (BinaryData::layout_xml, BinaryData::layout_xmlSize);
}

bool FlangerProcessor::isBusesLayoutSupported (const juce::AudioProcessor::BusesLayout& layouts) const
{
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;

    return true;
}

void FlangerProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    flanger.prepareToPlay (sampleRate, samplesPerBlock, getTotalNumOutputChannels());
}

void FlangerProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midi)
{
    juce::ScopedNoDenormals noDenormals;
    flanger.processBlock (buffer, midi, getPlayHead());
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FlangerProcessor();
}
