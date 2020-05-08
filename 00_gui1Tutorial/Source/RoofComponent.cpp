/*
 ==============================================================================
 
 RoofComponent.cpp
 Created: 29 Apr 2020 6:58:13pm
 Author:  Pau Rosell
 
 ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"
#include "RoofComponent.h"

//==============================================================================
RoofComponent::RoofComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
}

RoofComponent::~RoofComponent()
{
}

void RoofComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
     draws some placeholder text to get you started.
     
     You should replace everything in this method with your own
     drawing code..
     */
    g.setColour(Colours::darkred);
    Path p;
    p.startNewSubPath(200, 195);
    p.lineTo(400, 195);
    p.lineTo(300,140);
    p.closeSubPath();
    g.fillPath(p);
    g.strokePath(p, PathStrokeType(15.0f));
}

void RoofComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
}
