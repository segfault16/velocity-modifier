/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
class VelocityModifierAudioProcessor  : public AudioProcessor
{
public:
    // Velocity compression
    const String p_midiCompressionValue = "midiCompressionValue";
    const String p_midiCompressionFilterControl = "midiCompressionFilterControl";
    const String p_midiCompressionControlCC = "midiCompressionControlCC";
    AudioParameterFloat* midiCompressionValue;
    AudioParameterBool* midiCompressionFilterControl; // Filter out control Message?
    AudioParameterInt* midiCompressionControlCC; // CC for Control Message
    
    // Velocity range
    const String p_midiRangeValue = "midiRangeValue";
    const String p_midiRangeFilterControl = "midiRangeFilterControl";
    const String p_midiRangeControlCC = "midiRangeControlCC";
    AudioParameterFloat* midiRangeValue;
    AudioParameterBool* midiRangeFilterControl; // Filter out control Message?
    AudioParameterInt* midiRangeControlCC; // CC for Control Message
    
    
    
    //==============================================================================
    VelocityModifierAudioProcessor();
    ~VelocityModifierAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VelocityModifierAudioProcessor)
};
