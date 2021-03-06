/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AddSynAudioProcessor::AddSynAudioProcessor()
{
	synth = new AddSynthesizer();
	muted = new bool[16];

	for (int i = 0; i < 16; i++)
	{
		muted[i] = false;
	}
}

AddSynAudioProcessor::~AddSynAudioProcessor()
{
	delete synth;
}

//==============================================================================
const String AddSynAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int AddSynAudioProcessor::getNumParameters()
{
    return 0;
}

float AddSynAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void AddSynAudioProcessor::setParameter (int index, float newValue)
{
}

const String AddSynAudioProcessor::getParameterName (int index)
{
    return String();
}

const String AddSynAudioProcessor::getParameterText (int index)
{
    return String();
}

const String AddSynAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String AddSynAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool AddSynAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool AddSynAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool AddSynAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AddSynAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AddSynAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double AddSynAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AddSynAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AddSynAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AddSynAudioProcessor::setCurrentProgram (int index)
{
}

const String AddSynAudioProcessor::getProgramName (int index)
{
    return String();
}

void AddSynAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AddSynAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	synth->synth->setCurrentPlaybackSampleRate(sampleRate);
	keyboardState.reset();
}

void AddSynAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
	keyboardState.reset();
}

void AddSynAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	const int numSamples = buffer.getNumSamples();

	/*
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
	*/

	// Now pass any incoming midi messages to our keyboard state object, and let it
	// add messages to the buffer if the user is clicking on the on-screen keys
	keyboardState.processNextMidiBuffer(midiMessages, 0, numSamples, true);

	// and now get the synth to process these midi events and generate its output.
	for (int i = 0; i < 16; i++)
		if(synth->getActive(i) && !muted[i])
			synth->synth[i].renderNextBlock(buffer, midiMessages, 0, numSamples);

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }

	// In case we have more outputs than inputs, we'll clear any output
	// channels that didn't contain input data, (because these aren't
	// guaranteed to be empty - they may contain garbage).
	for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
		buffer.clear(i, 0, buffer.getNumSamples());
}

//==============================================================================
bool AddSynAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AddSynAudioProcessor::createEditor()
{
    return new AddSynAudioProcessorEditor (*this);
}

//==============================================================================
void AddSynAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AddSynAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AddSynAudioProcessor();
}
