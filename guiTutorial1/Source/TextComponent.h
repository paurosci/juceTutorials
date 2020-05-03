/*
  ==============================================================================

    TextComponent.h
    Created: 29 Apr 2020 7:26:27pm
    Author:  Pau Rosell

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class TextComponent    : public Component
{
public:
    TextComponent();
    ~TextComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TextComponent)
};
