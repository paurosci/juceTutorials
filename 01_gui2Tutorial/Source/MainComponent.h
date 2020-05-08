/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class OtherLookAndFeel : public LookAndFeel_V4
{
public:
    void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
    {
        float diameter = jmin(width, height);
        float centerX = x + width / 2;
        float centerY = y + height / 2;
        float rx = centerX - diameter/2;
        float ry = centerY - diameter/2;
        float angle = rotaryStartAngle + (sliderPos *(rotaryEndAngle - rotaryStartAngle));
        
        
        std::cout << rotaryStartAngle << " " << rotaryEndAngle << std::endl;
        Rectangle<float> dialArea (rx, ry, diameter, diameter);
        
        g.setColour(Colours::red);
        //g.drawRect(dialArea);
        g.fillEllipse(dialArea);
        
        g.setColour(Colours::black);
        //g.fillEllipse(centerX, centerY, 5, 5);
        
        Path dialTick;
        dialTick.addRectangle(0, -diameter/2, 10.0f, diameter/2 *0.33);
        
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centerX, centerY));
        g.setColour(Colours::black);
        g.drawEllipse(rx, ry, diameter, diameter, 5.0f);
    }
};
//==============================================================================
/*
 This component lives inside our window, and this is where you should put all
 your controls and content.
 */
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();
    
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
private:
    Slider dial1;
    OtherLookAndFeel otherLookAndFeel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
