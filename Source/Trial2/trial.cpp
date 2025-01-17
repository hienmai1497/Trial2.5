#include "Trial.h"

int Trial::totalTrials;

Trial::Trial(FString stimulusWord, FString stimulusColor)
{
	stimulus = stimulusWord;
	color = stimulusColor;
	trialNumber = -1;

	if (stimulus == color) {
		isCongruentTrial = true;
	}
	else {
		isCongruentTrial = false;
	}

	if (color == "red") {
		correctLane = 1;
	}
	else if (color == "blue") {
		correctLane = 2;
	}
	else if (color == "green") {
		correctLane = 3;
	}
	else if (color == "yellow") {
		correctLane = 4;
	}
	else {}
}


Trial::~Trial()
{
}

FString Trial::printTrial() {
	FString output =
		"  *** TRIAL " + FString::FromInt(this->getTrialNumber()) + " ***" + "\n" +
		"    stimulus text: " + stimulus + "\n"
		"    stimulus color: " + color + "\n"
		"    lane selected: " + FString::FromInt(selectedLane) + "\n"
		"    correct: " + FString::FromInt(correctLane) + "\n"
		"    reaction time: " + FString::SanitizeFloat(reactionTime * 1000) + "\n";
	return output;
}


FString Trial::getTrialStats() {
	int levelNumber = 0; // addable in the future
	int roundedRT; // the reaction time in in ms as a float, we're changing it to a rounded ms
	roundedRT = FMath::FloorToInt(reactionTime * 100000) / 100;
	FString congruent, correct, output;
	congruent = (isCongruentTrial) ? "1" : "0";
	correct = (correctLane == selectedLane) ? "1" : "0";
	output = FString::FromInt(levelNumber) + "," + FString::FromInt(trialNumber) + "," + color + "," + stimulus + "," + congruent + "," + correct + ","
		+ FString::FromInt(selectedLane) + "," + FString::FromInt(correctLane) + "," + FString::FromInt(roundedRT);

	return output;
}

void Trial::setTrialNumber(int number) {
	this->trialNumber = number;
}

int Trial::getTrialNumber() {
	return trialNumber;
}

FString Trial::getColor() {
	return color;
}

FString Trial::getStimulus() {
	return stimulus;
}

int Trial::getCorrectLane() {
	return correctLane;
}

void Trial::getResponse(int laneSelected, float reactTime) {

	// send data to dataStream


	// get Elapsed time
	reactionTime = reactTime;

	selectedLane = laneSelected;
}