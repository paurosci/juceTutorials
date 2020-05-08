/*
 ==============================================================================
 
 TextComponent.cpp
 Created: 29 Apr 2020 7:26:27pm
 Author:  Pau Rosell
 
 ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"
#include "TextComponent.h"

//==============================================================================
TextComponent::TextComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
}

TextComponent::~TextComponent()
{
}

void TextComponent::paint (Graphics& g)
{
    Font theFont("Ubuntu", "Regular", 20.0f);
    g.setFont(theFont);
    g.drawText("Rozzilabs", 20, 20, 100, 20, Justification::topLeft);
}

void TextComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
}
