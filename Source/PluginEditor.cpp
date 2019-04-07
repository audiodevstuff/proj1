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
    someButton.setButtonText("yep!");
    someButton.setColour(TextButton::buttonColourId, Colours::grey);
    addAndMakeVisible(someButton);
    setSize (400, 400);
}

Proj1AudioProcessorEditor::~Proj1AudioProcessorEditor() {}

void Proj1AudioProcessorEditor::paint (Graphics& g) {
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);

    g.drawText("text here", 10, 200, 150, 30, Justification::centred, 1);
}

void Proj1AudioProcessorEditor::resized() {
    someButton.setBounds(10, 10, 100, 20);
}
