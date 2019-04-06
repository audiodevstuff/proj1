/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Proj1AudioProcessorEditor::Proj1AudioProcessorEditor (Proj1AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (400, 400);
}

Proj1AudioProcessorEditor::~Proj1AudioProcessorEditor()
{
}

//==============================================================================
void Proj1AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("It should work", getLocalBounds(), Justification::top, 1);
}

void Proj1AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
