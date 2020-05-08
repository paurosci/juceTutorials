/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);

    // Some platforms require permissions to open input channels so request that here
    if (RuntimePermissions::isRequired (RuntimePermissions::recordAudio)
        && ! RuntimePermissions::isGranted (RuntimePermissions::recordAudio))
    {
        RuntimePermissions::request (RuntimePermissions::recordAudio,
                                     [&] (bool granted) { if (granted)  setAudioChannels (2, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    frequency = 440;
    phase = 0;
    wtSize = 1024;
    increment = frequency * wtSize / sampleRate;
    amplitude = 0.25;
    
    // one cycle of a sine wave
    for ( int i=0; i < wtSize; i++)
    {
        waveTable.insert(i, sin(2.0 * double_Pi * i / wtSize));
    }
    
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    float *leftSpeaker  = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    float *rightSpeaker = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
    
    for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
    {
        leftSpeaker[sample] = waveTable[(int)phase] * amplitude;
        rightSpeaker[sample] = waveTable[(int)phase] * amplitude;
        phase = fmod((phase + increment),wtSize);
    }
}

void MainComponent::releaseResources()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
}
