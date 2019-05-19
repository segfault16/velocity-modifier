/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VelocityModifierAudioProcessorEditor::VelocityModifierAudioProcessorEditor (VelocityModifierAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    midiCompressionSlider.setComponentID("midiCompressionSlider");
    midiCompressionSlider.setSliderStyle(Slider::LinearBarVertical);
    midiCompressionSlider.setRange(-1.0, 1.0, 0.01);
    midiCompressionSlider.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    midiCompressionSlider.setPopupDisplayEnabled (true, false, this);
    midiCompressionSlider.setTextValueSuffix (" Velocity Compression");
    midiCompressionSlider.setValue(0.0);
    midiCompressionSlider.addListener(this);
    // this function adds the slider to the editor
    addAndMakeVisible (&midiCompressionSlider);
    
    midiRangeSlider.setComponentID("midiRangeSlider");
    midiRangeSlider.setSliderStyle(Slider::LinearBarVertical);
    midiRangeSlider.setRange(0.0, 1.0, 0.01);
    midiRangeSlider.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    midiRangeSlider.setPopupDisplayEnabled (true, false, this);
    midiRangeSlider.setTextValueSuffix (" Velocity Range");
    midiRangeSlider.setValue(1.0);
    midiRangeSlider.addListener(this);
    // this function adds the slider to the editor
    addAndMakeVisible (&midiRangeSlider);
}

VelocityModifierAudioProcessorEditor::~VelocityModifierAudioProcessorEditor()
{
}

//==============================================================================
void VelocityModifierAudioProcessorEditor::paint (Graphics& g)
{
    // fill the whole window white
    g.fillAll (Colours::white);
    // set the current drawing colour to black
    g.setColour (Colours::black);
    // set the font size and draw text to the screen
    g.setFont (15.0f);
    g.drawFittedText ("Midi Volume", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void VelocityModifierAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    midiCompressionSlider.setBounds (40, 30, 20, getHeight() - 60);
    midiRangeSlider.setBounds(80, 30, 20, getHeight() - 60);
}

// Slider callback

void VelocityModifierAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    if(slider->getComponentID() == midiCompressionSlider.getComponentID()) {
        *processor.midiCompressionValue = slider->getValue();
    } else if (slider->getComponentID() == midiRangeSlider.getComponentID()) {
        *processor.midiRangeValue = slider->getValue();
    }
}
