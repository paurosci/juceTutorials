/*
  ==============================================================================

    RoofComponent.h
    Created: 29 Apr 2020 6:58:13pm
    Author:  Pau Rosell

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class RoofComponent    : public Component
{
public:
    RoofComponent();
    ~RoofComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoofComponent)
};
