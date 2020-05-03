/*
  ==============================================================================

    SunComponent.cpp
    Created: 29 Apr 2020 7:21:26pm
    Author:  Pau Rosell

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SunComponent.h"

//==============================================================================
SunComponent::SunComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

SunComponent::~SunComponent()
{
}

void SunComponent::paint (Graphics& g)
{
    g.setColour(Colours::yellow);
    //Rectangle<float>(50, 50)
    //g.drawEllipse(400, 50, 50, 50, 10.f);
    g.fillEllipse(400, 50, 50, 50);
}

void SunComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
