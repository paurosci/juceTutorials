/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
_06_plGainTutorialAudioProcessor::_06_plGainTutorialAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
                    // pro: initialise deviceTree parameters
                    parameters(*this, nullptr, Identifier (GAIN_ID),
                               {
                                   std::make_unique<AudioParameterFloat> (GAIN_ID,           // parameterID
                                                                          GAIN_NAME,         // parameter name
                                                                          -48.0f,            // minimum value
                                                                          0.0f,              // maximum value
                                                                          -6.0f),            // default value
                               })

#endif
{
    //pro: obtain first value from the slider
    gainParameter = parameters.getRawParameterValue(GAIN_ID);
    
}

_06_plGainTutorialAudioProcessor::~_06_plGainTutorialAudioProcessor()
{
}

//==============================================================================
const String _06_plGainTutorialAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool _06_plGainTutorialAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool _06_plGainTutorialAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool _06_plGainTutorialAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double _06_plGainTutorialAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int _06_plGainTutorialAudioProcessor::getNumPrograms()
{
    return 1;   
}

int _06_plGainTutorialAudioProcessor::getCurrentProgram()
{
    return 0;
}

void _06_plGainTutorialAudioProcessor::setCurrentProgram (int index)
{
}

const String _06_plGainTutorialAudioProcessor::getProgramName (int index)
{
    return {};
}

void _06_plGainTutorialAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void _06_plGainTutorialAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{

}

void _06_plGainTutorialAudioProcessor::releaseResources()
{

}

#ifndef JucePlugin_PreferredChannelConfigurations
bool _06_plGainTutorialAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void _06_plGainTutorialAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);
        
        for ( int sample=0; sample < buffer.getNumSamples(); ++sample )
        {
            channelData[sample] = buffer.getSample(channel, sample) * pow(10,*gainParameter/20);
        }
    }
}

//==============================================================================
bool _06_plGainTutorialAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* _06_plGainTutorialAudioProcessor::createEditor()
{
    //pro: return processorEditor and AudioProcessorValueTreeState 
    return new _06_plGainTutorialAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void _06_plGainTutorialAudioProcessor::getStateInformation (MemoryBlock& destData)
{
}

void _06_plGainTutorialAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new _06_plGainTutorialAudioProcessor();
}
