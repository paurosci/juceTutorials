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
    setSize (800, 100);
    freqSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    freqSlider.setRange(50.0, 500.0);
    freqSlider.setNumDecimalPlacesToDisplay(2);
    ampSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    ampSlider.setRange(0, 0.5);
    ampSlider.setNumDecimalPlacesToDisplay(2);
    addAndMakeVisible(freqSlider);
    addAndMakeVisible(ampSlider);
    
    freqSlider.addListener(this);
    freqSlider.setValue(200.0);
    freqSlider.setTextValueSuffix("Hz");
    freqLabel.setText("Frequency:", dontSendNotification);
    freqLabel.attachToComponent(&freqSlider, true);
    
    ampSlider.addListener(this);
    ampSlider.setValue(0.25);
    ampLabel.setText("Amplitude:", dontSendNotification);
    ampLabel.attachToComponent(&ampSlider, true);
    
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

void MainComponent::updateFrequency()
{
    increment = frequency * wtSize / currentSampleRate;
    phase = fmod((phase + increment),wtSize);
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    phase = 0;
    wtSize = 1024;
    frequency = freqSlider.getValue();
    amplitude = ampSlider.getValue();
    currentSampleRate = sampleRate;
    
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
        updateFrequency();
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
    const int labelSpace = 100;
    freqSlider.setBounds(labelSpace, 20, getWidth() - 100, 20);
    ampSlider.setBounds(labelSpace, 50, getWidth() - 100, 20);
}
