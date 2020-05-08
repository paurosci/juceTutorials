/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    
    addAndMakeVisible(dial1);
    dial1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalDrag);
    dial1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    dial1.setLookAndFeel(&otherLookAndFeel);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colours::white);
}

void MainComponent::resized()
{
    dial1.setBounds(getLocalBounds());
}
