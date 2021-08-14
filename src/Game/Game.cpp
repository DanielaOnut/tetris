//
// Created by loghin on 16.04.2021.
//

#include "Game.h"
#include "Shop.h"
#include "Util.h"
#include "CurrentSettings.h"

SquareTexture::TextureType findEquippedItem () {
    if (Shop::verifyIfItemIsPurchased("Rainbow Square") == "purchased and equipped")
        return SquareTexture::TextureType::RAINBOW;
    if (Shop::verifyIfItemIsPurchased("Black Square") == "purchased and equipped")
        return SquareTexture::TextureType::BLACK;
    if (Shop::verifyIfItemIsPurchased("White Square") == "purchased and equipped")
        return SquareTexture::TextureType::WHITE;
    if (Shop::verifyIfItemIsPurchased("Brown Square") == "purchased and equipped")
        return SquareTexture::TextureType::BROWN;
    return SquareTexture::TextureType::STANDARD;
}

void Game::init() noexcept {
    this->createComponents();
    this->alignComponents();
    this->adjustComponents();
    this->styleComponents();
    this->connectComponents();

    this->gameBoard->setVerticalMargin(5);
    this->gameBoard->setHorizontalMargin(5);

    this->queue->setVerticalMargin(20);
    this->queue->setHorizontalMargin(20);

    SquareTexture::TextureType equippedItemTex = findEquippedItem();
    SquareTexture::switchToTexture(equippedItemTex);
    this->gameBoard->init();
    this->gameBoard->dropActiveShape();

    this->queue->init();
    this->queue->generateInitial();

    this->pauseLabel->setVisible(false);
}

void Game::createComponents() noexcept {
    this->generalLayout = new QHBoxLayout(nullptr);
    this->figuresQueueLayout = new QVBoxLayout (nullptr);
    this->boardLayout = new QHBoxLayout (nullptr);
    this->dataLayout = new QVBoxLayout (nullptr);

    this->scoreLabel = new QLabel (this->scoreLabelText,this);
    std::string timeText;
    timeText.append("Time played: ").append(std::to_string(this->timePassed)).append(" s");
    this->timeLabel = new QLabel (timeText.c_str(), this);
    this->quitButton = new NoKeyButton (this->quitButtonText, this);

    this->gameBoard = new Board(this);

    this->queueLabel = new QLabel (this->queueLabelText, this);
    this->queue = new Queue (this);
    this->pauseLabel = new QLabel (this->pauseLabelText, this);
    this->pauseButton = new NoKeyButton (this);

    this->shapeFallTimer = new QTimer(this);

    this->moveRightSignalGenerator = new QTimer(this);
    this->moveLeftSignalGenerator = new QTimer(this);
    this->dropSignalGenerator = new QTimer(this);

    this->pIncTimer = new QTimer(this);
}

void Game::alignComponents() noexcept {
    this->setLayout(this->generalLayout);

    this->generalLayout->addItem(this->dataLayout);
    this->generalLayout->addItem(this->boardLayout);
    this->generalLayout->addItem(this->figuresQueueLayout);

    this->dataLayout->addWidget(this->scoreLabel);
    this->dataLayout->addWidget(this->timeLabel);
    this->dataLayout->addWidget(this->quitButton);

    this->boardLayout->addWidget(this->gameBoard);

    this->figuresQueueLayout->addWidget(this->queueLabel);
    this->figuresQueueLayout->addWidget(this->queue);
    this->figuresQueueLayout->addWidget(this->pauseLabel);
    this->figuresQueueLayout->addWidget(this->pauseButton);

    this->dataLayout->setAlignment(this->quitButton, Qt::AlignBottom | Qt::AlignLeft);
    this->dataLayout->setAlignment(this->scoreLabel, Qt::AlignLeft);
    this->dataLayout->setAlignment(this->timeLabel, Qt::AlignTop | Qt::AlignLeft);
    this->dataLayout->setSpacing (7);

    this->boardLayout->setAlignment(this->gameBoard, Qt::AlignHCenter | Qt::AlignTop);

    this->figuresQueueLayout->setAlignment(this->queueLabel, Qt::AlignLeft);
    this->figuresQueueLayout->setAlignment(this->queue, Qt::AlignTop);
    this->figuresQueueLayout->setAlignment(this->pauseButton, Qt::AlignLeft);
    this->figuresQueueLayout->setAlignment(this->pauseLabel, Qt::AlignBottom);
}

void Game::adjustComponents() noexcept {
    this->moveRightSignalGenerator->setInterval(100);
    this->moveLeftSignalGenerator->setInterval(100);
    this->pIncTimer->setInterval(1000);

    if (CurrentSettings::instance().general().difficulty == CurrentSettings::EASY) {
        this->shapeFallTimer->setInterval(1300);
        this->dropSignalGenerator->setInterval(60);
    }
    if (CurrentSettings::instance().general().difficulty == CurrentSettings::NORMAL) {
        this->shapeFallTimer->setInterval(650);
        this->dropSignalGenerator->setInterval(40);
    }
    if (CurrentSettings::instance().general().difficulty == CurrentSettings::HARD) {
        this->shapeFallTimer->setInterval(325);
        this->dropSignalGenerator->setInterval(20);
    }

    this->quitButton->setMinimumWidth(130);
    this->quitButton->setMaximumWidth(130);

    this->pauseButton->setMinimumWidth(40);
    this->pauseButton->setMaximumWidth(40);
    this->pauseButton->setMinimumHeight(40);
    this->pauseButton->setMaximumHeight(40);
}

void Game::styleComponents() noexcept {
    this->quitButton->setStyleSheet(Util::getStyle("ExitButton.css").c_str());
    this->quitButton->setIcon(Util::getIcon("quitButtonIcon.png", 20, 20));

    this->queueLabel->setStyleSheet(Util::getStyle("NextLabel.css").c_str());
    this->pauseLabel->setStyleSheet(Util::getStyle("PauseLabel.css").c_str());
    this->scoreLabel->setStyleSheet(Util::getStyle("ScoreLabel.css").c_str());
    this->timeLabel->setStyleSheet(Util::getStyle("TimeLabel.css").c_str());

    this->pauseButton->setIcon(Util::getIcon("pauseButtonIcon.png", 50, 50));
    this->pauseButton->setIconSize(QSize(50, 40));
}

#include <iostream>

static bool pauseButtonCliked = false;
static int pauseButtonClikedCounter = 0;

#include <chrono>
#include <ctime>

void Game::connectComponents() noexcept {
//    auto time = std::chrono::high_resolution_clock::now();
//    std::chrono::
//    auto minutes = std::chrono::duration(time - std::ratio < 60, 1 >());
//    auto sec = time(nullptr);
//    auto timeInfo = localtime(& sec);
//    timeInfo.

    QObject::connect( this->pIncTimer, & QTimer::timeout, [this] {
        this->timePassed++;
        std::string timeText;
        if (! this->gamePlayedForMinutes && ! this->gamePlayedForHours) {
            if (this->timePassed <= 59)
                timeText.append("Time played: ").append(std::to_string(this->timePassed)).append(" s");
            else if (this->timePassed > 59) {
                this->gamePlayedForMinutes = true;
                this->pIncTimer->setInterval(60000);
                this->timePassed = 1;
                timeText.append("Time played: ").append(std::to_string(this->timePassed)).append(" min");
            }
        }
        else if (! this->gamePlayedForHours) {
            if (this->timePassed <= 59)
                timeText.append("Time played: ").append(std::to_string(this->timePassed)).append(" mins");
            else if (this->timePassed > 59) {
                this->gamePlayedForHours = true;
                this->pIncTimer->setInterval(3600000);
                this->timePassed = 1;
                timeText.append("Time played: ").append(std::to_string(this->timePassed)).append(" h");
            }
        }
        else
            timeText.append("Time played: ").append(std::to_string(this->timePassed)).append(" h");
        this->timeLabel->setText(timeText.c_str());
    } );
    this->pIncTimer->start();

    connect (this->pauseButton, & QPushButton::clicked, [this] {
        if (pauseButtonClikedCounter % 2 == 0) {
            pauseButtonCliked = true;
            this->pauseLabel->setVisible(true);
            this->shapeFallTimer->stop();
            if (this->moveRightSignalGenerator->isActive())
                this->moveRightSignalGenerator->stop();
            if (this->moveLeftSignalGenerator->isActive())
                this->moveLeftSignalGenerator->stop();
            if (this->dropSignalGenerator->isActive())
                this->dropSignalGenerator->stop();
        }
        else {
            pauseButtonCliked = false;
            this->pauseLabel->setVisible(false);
            this->shapeFallTimer->start();
        }
        pauseButtonClikedCounter++;
        this->setFocus();
    });

    connect (this->quitButton, & QPushButton::clicked, [this] {
        this->saveData();
        emit this->quit(this->gameScore);
        pauseButtonCliked = false;
        pauseButtonClikedCounter = 0;
    } );

    connect(this->shapeFallTimer, & QTimer::timeout, [this]{ this->gameBoard->dropActiveShape();});

    connect(this->moveRightSignalGenerator, & QTimer::timeout, [this]{
        emit this->moveRight();
    });

    connect(this->moveLeftSignalGenerator, & QTimer::timeout, [this]{
        emit this->moveLeft();
    });

    connect(this->dropSignalGenerator, & QTimer::timeout, [this] { this->gameBoard->dropActiveShape();});

    this->shapeFallTimer->start();
}

void Game::setGameOverWindow() noexcept {
    emit this->gameOverSignal(this->gameScore);
}

void Game::editScore (int x) noexcept {
    this->gameScore += x;

    char str[30];
    std::sprintf(str, "Score: %d", this->gameScore);
    this->scoreLabel->setText (str);

//    this->scoreLabel->setText ( ( std::string ("Score: ") + std::to_string(this->gameScore) ).c_str() );
//    this->scoreLabel->setText ( QString ("Score: ") + QString::number ( this->gameScore, 10 ) );
}

std::list <std::string> Game::isDataInFile () noexcept {
    std::list <std::string> list;
    std::fstream dataFile;
    dataFile.open("StatisticsData.txt", std::ios::in);
    try {
        std::string buffer = "empty";
        int dataNumber = 4;
        while (dataNumber--) {
            std::getline (dataFile, buffer);
            if (buffer != "empty")
                list.push_back(buffer);
        }
        dataFile.close();
        return list;
    }
    catch (std::exception const & e) {
        dataFile.close();
        return list;
    }
}

std::pair <int, std::string> timeConvertor (std::string const & string) noexcept {
    std::pair <int, std::string> pair;
    char * timeValue = const_cast <char *> (string.c_str());
    char * timeUnit = strchr (string.c_str(), ' ') + 1;
    * (timeUnit - 1) = 0;
    pair.first = std::strtol (timeValue, nullptr, 10);
    pair.second = timeUnit;
    return pair;
}

void Game::saveData() noexcept {
    auto dataList = Game::isDataInFile();
    std::fstream dataFile;
    dataFile.open ("StatisticsData.txt", std::ios::trunc | std::ios::out);
    if (dataList.empty()) {
        dataFile << this->gameScore << '\n';
        dataFile << '-' << '\n';
        std::string timePlayed, timeLabelText;
        timeLabelText = this->timeLabel->text().toStdString();
        timePlayed = strstr (timeLabelText.c_str(), ": ") + 2;
        dataFile << timePlayed << '\n';
        dataFile << this->gameScore / 10;
        dataFile.close();
    }
    else  {
        std::string buffer;
        buffer = dataList.front();
        int fileBestGameScore = std::strtol (buffer.c_str(), nullptr, 10);
        bool bestScoreUpdated = false;
        if (this->gameScore > fileBestGameScore) {
            bestScoreUpdated = true;
            dataFile << this->gameScore << '\n';
        }
        else
            dataFile << buffer.c_str() << '\n';
        dataList.pop_front();
        buffer = dataList.front();
        if (buffer.c_str()[0] == '-' && ! bestScoreUpdated)
            dataFile << this->gameScore << '\n';
        else {
            int fileWorstGameScore = std::strtol (buffer.c_str(), nullptr, 10);
            if (this->gameScore < fileWorstGameScore)
                dataFile << this->gameScore << '\n';
            else
                dataFile << buffer << '\n';
        }
        dataList.pop_front();
        buffer = dataList.front();
        std::string currentTimePlayed;
        currentTimePlayed = strstr (this->timeLabel->text().toStdString().c_str(), ": ") + 2;
        // extracting time values from string
        auto timePlayedInFile = timeConvertor(buffer);
        auto timePlayedInGame = timeConvertor(currentTimePlayed);
        // if time unit is the same
        if (! strcmp (timePlayedInFile.second.c_str(), timePlayedInGame.second.c_str())) {
            if (timePlayedInGame.first > timePlayedInFile.first)
                dataFile << timePlayedInGame.first << ' ' << timePlayedInGame.second << '\n';
            else
                dataFile << timePlayedInFile.first << ' ' << timePlayedInFile.second << '\n';
        }
        else { // time unit is different
            bool dataWasWitten = false;
            if (timePlayedInGame.second == "mins" && timePlayedInFile.second == "min") {
                dataFile << timePlayedInGame.first << ' ' << timePlayedInGame.second << '\n';
                dataWasWitten = true;
            }
            if ((timePlayedInGame.second == "min" || timePlayedInGame.second == "mins")
            && timePlayedInFile.second == "s"){
                dataFile << timePlayedInGame.first << ' ' << timePlayedInGame.second << '\n';
                dataWasWitten = true;
            }
            if (timePlayedInGame.second == "h"
            && (timePlayedInGame.second == "min" || timePlayedInGame.second == "mins")){
                dataFile << timePlayedInGame.first << ' ' << timePlayedInGame.second << '\n';
                dataWasWitten = true;
            }
            if (timePlayedInGame.second == "h" && timePlayedInFile.second == "s") {
                dataFile << timePlayedInGame.first << ' ' << timePlayedInGame.second << '\n';
                dataWasWitten = true;
            }
            if (! dataWasWitten)
                dataFile << timePlayedInFile.first << ' ' << timePlayedInFile.second << '\n';
        }
        dataList.pop_front();
        buffer = dataList.front();
        int coinsInFile = std::strtol (buffer.c_str(), nullptr, 10);
        if (this->gameScore / 10 > coinsInFile)
            dataFile << this->gameScore / 10;
        else
            dataFile << buffer.c_str();
        dataFile.close();
    }
}

Game::~Game() noexcept {
    this->boardLayout->removeWidget(this->gameBoard);

    this->figuresQueueLayout->removeWidget(this->queueLabel);
    this->figuresQueueLayout->removeWidget(this->queue);
    this->figuresQueueLayout->removeWidget(this->pauseButton);
    this->figuresQueueLayout->removeWidget(this->pauseLabel);

    this->dataLayout->removeWidget(this->quitButton);
    this->dataLayout->removeWidget(this->scoreLabel);
    this->dataLayout->removeWidget(this->timeLabel);

    this->generalLayout->removeItem(this->figuresQueueLayout);
    this->generalLayout->removeItem(this->boardLayout);
    this->generalLayout->removeItem(this->dataLayout);

    delete this->generalLayout;

    delete this->dataLayout;
    delete this->boardLayout;
    delete this->figuresQueueLayout;

    delete this->quitButton;
    delete this->scoreLabel;
    delete this->timeLabel;
    delete this->pauseButton;
    delete this->pauseLabel;
    delete this->gameBoard;
    delete this->queueLabel;
    delete this->queue;

    delete this->shapeFallTimer;
    delete this->moveRightSignalGenerator;
    delete this->moveLeftSignalGenerator;
    delete this->dropSignalGenerator;
    delete this->pIncTimer;
}
#include <CurrentSettings.h>

void Game::keyPressEvent(QKeyEvent *event) {
//    if ( ! event->isAutoRepeat() )
//        std::cout << event->text().toStdString() << " pressed\n";
    if (pauseButtonCliked)
        this->pauseLabel->setStyleSheet(Util::getStyle("PauseLabelPressed.css").c_str());
    else if ( ! event->isAutoRepeat() ) {
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().moveRightKey
        ) {
            emit this->moveRight();
            this->moveRightSignalGenerator->start();
        }
        if (
            CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
            CurrentSettings::instance().control().moveLeftKey
        ) {
            emit this->moveLeft();
            this->moveLeftSignalGenerator->start();
        }
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().dropKey
        ) {
            this->gameBoard->dropActiveShape();
            this->shapeFallTimer->stop();
            this->dropSignalGenerator->start();
        }
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().rotateKey
        )
            this->gameBoard->rotateShape();
    }
//    std::cout << event->text().toStdString() << " pressed " << event->isAutoRepeat() << '\n';
}

void Game::keyReleaseEvent(QKeyEvent *event) {
//    if ( ! event->isAutoRepeat() )
//        std::cout << event->text().toStdString() << " released\n";
    if (pauseButtonCliked)
        this->pauseLabel->setStyleSheet(Util::getStyle("PauseLabel.css").c_str());
    else if ( ! event->isAutoRepeat() ) {
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().moveRightKey
        )
            this->moveRightSignalGenerator->stop();
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().moveLeftKey
                )
            this->moveLeftSignalGenerator->stop();
        if (
                CurrentSettings::getControlKeyForQKey( static_cast < Qt::Key > (event->key()) ) ==
                CurrentSettings::instance().control().dropKey
        ) {
            this->dropSignalGenerator->stop();
            this->shapeFallTimer->start();
        }
    }
//    std::cout << event->text().toStdString() << " released " << event->isAutoRepeat() << '\n';
}