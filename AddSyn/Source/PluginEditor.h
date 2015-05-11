/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_3DF5A35AD5D81276__
#define __JUCE_HEADER_3DF5A35AD5D81276__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "EnvelopeType.h"
class AddSynAudioProcessor;
enum Tab;
enum WaveType;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AddSynAudioProcessorEditor  : public AudioProcessorEditor,
                                    public Timer,
                                    public SliderListener,
                                    public ButtonListener
{
public:
    //==============================================================================
    AddSynAudioProcessorEditor (AddSynAudioProcessor& ownerFilter);
    ~AddSynAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
		AddSynAudioProcessor* getProcessor();
		void timerCallback();
		void MoveNextInstrument(bool forward);
		void ResetGUI(EnvelopeType tab);
		void setWaveTypeGUI(WaveType wt);
		EnvelopeType getCurrentTab();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	int currPos = 0;
	EnvelopeType currTab;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TabbedComponent> uxTabs;
    ScopedPointer<Slider> uxSlider1;
    ScopedPointer<Slider> uxSlider2;
    ScopedPointer<Slider> uxSlider3;
    ScopedPointer<Slider> uxSlider4;
    ScopedPointer<Slider> uxSlider5;
    ScopedPointer<Slider> uxSlider6;
    ScopedPointer<Slider> uxSlider7;
    ScopedPointer<Slider> uxSlider8;
    ScopedPointer<Slider> uxSlider9;
    ScopedPointer<Slider> uxSlider10;
    ScopedPointer<Slider> uxSlider11;
    ScopedPointer<Slider> uxSlider12;
    ScopedPointer<TextButton> uxLeftButton;
    ScopedPointer<TextEditor> uxName;
    ScopedPointer<TextButton> uxRightButton;
    ScopedPointer<TextButton> uxCreateInstrument;
    ScopedPointer<TextButton> uxDestroyInstrument;
    ScopedPointer<ToggleButton> uxSineButton;
    ScopedPointer<ToggleButton> uxTriangleButton;
    ScopedPointer<ToggleButton> uxSquareButton;
    ScopedPointer<ToggleButton> uxSawButton;
    ScopedPointer<Slider> uxAttackSlider;
    ScopedPointer<Slider> uxReleaseSlider;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Slider> uxSustainSlider;
    ScopedPointer<Label> label3;
    ScopedPointer<ToggleButton> uxSustainButton;
    ScopedPointer<MidiKeyboardComponent> midiKeyboard;
    ScopedPointer<ToggleButton> uxSoloButton;
    ScopedPointer<ToggleButton> uxMuteButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AddSynAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_3DF5A35AD5D81276__
