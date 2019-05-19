/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class VelocityModifierAudioProcessorEditor  : public AudioProcessorEditor, private Slider::Listener
{
public:
    VelocityModifierAudioProcessorEditor (VelocityModifierAudioProcessor&);
    ~VelocityModifierAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // Slider callback
    void sliderValueChanged (Slider* slider) override;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VelocityModifierAudioProcessor& processor;
    
    // Own
    Slider midiCompressionSlider;
    Slider midiRangeSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VelocityModifierAudioProcessorEditor)
};
