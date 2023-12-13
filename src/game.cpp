#include "game.h"

Game::Game() {
    //sets background for arena
    bg_texture.loadFromFile("../assets/img/background.jpg");
    background.setTexture(bg_texture);
    background.setScale(1.25, 1.4);

    //sets background for menu
    mainMenuT.loadFromFile("../assets/img/background1.jpg");
    mainMenuS.setTexture(mainMenuT);
    mainMenuS.setScale(0.85, 0.8);

    //creating 2 pointers to opponents
    opponents = new Opponent* [2];
    opponents[0] = new Opponent();
    opponents[1] = nullptr;

    //open file
    scoreFile = fopen("../assets/highscores.txt", "r");
    char temp[10];
    //store highscores in string
    fgets(temp, 10, scoreFile);
    //convert string to int and store in highscores
    highscores = std::stoi(temp);
    //close file
    fclose(scoreFile);

    menu.updateHighScores(highscores);

}

Game::~Game() {
    //delete opponents
    delete opponents[0];
    delete opponents[1];
    //delete pointer to opponents
    delete [] opponents;
}

void Game::saveHighscores() {
    //open file
    scoreFile = fopen("../assets/highscores.txt", "w");
    //store highscores in string
    std::string temp = std::to_string(scores);
    //write string to file
    std::cout << "Value to be saved: " << temp << std::endl;
    fprintf(scoreFile, temp.c_str());
    //close file
    fclose(scoreFile);
}

void Game::update(sf::RenderWindow& target_w) {
    target_w.clear(sf::Color::Black);

    //level is drawn below, rest of the things are drawn at top as necessary
    target_w.draw(background);
    arena.render(target_w);
    player.render(target_w);
    opponents[0]->render(target_w);
    menu.renderGUI(target_w);

    switch(state) {

        case GameState::MainMenu:
            target_w.draw(mainMenuS);
            menu.renderMenu(target_w, false);
            break;

        case GameState::Playing:
            break;

        case GameState::Paused:
            menu.renderMenu(target_w, true);
            break;

        case GameState::Highscores:
            target_w.draw(mainMenuS);
            menu.renderHighScores(target_w);
            break;

        case GameState::Help:
            target_w.draw(mainMenuS);
            menu.renderHelp(target_w);
            break;
    }

    target_w.display();
}

void Game::menuControls(const sf::Event::KeyEvent& e, sf::RenderWindow& target_w) {

    switch (e.code) {

        case sf::Keyboard::Num1:    //start game
            if (!(state == GameState::Paused || state == GameState::MainMenu))
                break;
            
            prevState = state;
            state = GameState::Playing;
            level = 1;
            resetLevel(target_w);
            break;

        case sf::Keyboard::Num2:    //highscores
            prevState = state;
            state = GameState::Highscores;
            break;

        case sf::Keyboard::Num3:    //help
            prevState = state;
            state = GameState::Help;
            break;

        case sf::Keyboard::Num4:    //exit
            prevState = state;
            if (scores > highscores)
                saveHighscores();
            target_w.close();
            break;

        case sf::Keyboard::Num5:    //continue
            prevState = state;
            state = GameState::Playing;
            break;

        case sf::Keyboard::P:  //pause
            prevState = state;
            if (state == GameState::Playing)
                state = GameState::Paused;
            break;

        case sf::Keyboard::Escape:  //escape
            if(state == GameState::Highscores || state == GameState::Help){
                if((prevState == GameState::Paused))
                    state = GameState::Playing;
                else
                    state = GameState::MainMenu;
            }
            prevState = state;
            break;
            
        default:
            break;
    }

}

void Game::handleEvents(const sf::Event& e, sf::RenderWindow& target_w) {
    switch (e.type) {

        case sf::Event::Closed:
            if (scores > highscores)
                saveHighscores();
            target_w.close();
            break;

        case sf::Event::KeyPressed:
            menuControls(e.key, target_w);
            if (state == GameState::Playing)
                control(e.key);
            break;

        default:
            break;
    }
}

void Game::control(const sf::Event::KeyEvent& e) {

    for (int i = 0; i < 4; i++) {
        if (player.getAppearance()->getGlobalBounds().intersects(arena.getArenaTile(i)->getGlobalBounds())) {
            return;
        }
    }

    int direction = player.getDirection();
    int track = player.getTrackID();

    switch (e.code) {
        case sf::Keyboard::Up:
            if (direction == Car::Direction::Left && track < 3)
                player.setTrackID(track + 1);
            else if (direction == Car::Direction::Right && track > 0)
                player.setTrackID(track - 1);
            break;

        case sf::Keyboard::Down:
            if (direction == Car::Direction::Left && track > 0)
                player.setTrackID(track - 1);
            else if (direction == Car::Direction::Right && track < 3)
                player.setTrackID(track + 1);
            break;

        case sf::Keyboard::Left:
            if (direction == Car::Direction::Up && track > 0)
                player.setTrackID(track - 1);
            else if (direction == Car::Direction::Down && track < 3)
                player.setTrackID(track + 1);
            break;

        case sf::Keyboard::Right:
            if (direction == Car::Direction::Up && track < 3)
                player.setTrackID(track + 1);
            else if (direction == Car::Direction::Down && track > 0)
                player.setTrackID(track - 1);
            break;

        default:
            break;
    }

    track = player.getTrackID();

    player.updateTrack(arena.getTrack(track)->getCorners());
    
}

void Game::resetPerks() {
    //back to default values
    player.setSpeed(5);
    //rescale opponent back to original from 0
    opponents[0]->getAppearance()->setScale(0.05, 0.05);
}

void Game::resetLevel(sf::RenderWindow& target_w) {

    arena.setFoodLeft(8 * 8);                   //reset foodcount
    resetPerks();                               //reset perks
    arena.populateFoodMap();                    //repopulate food
    arena.foodDistribution();                   //reinitialize food
    menu.updateLives(3);                        //reset lives text
    menu.updateScores(0);                       //reset scores text
    player.setTrackID(0);                       //reset player track
    player.setDirection(Car::Direction::Right); //reset player direction
    
    player.initialize(sf::Vector2f(             //reset player position
        target_w.getSize().x / 2,
        arena.getTrack(0)->corner[0].position.y
    ));

    for (int i = 0; i < 2; i++) {               //reset opponents
        if (opponents[i] != nullptr) {
            opponents[i]->setTrackID(0);
            opponents[i]->setDirection(Car::Direction::Down);
            opponents[i]->initialize(sf::Vector2f(
                arena.getTrack(0)->corner[0].position.x,
                target_w.getSize().y / 2
            ));
        }
    }

}

void Game::updateLevel(sf::RenderWindow& target_w) {
    resetLevel(target_w);

    level++;                        //increment level
    scores += 100;                  //increment score
    menu.updateLevel(level);        //update level on menu
    menu.updateLives(player.getLives()); //update lives on menu
    menu.updateScores(scores);      //update scores on menu
}

void Game::initialize(sf::RenderWindow& target_w) {

    arena.initialize(target_w);

    player.initialize(sf::Vector2f(
        target_w.getSize().x / 2,                   //horizontal center of screen
        arena.getTrack(0)->corner[0].position.y     //Track 0 Top
    ));

    opponents[0]->initialize(sf::Vector2f(
        arena.getTrack(0)->corner[0].position.x,    //Track 0 Left
        target_w.getSize().y / 2                    //vertical center of screen
    ));
}

void Game::updateDisplayValues() {
    menu.updateLevel(level);
    menu.updateScores(scores);
    menu.updateLives(player.getLives());
    menu.updateHighScores(highscores);

    //overwrite if current scores are higher
    if (scores > highscores)
        menu.updateHighScores(scores);
}

void Game::start_game() {

    sf::RenderWindow gameWindow(sf::VideoMode(1000, 700), TITLE);

    initialize(gameWindow);

    sf::Clock frameTicks, physicsTicks, foodPerkTicks;
    float fps = 60;     //frames per second

    int deltaTime = 0;

    while (gameWindow.isOpen()) {

        bool allowTrackChange;
        float timer = frameTicks.getElapsedTime().asMilliseconds();
        sf::Event e;

        while (gameWindow.pollEvent(e)) {
            handleEvents(e, gameWindow);
        }

        if (
            physicsTicks.getElapsedTime().asMilliseconds() >= 20 && 
            player.isAlive() && 
            state == GameState::Playing
        ) {

            for (int i = 0; i < 2; i++) {
                if (opponents[i] != nullptr) {

                    int oppoTrackID = opponents[i]->getTrackID();
                    Track* oppoTrack = arena.getTrack(oppoTrackID);

                    opponents[i]->update(oppoTrack->getCorners());
                    
                    bool colliding = false;

                    for (int j = 0; j < 4; j++) {
                        if (opponents[i]->getAppearance()->getGlobalBounds().intersects(arena.getArenaTile(j)->getGlobalBounds())) {
                            colliding = true;
                            allowTrackChange = true;
                            break;
                        }
                    }

                    if (!colliding && allowTrackChange) {
                        opponents[i]->control(level);
                        oppoTrackID = opponents[i]->getTrackID();
                        oppoTrack = arena.getTrack(oppoTrackID);
                        opponents[i]->updateTrack(oppoTrack->getCorners());
                        allowTrackChange = false;
                    }


                    if (opponents[i]->kills(player))
                        std::cout << "Player killed by opponent " << i << std::endl;
                    
                }
            }

            int trackID = player.getTrackID();
            Track* currentTrack = arena.getTrack(trackID);

            player.update(currentTrack->getCorners());
            arena.foodConsumption(player, scores, *opponents[0], foodPerkTicks);
            
            if(arena.getFoodLeft() == 0 && level < 4)
                updateLevel(gameWindow);

            updateDisplayValues();

            deltaTime += foodPerkTicks.getElapsedTime().asMilliseconds();
            if(deltaTime >= 10*1000) {
                deltaTime = 0;
                resetPerks();
            }

            foodPerkTicks.restart();
            physicsTicks.restart();
        }

        if (timer >= 1.0 / fps * 1000) {
            update(gameWindow);
            frameTicks.restart();
        }
    }
}