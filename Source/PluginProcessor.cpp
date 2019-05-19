/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VelocityModifierAudioProcessor::VelocityModifierAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

VelocityModifierAudioProcessor::~VelocityModifierAudioProcessor()
{
}

//==============================================================================
const String VelocityModifierAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool VelocityModifierAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool VelocityModifierAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool VelocityModifierAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double VelocityModifierAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int VelocityModifierAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int VelocityModifierAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VelocityModifierAudioProcessor::setCurrentProgram (int index)
{
}

const String VelocityModifierAudioProcessor::getProgramName (int index)
{
    return {};
}

void VelocityModifierAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void VelocityModifierAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void VelocityModifierAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool VelocityModifierAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void VelocityModifierAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    buffer.clear();
    MidiBuffer processedMidi;
    int time;
    MidiMessage m;
    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
    {
        if (m.isNoteOn())
        {
            uint8 oldVel = (uint8) m.getVelocity();
            // Scale velocity based on midiRangeValue and midiCompressionValue
            //
            
            // Scale velocity based on midiCompressionValue
            float lowVal = 0.0;
            float highVal = 1.0;
            if (midiCompressionValue >= 0) {
                lowVal = midiCompressionValue;
            } else {
                highVal = 1.0 - (- midiCompressionValue);
            }
            float oldNormed = oldVel / 127.0;
            
            float newNormed = lowVal + oldNormed * (highVal - lowVal);
            
            uint8 newVel = (uint8) (newNormed * 127.0);
            
            m = MidiMessage::noteOn(m.getChannel(), m.getNoteNumber(), newVel);
        }
        else if (m.isNoteOff())
        {
        }
        else if (m.isAftertouch())
        {
        }
        else if (m.isPitchWheel())
        {
        }
        else if (m.isControllerOfType(1)) {
            // Change midiCompressionValue, leave Controller Message unaltered
            int cVal = m.getControllerValue();
            midiCompressionValue = (cVal - 64.0) / 127.0;
            midiCompressionValue = fmax(fmin(midiCompressionValue, -1), 1);
        }
        processedMidi.addEvent (m, time);
    }
    midiMessages.swapWith (processedMidi);
}

//==============================================================================
bool VelocityModifierAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* VelocityModifierAudioProcessor::createEditor()
{
    return new VelocityModifierAudioProcessorEditor (*this);
}

//==============================================================================
void VelocityModifierAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void VelocityModifierAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VelocityModifierAudioProcessor();
}
