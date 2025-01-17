/*#include "Participant.h"

std::vector<ANewBlock> UParticipant::allBlocks;
int UParticipant::currentBlock = 0;
int UParticipant::participantNumber;
FString UParticipant::dataPathLocation = FString(FPlatformProcess::UserDir()) + "\\GameData\\";

UParticipant::UParticipant() {

	incrementParticipantNumber(dataPathLocation + "dataInputFile.txt");
	participantNumber = getParticipantNumberFromFile(dataPathLocation + "dataInputFile.txt");

	
	createStatsFile(dataPathLocation + "Stats\\", "PN" + FString::FromInt(participantNumber) + "stats.txt");

	//ANewBlock* block1Pointer = NewObject<ANewBlock>();
	//UDatabaseCommunicatorModel* Model = Cast(Query->QueryModel);
	//allBlocks.push_back(block1);
}

UParticipant::~UParticipant() {}

void UParticipant::setParticipantNumber(int number) {
	participantNumber = number;
}

int UParticipant::getParticipantNumber() {
	return this->participantNumber;
}

void UParticipant::incrementCurrentBlock() {
	currentBlock = currentBlock++;
}

int UParticipant::getCurrentBlock() {
	return this->currentBlock;
}

FString UParticipant::printAllBlocks() {
	FString output = "* Participant " + FString::FromInt(participantNumber) + " Data *" + "\n";

	for (int i = 0; i < allBlocks.size(); i++) {
		output += allBlocks[i].printBlock();
	}

	output += "* Participant " + FString::FromInt(participantNumber) + " Data Completed -\n";

	return output;
}

FString UParticipant::printStats() {
	FString output = "\nSTATS\nAccuracy: " 
		+ FString::SanitizeFloat(participantAccuracy) + "%\nReaction Time: "
		+ FString::FromInt(participantRT) + "ms\nCorrect: " + FString::FromInt(participantCorrect) + " / " + FString::FromInt(participantTotal) + "\n";

	return output;
}

void UParticipant::printParticipant() {
	FString filePath = "participant" + FString::FromInt(participantNumber);
	FString content = printAllBlocks() + printStats();
	rewriteFile(filePath, content);
}

int UParticipant::retrieveParticipantNumber() {
	return getParticipantNumberFromFile(dataPathLocation + "dataInputFile.txt");
}

void UParticipant::writeTrialStats() {
	FString content = "\n" + ANewBlock::getStats();
	writeToFile(dataPathLocation + "\\Stats\\PN" + FString::FromInt(participantNumber) + "stats.txt", content);
}

//UParticipant participant1;
*/