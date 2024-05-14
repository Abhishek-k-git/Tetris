#include "Sounds.hpp"

Sounds::Sounds(){
	if (!music.openFromFile("sounds/music.ogg")) {
		cout << "Error loading music" << endl;
	}

	music.setLoop(true);
	music.setVolume(20);
	
	if(!lineSoundBuffer.loadFromFile("sounds/line.ogg")) {
		cout << "Error loading line sound" << endl;
	}
	
	if(!newScoreSoundBuffer.loadFromFile("sounds/newScore.ogg")) {
		cout << "Error loading new score sound" << endl;
	}
	
	if(!gameOverSoundBuffer.loadFromFile("sounds/gameOver.ogg")) {
		cout << "Error loading game over sound" << endl;
	}
	
	lineSound.setBuffer(lineSoundBuffer);
	newScoreSound.setBuffer(newScoreSoundBuffer);
	gameOverSound.setBuffer(gameOverSoundBuffer);
}

void Sounds::PlayMusic(){
	music.play();
}

void Sounds::PauseMusic(){
	music.pause();
}

void Sounds::PlayLine(){
	lineSound.play();
}

void Sounds::PlayNewScore(){
	newScoreSound.play();
}
void Sounds::PlayGameOver(){
	gameOverSound.play();
}
