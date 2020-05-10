/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class _06_plGainTutorialAudioProcessorEditor  : public AudioProcessorEditor,
                                                public Slider::Listener
{
public:
    //pro: include AudioProcessorValueTreeState vts object in the AudioProcessor initialisation
    _06_plGainTutorialAudioProcessorEditor (_06_plGainTutorialAudioProcessor&, AudioProcessorValueTreeState&);
    ~_06_plGainTutorialAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider *slider) override;
    
    //pro: define SliderAttachment variable type
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    
private:
    _06_plGainTutorialAudioProcessor& processor;
    //pro: define AudioProcessorValueTreeState variable in order to link both, processor and editor
    AudioProcessorValueTreeState& valueTreeState;
    //pro: define gainSlider, it needs to be declared before the SliderAttachment
    Slider gainSlider;
    //pro: define a pointer to reference the slider attachment
    std::unique_ptr<SliderAttachment> gainAttachment;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_06_plGainTutorialAudioProcessorEditor)
};
