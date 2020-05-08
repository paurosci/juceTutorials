/*
 ==============================================================================
 
 GrassComponent.cpp
 Created: 29 Apr 2020 6:52:46pm
 Author:  Pau Rosell
 
 ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"
#include "GrassComponent.h"

//==============================================================================
GrassComponent::GrassComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
}

GrassComponent::~GrassComponent()
{
}

void GrassComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
     draws some placeholder text to get you started.
     
     You should replace everything in this method with your own
     drawing code..
     */
    g.setColour(Colours::green);
    g.drawLine(10, 325, getWidth() - 10, 325, 10.0f);
    
}

void GrassComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
}
