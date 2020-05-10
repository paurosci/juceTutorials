/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#define GAIN_ID "gain"
#define GAIN_NAME "Gain"
//==============================================================================
/**
*/
class _06_plGainTutorialAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    _06_plGainTutorialAudioProcessor();
    ~_06_plGainTutorialAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //pro: create an AudioProcessorValueTreeState object to attach to our processor
    AudioProcessorValueTreeState parameters;
    float gainValue;
private:
    //pro: declare a pointer to initialise the AudioProcessorValueTreeState
    std::atomic<float>* gainParameter  = nullptr;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_06_plGainTutorialAudioProcessor)
};
