/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
//pro: include AudioProcessorValueTreeState vts object in the ProcessorEditor initialisation
_06_plGainTutorialAudioProcessorEditor::_06_plGainTutorialAudioProcessorEditor (_06_plGainTutorialAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState(vts)
{
    setSize (100, 400);
    gainSlider.setRange(-48.0, 0.0);
    gainSlider.setValue(-6.0);
    gainSlider.setNumDecimalPlacesToDisplay(2);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gainSlider.setTextValueSuffix("dB");
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    // pro: create slider attachment object to the gainSlider
    gainAttachment.reset (new SliderAttachment(valueTreeState, GAIN_ID, gainSlider));

}

_06_plGainTutorialAudioProcessorEditor::~_06_plGainTutorialAudioProcessorEditor()
{
}

//==============================================================================
void _06_plGainTutorialAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::magenta);
}

void _06_plGainTutorialAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}
//pro: create gainSlider listener definition
void _06_plGainTutorialAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if ( slider == &gainSlider )
    {
        processor.gainValue = gainSlider.getValue();
    }
}
