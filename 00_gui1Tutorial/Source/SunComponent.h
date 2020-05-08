/*
 ==============================================================================
 
 SunComponent.h
 Created: 29 Apr 2020 7:21:26pm
 Author:  Pau Rosell
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
 */
class SunComponent    : public Component
{
public:
    SunComponent();
    ~SunComponent();
    
    void paint (Graphics&) override;
    void resized() override;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SunComponent)
};
