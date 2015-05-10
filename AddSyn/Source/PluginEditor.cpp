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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AddSynAudioProcessorEditor::AddSynAudioProcessorEditor (AddSynAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (uxTabs = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    uxTabs->setTabBarDepth (30);
    uxTabs->addTab (TRANS("Attack"), Colour (0xffce3838), 0, false);
    uxTabs->addTab (TRANS("Sustain"), Colour (0xff07c046), 0, false);
    uxTabs->addTab (TRANS("Release"), Colour (0xff0c0ea8), 0, false);
    uxTabs->setCurrentTabIndex (0);

    addAndMakeVisible (uxSlider1 = new Slider ("uxSlider1"));
    uxSlider1->setRange (0, 9, 0);
    uxSlider1->setSliderStyle (Slider::LinearVertical);
    uxSlider1->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider1->addListener (this);

    addAndMakeVisible (uxSlider2 = new Slider ("uxSlider2"));
    uxSlider2->setRange (0, 10, 0);
    uxSlider2->setSliderStyle (Slider::LinearVertical);
    uxSlider2->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider2->addListener (this);

    addAndMakeVisible (uxSlider3 = new Slider ("uxSlider3"));
    uxSlider3->setRange (0, 10, 0);
    uxSlider3->setSliderStyle (Slider::LinearVertical);
    uxSlider3->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider3->addListener (this);

    addAndMakeVisible (uxSlider4 = new Slider ("uxSlider4"));
    uxSlider4->setRange (0, 10, 0);
    uxSlider4->setSliderStyle (Slider::LinearVertical);
    uxSlider4->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider4->addListener (this);

    addAndMakeVisible (uxSlider5 = new Slider ("uxSlider5"));
    uxSlider5->setRange (0, 10, 0);
    uxSlider5->setSliderStyle (Slider::LinearVertical);
    uxSlider5->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider5->addListener (this);

    addAndMakeVisible (uxSlider6 = new Slider ("uxSlider6"));
    uxSlider6->setRange (0, 10, 0);
    uxSlider6->setSliderStyle (Slider::LinearVertical);
    uxSlider6->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider6->addListener (this);

    addAndMakeVisible (uxSlider7 = new Slider ("uxSlider7"));
    uxSlider7->setRange (0, 10, 0);
    uxSlider7->setSliderStyle (Slider::LinearVertical);
    uxSlider7->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider7->addListener (this);

    addAndMakeVisible (uxSlider8 = new Slider ("uxSlider8"));
    uxSlider8->setRange (0, 10, 0);
    uxSlider8->setSliderStyle (Slider::LinearVertical);
    uxSlider8->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider8->addListener (this);

    addAndMakeVisible (uxSlider9 = new Slider ("uxSlider9"));
    uxSlider9->setRange (0, 10, 0);
    uxSlider9->setSliderStyle (Slider::LinearVertical);
    uxSlider9->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider9->addListener (this);

    addAndMakeVisible (uxSlider10 = new Slider ("uxSlider10"));
    uxSlider10->setRange (0, 10, 0);
    uxSlider10->setSliderStyle (Slider::LinearVertical);
    uxSlider10->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider10->addListener (this);

    addAndMakeVisible (uxSlider11 = new Slider ("uxSlider11"));
    uxSlider11->setRange (0, 10, 0);
    uxSlider11->setSliderStyle (Slider::LinearVertical);
    uxSlider11->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider11->addListener (this);

    addAndMakeVisible (uxSlider12 = new Slider ("uxSlider12"));
    uxSlider12->setRange (0, 10, 0);
    uxSlider12->setSliderStyle (Slider::LinearVertical);
    uxSlider12->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    uxSlider12->addListener (this);

    addAndMakeVisible (uxLeftButton = new TextButton ("uxLeftButton"));
    uxLeftButton->setButtonText (TRANS("<"));
    uxLeftButton->addListener (this);

    addAndMakeVisible (uxName = new TextEditor ("uxName"));
    uxName->setMultiLine (false);
    uxName->setReturnKeyStartsNewLine (false);
    uxName->setReadOnly (false);
    uxName->setScrollbarsShown (true);
    uxName->setCaretVisible (true);
    uxName->setPopupMenuEnabled (true);
    uxName->setText (String::empty);

    addAndMakeVisible (uxRightButton = new TextButton ("uxRightButton"));
    uxRightButton->setButtonText (TRANS(">"));
    uxRightButton->addListener (this);

    addAndMakeVisible (uxCreateInstrument = new TextButton ("uxCreateInstrument"));
    uxCreateInstrument->setButtonText (TRANS("+"));
    uxCreateInstrument->addListener (this);
    uxCreateInstrument->setColour (TextButton::textColourOffId, Colour (0xff077c24));

    addAndMakeVisible (uxDestroyInstrument = new TextButton ("uxDestroyInstrument"));
    uxDestroyInstrument->setButtonText (TRANS("x"));
    uxDestroyInstrument->addListener (this);
    uxDestroyInstrument->setColour (TextButton::textColourOffId, Colour (0xfffd0000));

    addAndMakeVisible (uxSineButton = new ToggleButton ("uxSineButton"));
    uxSineButton->setButtonText (TRANS("Sine"));
    uxSineButton->addListener (this);

    addAndMakeVisible (uxTriangleButton = new ToggleButton ("uxTriangleButton"));
    uxTriangleButton->setButtonText (TRANS("Triangle"));
    uxTriangleButton->addListener (this);

    addAndMakeVisible (uxSquareButton = new ToggleButton ("uxSquareButton"));
    uxSquareButton->setButtonText (TRANS("Square"));
    uxSquareButton->addListener (this);

    addAndMakeVisible (uxSawButton = new ToggleButton ("uxSawButton"));
    uxSawButton->setButtonText (TRANS("Saw"));
    uxSawButton->addListener (this);

    addAndMakeVisible (uxAttackSlider = new Slider ("uxAttackSlider"));
    uxAttackSlider->setRange (0, 10, 0);
    uxAttackSlider->setSliderStyle (Slider::RotaryHorizontalDrag);
    uxAttackSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    uxAttackSlider->addListener (this);

    addAndMakeVisible (uxReleaseSlider = new Slider ("uxReleaseSlider"));
    uxReleaseSlider->setRange (0, 10, 0);
    uxReleaseSlider->setSliderStyle (Slider::RotaryHorizontalDrag);
    uxReleaseSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    uxReleaseSlider->addListener (this);

    addAndMakeVisible (label = new Label ("uxAttackLabel",
                                          TRANS("Attack Rate")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("uxReleaseLabel",
                                           TRANS("Release Rate")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (uxSustainSlider = new Slider ("uxSustainSlider"));
    uxSustainSlider->setRange (0, 10, 0);
    uxSustainSlider->setSliderStyle (Slider::RotaryHorizontalDrag);
    uxSustainSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    uxSustainSlider->addListener (this);

    addAndMakeVisible (label3 = new Label ("uxReleaseLabel",
                                           TRANS("Sustain Rate")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (uxSustainButton = new ToggleButton ("uxSustainButton"));
    uxSustainButton->setButtonText (TRANS("Sustain"));
    uxSustainButton->addListener (this);
    uxSustainButton->setToggleState (true, dontSendNotification);

    addAndMakeVisible (uxLeftButton2 = new TextButton ("uxLeftButton"));
    uxLeftButton2->setButtonText (TRANS("Save"));
    uxLeftButton2->addListener (this);

    addAndMakeVisible (uxRightButton2 = new TextButton ("uxRightButton"));
    uxRightButton2->setButtonText (TRANS("Load"));
    uxRightButton2->addListener (this);

    addAndMakeVisible (midiKeyboard = new Component());
    midiKeyboard->setName ("MIDI Keyboard");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
		startTimer(200); //starts timer with interval of 200ms
		currTab = Attack;
    //[/Constructor]
}

AddSynAudioProcessorEditor::~AddSynAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    uxTabs = nullptr;
    uxSlider1 = nullptr;
    uxSlider2 = nullptr;
    uxSlider3 = nullptr;
    uxSlider4 = nullptr;
    uxSlider5 = nullptr;
    uxSlider6 = nullptr;
    uxSlider7 = nullptr;
    uxSlider8 = nullptr;
    uxSlider9 = nullptr;
    uxSlider10 = nullptr;
    uxSlider11 = nullptr;
    uxSlider12 = nullptr;
    uxLeftButton = nullptr;
    uxName = nullptr;
    uxRightButton = nullptr;
    uxCreateInstrument = nullptr;
    uxDestroyInstrument = nullptr;
    uxSineButton = nullptr;
    uxTriangleButton = nullptr;
    uxSquareButton = nullptr;
    uxSawButton = nullptr;
    uxAttackSlider = nullptr;
    uxReleaseSlider = nullptr;
    label = nullptr;
    label2 = nullptr;
    uxSustainSlider = nullptr;
    label3 = nullptr;
    uxSustainButton = nullptr;
    uxLeftButton2 = nullptr;
    uxRightButton2 = nullptr;
    midiKeyboard = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AddSynAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffaea2a2));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AddSynAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    uxTabs->setBounds (16, 48, 288, 224);
    uxSlider1->setBounds (16, 88, 23, 184);
    uxSlider2->setBounds (40, 88, 23, 184);
    uxSlider3->setBounds (64, 88, 23, 184);
    uxSlider4->setBounds (88, 88, 23, 184);
    uxSlider5->setBounds (112, 88, 23, 184);
    uxSlider6->setBounds (136, 88, 23, 184);
    uxSlider7->setBounds (160, 88, 23, 184);
    uxSlider8->setBounds (184, 88, 23, 184);
    uxSlider9->setBounds (208, 88, 23, 184);
    uxSlider10->setBounds (232, 88, 23, 184);
    uxSlider11->setBounds (256, 88, 23, 184);
    uxSlider12->setBounds (280, 88, 23, 184);
    uxLeftButton->setBounds (8, 8, 31, 24);
    uxName->setBounds (80, 8, 158, 24);
    uxRightButton->setBounds (40, 8, 32, 24);
    uxCreateInstrument->setBounds (248, 8, 32, 24);
    uxDestroyInstrument->setBounds (280, 8, 32, 24);
    uxSineButton->setBounds (24, 288, 56, 24);
    uxTriangleButton->setBounds (88, 288, 64, 24);
    uxSquareButton->setBounds (168, 288, 64, 24);
    uxSawButton->setBounds (248, 288, 64, 24);
    uxAttackSlider->setBounds (304, 80, 64, 48);
    uxReleaseSlider->setBounds (304, 136, 64, 48);
    label->setBounds (376, 88, 79, 24);
    label2->setBounds (376, 144, 79, 24);
    uxSustainSlider->setBounds (304, 192, 64, 48);
    label3->setBounds (376, 200, 79, 24);
    uxSustainButton->setBounds (344, 248, 64, 24);
    uxLeftButton2->setBounds (336, 8, 48, 24);
    uxRightButton2->setBounds (384, 8, 48, 24);
    midiKeyboard->setBounds (16, 320, 432, 64);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AddSynAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	AddSynAudioProcessor* proc = getProcessor();
	Tab tab;

	tab = getCurrentTab();

    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == uxSlider1)
    {
        //[UserSliderCode_uxSlider1] -- add your slider handling code here..
		proc->setLevels(currPos, 0, tab, uxSlider1->getValue());
		//uxName->setText(juce::String(proc->getLevels(currPos).attackValues[0]));
        //[/UserSliderCode_uxSlider1]
    }
    else if (sliderThatWasMoved == uxSlider2)
    {
        //[UserSliderCode_uxSlider2] -- add your slider handling code here..
		proc->setLevels(currPos, 1, tab, uxSlider2->getValue());
        //[/UserSliderCode_uxSlider2]
    }
    else if (sliderThatWasMoved == uxSlider3)
    {
        //[UserSliderCode_uxSlider3] -- add your slider handling code here..
		proc->setLevels(currPos, 2, tab, uxSlider3->getValue());
        //[/UserSliderCode_uxSlider3]
    }
    else if (sliderThatWasMoved == uxSlider4)
    {
        //[UserSliderCode_uxSlider4] -- add your slider handling code here..
		proc->setLevels(currPos, 3, tab, uxSlider4->getValue());
        //[/UserSliderCode_uxSlider4]
    }
    else if (sliderThatWasMoved == uxSlider5)
    {
        //[UserSliderCode_uxSlider5] -- add your slider handling code here..
		proc->setLevels(currPos, 4, tab, uxSlider5->getValue());
        //[/UserSliderCode_uxSlider5]
    }
    else if (sliderThatWasMoved == uxSlider6)
    {
        //[UserSliderCode_uxSlider6] -- add your slider handling code here..
		proc->setLevels(currPos, 5, tab, uxSlider6->getValue());
        //[/UserSliderCode_uxSlider6]
    }
    else if (sliderThatWasMoved == uxSlider7)
    {
        //[UserSliderCode_uxSlider7] -- add your slider handling code here..
		proc->setLevels(currPos, 6, tab, uxSlider7->getValue());
        //[/UserSliderCode_uxSlider7]
    }
    else if (sliderThatWasMoved == uxSlider8)
    {
        //[UserSliderCode_uxSlider8] -- add your slider handling code here..
		proc->setLevels(currPos, 7, tab, uxSlider8->getValue());
        //[/UserSliderCode_uxSlider8]
    }
    else if (sliderThatWasMoved == uxSlider9)
    {
        //[UserSliderCode_uxSlider9] -- add your slider handling code here..
		proc->setLevels(currPos, 8, tab, uxSlider9->getValue());
        //[/UserSliderCode_uxSlider9]
    }
    else if (sliderThatWasMoved == uxSlider10)
    {
        //[UserSliderCode_uxSlider10] -- add your slider handling code here..
		proc->setLevels(currPos, 9, tab, uxSlider10->getValue());
        //[/UserSliderCode_uxSlider10]
    }
    else if (sliderThatWasMoved == uxSlider11)
    {
        //[UserSliderCode_uxSlider11] -- add your slider handling code here..
		proc->setLevels(currPos, 10, tab, uxSlider11->getValue());
        //[/UserSliderCode_uxSlider11]
    }
    else if (sliderThatWasMoved == uxSlider12)
    {
        //[UserSliderCode_uxSlider12] -- add your slider handling code here..
		proc->setLevels(currPos, 11, tab, uxSlider12->getValue());
        //[/UserSliderCode_uxSlider12]
    }
    else if (sliderThatWasMoved == uxAttackSlider)
    {
        //[UserSliderCode_uxAttackSlider] -- add your slider handling code here..
		proc->setRates(currPos, Attack, uxAttackSlider->getValue());
        //[/UserSliderCode_uxAttackSlider]
    }
    else if (sliderThatWasMoved == uxReleaseSlider)
    {
        //[UserSliderCode_uxReleaseSlider] -- add your slider handling code here..
		proc->setRates(currPos, Release, uxReleaseSlider->getValue());
        //[/UserSliderCode_uxReleaseSlider]
    }
    else if (sliderThatWasMoved == uxSustainSlider)
    {
        //[UserSliderCode_uxSustainSlider] -- add your slider handling code here..
		proc->setRates(currPos, Sustain, uxSustainSlider->getValue());
        //[/UserSliderCode_uxSustainSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void AddSynAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	AddSynAudioProcessor* proc = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == uxLeftButton)
    {
        //[UserButtonCode_uxLeftButton] -- add your button handler code here..
		MoveNextInstrument(false);
        //[/UserButtonCode_uxLeftButton]
    }
    else if (buttonThatWasClicked == uxRightButton)
    {
        //[UserButtonCode_uxRightButton] -- add your button handler code here..
		MoveNextInstrument(true);
        //[/UserButtonCode_uxRightButton]
    }
    else if (buttonThatWasClicked == uxCreateInstrument)
    {
        //[UserButtonCode_uxCreateInstrument] -- add your button handler code here..
		for (int i = currPos + 1; i < currPos + 16; i++)
		{
			int currIndex = i % 16;
			if (!proc->getLevels(currIndex).isActive)
			{
				currPos = i;
				proc->setActive(currPos, true);
				break;
			}
		}
		ResetGUI(Attack);
        //[/UserButtonCode_uxCreateInstrument]
    }
    else if (buttonThatWasClicked == uxDestroyInstrument)
    {
        //[UserButtonCode_uxDestroyInstrument] -- add your button handler code here..
		proc->setActive(currPos, false);
		MoveNextInstrument(false);
        //[/UserButtonCode_uxDestroyInstrument]
    }
    else if (buttonThatWasClicked == uxSineButton)
    {
        //[UserButtonCode_uxSineButton] -- add your button handler code here..
		setWaveTypeGUI(Sine);
		proc->setWaveType(currPos, Sine);
        //[/UserButtonCode_uxSineButton]
    }
    else if (buttonThatWasClicked == uxTriangleButton)
    {
        //[UserButtonCode_uxTriangleButton] -- add your button handler code here..
		setWaveTypeGUI(Triangle);
		proc->setWaveType(currPos, Triangle);
        //[/UserButtonCode_uxTriangleButton]
    }
    else if (buttonThatWasClicked == uxSquareButton)
    {
        //[UserButtonCode_uxSquareButton] -- add your button handler code here..
		setWaveTypeGUI(Square);
		proc->setWaveType(currPos, Square);
        //[/UserButtonCode_uxSquareButton]
    }
    else if (buttonThatWasClicked == uxSawButton)
    {
        //[UserButtonCode_uxSawButton] -- add your button handler code here..
		setWaveTypeGUI(Sawtooth);
		proc->setWaveType(currPos, Sawtooth);
        //[/UserButtonCode_uxSawButton]
    }
    else if (buttonThatWasClicked == uxSustainButton)
    {
        //[UserButtonCode_uxSustainButton] -- add your button handler code here..
		proc->setSustain(currPos, uxSustainButton->getToggleState());
        //[/UserButtonCode_uxSustainButton]
    }
    else if (buttonThatWasClicked == uxLeftButton2)
    {
        //[UserButtonCode_uxLeftButton2] -- add your button handler code here..
        //[/UserButtonCode_uxLeftButton2]
    }
    else if (buttonThatWasClicked == uxRightButton2)
    {
        //[UserButtonCode_uxRightButton2] -- add your button handler code here..
        //[/UserButtonCode_uxRightButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
	AddSynAudioProcessor* AddSynAudioProcessorEditor::getProcessor()
	{
		return static_cast <AddSynAudioProcessor*>(getAudioProcessor());
	}

	void AddSynAudioProcessorEditor::timerCallback()
	{
		AddSynAudioProcessor* ourProcessor = getProcessor();
		//exchange any data you want between UI elements and the Plugin "ourProcessor"

		// Hack for handling tab changes since I can't figure out how to add a ChangeListener to the TabbedComponenet
		if (currTab != uxTabs->getCurrentTabIndex())
		{
			currTab = getCurrentTab();
			ResetGUI(currTab);
		}
	}

	// Move the currently displayed instrument GUI to next instrument
	void AddSynAudioProcessorEditor::MoveNextInstrument(bool forward)
	{
		AddSynAudioProcessor* proc = getProcessor();

		int firstForward = -1;
		int firstBackward = -1;
		for (int i = currPos + 1; i < currPos + 16; i++)
		{
			int currIndex = i % 16;
			if (proc->getLevels(currIndex).isActive)
			{
				if (firstForward == -1) firstForward = currIndex;
				firstBackward = currIndex;
			}
		}

		if (firstForward != -1 && forward) currPos = firstForward;
		else if (firstBackward != -1 && !forward) currPos = firstBackward;

		ResetGUI(Attack);
	}

	// Reset all of the GUI elements according to given tab and current instrument index
	void AddSynAudioProcessorEditor::ResetGUI(Tab tab)
	{
		AddSynAudioProcessor* proc = getProcessor();
		Levels levels = proc->getLevels(currPos);
		WaveType wavetype = proc->getWaveType(currPos);

		uxName->setText(juce::String(currPos));

		if (tab == Attack)
		{
			uxSlider1->setValue(levels.attackValues[0]);
			uxSlider2->setValue(levels.attackValues[1]);
			uxSlider3->setValue(levels.attackValues[2]);
			uxSlider4->setValue(levels.attackValues[3]);
			uxSlider5->setValue(levels.attackValues[4]);
			uxSlider6->setValue(levels.attackValues[5]);
			uxSlider7->setValue(levels.attackValues[6]);
			uxSlider8->setValue(levels.attackValues[7]);
			uxSlider9->setValue(levels.attackValues[8]);
			uxSlider10->setValue(levels.attackValues[9]);
			uxSlider11->setValue(levels.attackValues[10]);
			uxSlider12->setValue(levels.attackValues[11]);
		}
		else if (tab == Sustain)
		{
			uxSlider1->setValue(levels.sustainValues[0]);
			uxSlider2->setValue(levels.sustainValues[1]);
			uxSlider3->setValue(levels.sustainValues[2]);
			uxSlider4->setValue(levels.sustainValues[3]);
			uxSlider5->setValue(levels.sustainValues[4]);
			uxSlider6->setValue(levels.sustainValues[5]);
			uxSlider7->setValue(levels.sustainValues[6]);
			uxSlider8->setValue(levels.sustainValues[7]);
			uxSlider9->setValue(levels.sustainValues[8]);
			uxSlider10->setValue(levels.sustainValues[9]);
			uxSlider11->setValue(levels.sustainValues[10]);
			uxSlider12->setValue(levels.sustainValues[11]);
		}
		else
		{
			uxSlider1->setValue(levels.releaseValues[0]);
			uxSlider2->setValue(levels.releaseValues[1]);
			uxSlider3->setValue(levels.releaseValues[2]);
			uxSlider4->setValue(levels.releaseValues[3]);
			uxSlider5->setValue(levels.releaseValues[4]);
			uxSlider6->setValue(levels.releaseValues[5]);
			uxSlider7->setValue(levels.releaseValues[6]);
			uxSlider8->setValue(levels.releaseValues[7]);
			uxSlider9->setValue(levels.releaseValues[8]);
			uxSlider10->setValue(levels.releaseValues[9]);
			uxSlider11->setValue(levels.releaseValues[10]);
			uxSlider12->setValue(levels.releaseValues[11]);
		}

		uxAttackSlider->setValue(levels.attackRate);
		uxReleaseSlider->setValue(levels.releaseRate);
		uxSustainSlider->setValue(levels.sustainRate);
		uxSustainButton->setToggleState(levels.isSustain, new NotificationType());

		setWaveTypeGUI(wavetype);
	}

	void AddSynAudioProcessorEditor::setWaveTypeGUI(WaveType wt)
	{
		// Only allow one wavetype to be selected
		uxSineButton->setToggleState(false, juce::NotificationType());
		uxTriangleButton->setToggleState(false, juce::NotificationType());
		uxSquareButton->setToggleState(false, juce::NotificationType());
		uxSawButton->setToggleState(false, juce::NotificationType());

		if (wt == Sine)
		{
			uxSineButton->setToggleState(true, juce::NotificationType());
		}
		else if (wt == Triangle)
		{
			uxTriangleButton->setToggleState(true, juce::NotificationType());
		}
		else if (wt == Square)
		{
			uxSquareButton->setToggleState(true, juce::NotificationType());
		}
		else
		{
			uxSawButton->setToggleState(true, juce::NotificationType());
		}
	}

	Tab AddSynAudioProcessorEditor::getCurrentTab()
	{
		if (uxTabs->getCurrentTabName() == "Attack") return Attack;
		else if (uxTabs->getCurrentTabName() == "Sustain") return Sustain;
		else return Release;
	}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AddSynAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="AddSynAudioProcessor&amp; ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffaea2a2"/>
  <TABBEDCOMPONENT name="uxTabs" id="2611b740ea85765c" memberName="uxTabs" virtualName=""
                   explicitFocusOrder="0" pos="16 48 288 224" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="Attack" colour="ffce3838" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Sustain" colour="ff07c046" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Release" colour="ff0c0ea8" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <SLIDER name="uxSlider1" id="c2f0fd34eb464ed7" memberName="uxSlider1"
          virtualName="" explicitFocusOrder="0" pos="16 88 23 184" min="0"
          max="9" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxSlider2" id="b623ff4a4fc6be2" memberName="uxSlider2"
          virtualName="" explicitFocusOrder="0" pos="40 88 23 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxSlider3" id="9c27aafe20719efc" memberName="uxSlider3"
          virtualName="" explicitFocusOrder="0" pos="64 88 23 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxSlider4" id="33ba5a9f81e1224b" memberName="uxSlider4"
          virtualName="" explicitFocusOrder="0" pos="88 88 23 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxSlider5" id="b91e3611b5a4511f" memberName="uxSlider5"
          virtualName="" explicitFocusOrder="0" pos="112 88 23 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxSlider6" id="17f268caa59ccf84" memberName="uxSlider6"
          virtualName="" explicitFocusOrder="0" pos="136 88 23 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxSlider7" id="2d66a2f0787933a6" memberName="uxSlider7"
          virtualName="" explicitFocusOrder="0" pos="160 88 23 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxSlider8" id="875f6d0cd9506171" memberName="uxSlider8"
          virtualName="" explicitFocusOrder="0" pos="184 88 23 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxSlider9" id="9fdf82fe5c247c77" memberName="uxSlider9"
          virtualName="" explicitFocusOrder="0" pos="208 88 23 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxSlider10" id="f5b76a3051889417" memberName="uxSlider10"
          virtualName="" explicitFocusOrder="0" pos="232 88 23 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxSlider11" id="d5dbb70ea1b26dda" memberName="uxSlider11"
          virtualName="" explicitFocusOrder="0" pos="256 88 23 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxSlider12" id="99d5b5b537f41220" memberName="uxSlider12"
          virtualName="" explicitFocusOrder="0" pos="280 88 23 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="uxLeftButton" id="7cea6a0e7fd85c52" memberName="uxLeftButton"
              virtualName="" explicitFocusOrder="0" pos="8 8 31 24" buttonText="&lt;"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="uxName" id="758b022a6f99cbeb" memberName="uxName" virtualName=""
              explicitFocusOrder="0" pos="80 8 158 24" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTBUTTON name="uxRightButton" id="af1d2284bc1e614f" memberName="uxRightButton"
              virtualName="" explicitFocusOrder="0" pos="40 8 32 24" buttonText="&gt;"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="uxCreateInstrument" id="622bc8e38a604465" memberName="uxCreateInstrument"
              virtualName="" explicitFocusOrder="0" pos="248 8 32 24" textColOn="ff077c24"
              buttonText="+" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="uxDestroyInstrument" id="ccf53c0dfab64dda" memberName="uxDestroyInstrument"
              virtualName="" explicitFocusOrder="0" pos="280 8 32 24" textColOn="fffd0000"
              buttonText="x" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="uxSineButton" id="8714c20a01cd6bb6" memberName="uxSineButton"
                virtualName="" explicitFocusOrder="0" pos="24 288 56 24" buttonText="Sine"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="uxTriangleButton" id="2d0c5343bc4a811d" memberName="uxTriangleButton"
                virtualName="" explicitFocusOrder="0" pos="88 288 64 24" buttonText="Triangle"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="uxSquareButton" id="8767e706be00dd68" memberName="uxSquareButton"
                virtualName="" explicitFocusOrder="0" pos="168 288 64 24" buttonText="Square"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="uxSawButton" id="2084b9b8cb90582f" memberName="uxSawButton"
                virtualName="" explicitFocusOrder="0" pos="248 288 64 24" buttonText="Saw"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="uxAttackSlider" id="2295b727f9479e61" memberName="uxAttackSlider"
          virtualName="" explicitFocusOrder="0" pos="304 80 64 48" min="0"
          max="10" int="0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="uxReleaseSlider" id="cef7c00c399fee98" memberName="uxReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="304 136 64 48" min="0"
          max="10" int="0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="uxAttackLabel" id="ee617925784fb64d" memberName="label"
         virtualName="" explicitFocusOrder="0" pos="376 88 79 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="uxReleaseLabel" id="fd9d0e1ffe0c86ea" memberName="label2"
         virtualName="" explicitFocusOrder="0" pos="376 144 79 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="uxSustainSlider" id="ffee8eede01c4f9e" memberName="uxSustainSlider"
          virtualName="" explicitFocusOrder="0" pos="304 192 64 48" min="0"
          max="10" int="0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="uxReleaseLabel" id="c9461fd4fb8c08" memberName="label3"
         virtualName="" explicitFocusOrder="0" pos="376 200 79 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="uxSustainButton" id="140b6db1460d230e" memberName="uxSustainButton"
                virtualName="" explicitFocusOrder="0" pos="344 248 64 24" buttonText="Sustain"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TEXTBUTTON name="uxLeftButton" id="4f647f6abde1fec6" memberName="uxLeftButton2"
              virtualName="" explicitFocusOrder="0" pos="336 8 48 24" buttonText="Save"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="uxRightButton" id="5edea518d5f72e0b" memberName="uxRightButton2"
              virtualName="" explicitFocusOrder="0" pos="384 8 48 24" buttonText="Load"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="MIDI Keyboard" id="a2d2fd3359bafd05" memberName="midiKeyboard"
                    virtualName="" explicitFocusOrder="0" pos="16 320 432 64" class="Component"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
