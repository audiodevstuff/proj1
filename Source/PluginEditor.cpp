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

Proj1AudioProcessorEditor::~Proj1AudioProcessorEditor() {}

void Proj1AudioProcessorEditor::paint (Graphics& g) {
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);

    g.drawRect(10, 50, 150, 30, 1);
    g.drawText("Button 1", 10, 50, 150, 30, Justification::centred, 1);
}

void Proj1AudioProcessorEditor::resized() {}
