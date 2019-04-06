#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <iostream>
using namespace std;

//==============================================================================
Proj1AudioProcessor::Proj1AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

Proj1AudioProcessor::~Proj1AudioProcessor()
{
}

//==============================================================================
const String Proj1AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Proj1AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Proj1AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Proj1AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Proj1AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Proj1AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Proj1AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Proj1AudioProcessor::setCurrentProgram (int index)
{
}

const String Proj1AudioProcessor::getProgramName (int index)
{
    return {};
}

void Proj1AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Proj1AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void Proj1AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Proj1AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Proj1AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i) {
        buffer.clear(i, 0, buffer.getNumSamples());
    }

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        averageWave = (averageWave + *channelData) / 2;
        *channelData = averageWave;
        if (*channelData > topLimit) {
            *channelData = topLimit;
        }
        if (*channelData < lowLimit) {
            *channelData = lowLimit;
        }
        if (*channelData < minFreq) {
            minFreq = *channelData;
        }
        if (*channelData > maxFreq) {
            maxFreq = *channelData;
        }
        std::cout << "average: " << averageWave << std::endl;
        std::cout << "min: " << minFreq << std::endl;
        std::cout << "max: " << maxFreq << std::endl;
    }
}

//==============================================================================
bool Proj1AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Proj1AudioProcessor::createEditor()
{
    return new Proj1AudioProcessorEditor (*this);
}

//==============================================================================
void Proj1AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Proj1AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Proj1AudioProcessor();
}
