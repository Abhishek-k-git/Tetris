#include "UI.hpp"
#include "Board.hpp"

UI::UI(){
	Board board;

	if (!font.loadFromFile("font/ka.ttf")) {
		std::cerr << "Error loading font 'font/ka.ttf'. Using a default font.\n";
		font.loadFromFile("default_font.ttf");
	}

	float centerX = board.getScreenWidth() / 2.0f;
	
	scoreTextTitle.setFont(font);
	scoreTextTitle.setFillColor(Color::White);
	scoreTextTitle.setPosition(Vector2f(centerX + 80.0f, 25.0f));
	scoreTextTitle.setString("Score");
	
	maxScoreTextTitle.setFont(font);
	maxScoreTextTitle.setFillColor(Color::White);
	maxScoreTextTitle.setPosition(Vector2f(centerX + 70.0f, 200.0f));
	maxScoreTextTitle.setString("High Score");
	maxScoreTextTitle.setCharacterSize(20);
	
	scoreText.setFont(font);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(Vector2f(centerX + 95.0f, 70.0f));
	
	maxScoreText.setFont(font);
	maxScoreText.setFillColor(Color::White);
	maxScoreText.setPosition(Vector2f(centerX + 95.0f, 235.0f));
	
	byText.setFont(font);
	byText.setFillColor(Color::White);
	byText.setPosition(Vector2f(centerX + 40.0f, 470.0f));
	byText.setString("Tetris");
	byText.setCharacterSize(45);

	gameOverText.setFont(font);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition(Vector2f(55.0f, 250.0f));
	gameOverText.setString("Game Over");
	gameOverText.setCharacterSize(25);	
	
	newScoreText.setFont(font);
	newScoreText.setFillColor(Color::White);
	newScoreText.setPosition(Vector2f(65.0f, 350.0f));
	newScoreText.setString("New High");
	newScoreText.setCharacterSize(25);	
	
}

void UI::SetScore(int x){
	if(x <= 9) scoreText.setString("000" + to_string(x));
	else if(x <= 99) scoreText.setString("00" + to_string(x));
	else if(x <= 999) scoreText.setString("000" + to_string(x));
	else if(x <= 9999) scoreText.setString(to_string(x));
	else scoreText.setString("9999");
}


void UI::SetMaxScore(int x){
	if(x <= 9) maxScoreText.setString("000" + to_string(x));
	else if(x <= 99) maxScoreText.setString("00" + to_string(x));
	else if(x <= 999) maxScoreText.setString("000" + to_string(x));
	else if(x <= 9999) maxScoreText.setString(to_string(x));
	else maxScoreText.setString("9999");
}

void UI::GameOver(){
	gameOver = 1;
}


void UI::NewScore(){
	newScore = 1;
}

void UI::draw(RenderTarget &rt, RenderStates rs) const {
	rt.draw(scoreTextTitle, rs);
	rt.draw(scoreText, rs);
	rt.draw(maxScoreTextTitle, rs);
	rt.draw(maxScoreText, rs);
	rt.draw(byText, rs);
	if(gameOver) rt.draw(gameOverText, rs);
	if(newScore) rt.draw(newScoreText, rs);
}

