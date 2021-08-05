//
// Created by danie on 04.08.2021.
//

#include "Statistics.h"
#include "Util.h"
#include "Game.h"
#include <fstream>

void Statistics::init() noexcept {
    this->createComponents();
    this->alignComponents();
    this->adjustComponents();
    this->styleComponents();
    this->connectComponents();
}

void Statistics::createComponents() noexcept {
    this->generalLayout = new QHBoxLayout (nullptr);

    this->bestScoreLayout = new QVBoxLayout (nullptr);
    this->bestScoreTitleLabel = new QLabel (" Best Score Ever", this);
    this->bestScoreLabel = new QLabel ("0",this);

    this->worstScoreLayout = new QVBoxLayout (nullptr);
    this->worstScoreTitleLabel = new QLabel (" Worst Score Ever", this);
    this->worstScoreLabel = new QLabel ("-",this);

    this->mostTimePlayedLayout = new QVBoxLayout (nullptr);
    this->mostTimePlayedTitleLabel = new QLabel (" Most Time Played", this);
    this->mostTimePlayedLabel = new QLabel ("-",this);

    this->coinsEarnedLayout = new QVBoxLayout (nullptr);
    this->coinsEarnedTitleLabel = new QLabel (" Most Coins Earned", this);
    this->coinsEarnedLabel = new QLabel ("-",this);

//    this->backButtonLayout = new QHBoxLayout (nullptr);
    this->backButton = new QPushButton ("Back", this);

    this->loadDataFromFile();
}

void Statistics::loadDataFromFile() noexcept {
    auto dataList = Game::isDataInFile();
    if (! dataList.empty()) {
        std::fstream dataFile;
        dataFile.open ("StatisticsData.txt", std::ios::in);
        std::string buffer;
        std::getline (dataFile, buffer);
        this->bestScoreLabel->setText(buffer.c_str());
        std::getline (dataFile, buffer);
        this->worstScoreLabel->setText(buffer.c_str());
        std::getline (dataFile, buffer);
        this->mostTimePlayedLabel->setText(buffer.c_str());
        std::getline (dataFile, buffer);
        this->coinsEarnedLabel->setText(buffer.c_str());
        dataFile.close();
    }
}

void Statistics::alignComponents() noexcept {
    this->setLayout(this->generalLayout);

    this->generalLayout->addWidget(this->backButton);
    this->generalLayout->addItem(this->bestScoreLayout);
    this->generalLayout->addItem(this->worstScoreLayout);
    this->generalLayout->addItem(this->mostTimePlayedLayout);
    this->generalLayout->addItem(this->coinsEarnedLayout);

    this->bestScoreLayout->addWidget(this->bestScoreTitleLabel);
    this->bestScoreLayout->addWidget(this->bestScoreLabel);

    this->worstScoreLayout->addWidget(this->worstScoreTitleLabel);
    this->worstScoreLayout->addWidget(this->worstScoreLabel);

    this->mostTimePlayedLayout->addWidget(this->mostTimePlayedTitleLabel);
    this->mostTimePlayedLayout->addWidget(this->mostTimePlayedLabel);

    this->coinsEarnedLayout->addWidget(this->coinsEarnedTitleLabel);
    this->coinsEarnedLayout->addWidget(this->coinsEarnedLabel);

//    this->backButtonLayout->addWidget(this->backButton);
    this->generalLayout->setAlignment(this->backButton, Qt::AlignBottom | Qt::AlignLeft);
    this->generalLayout->setAlignment(this->bestScoreLayout, Qt::AlignVCenter);
    this->generalLayout->setAlignment(this->worstScoreLayout, Qt::AlignVCenter);
    this->generalLayout->setAlignment(this->mostTimePlayedLayout, Qt::AlignVCenter);
    this->generalLayout->setAlignment(this->coinsEarnedLayout, Qt::AlignVCenter);

    this->bestScoreLayout->setAlignment(this->bestScoreLabel, Qt::AlignCenter);
    this->worstScoreLayout->setAlignment(this->worstScoreLabel, Qt::AlignCenter);
    this->mostTimePlayedLayout->setAlignment(this->mostTimePlayedLabel, Qt::AlignCenter);
    this->coinsEarnedLayout->setAlignment(this->coinsEarnedLabel, Qt::AlignCenter);
}

void Statistics::adjustComponents() noexcept {
    this->backButton->setMaximumWidth(100);
    this->backButton->setMinimumWidth(100);
}

void Statistics::styleComponents() noexcept {
    this->bestScoreTitleLabel->setStyleSheet("QLabel {\n"
                                             "    border-color: rgba(97, 131, 143, 0.79);\n"
                                             "    border-width: 2px;\n"
                                             "    border-radius: 3px;\n"
                                             "    border-style: double;\n"
                                             "    background-color: rgb(255, 255, 255);\n"
                                             "    min-height: 45px;\n"
                                             "    font-size: 30px;\n"
                                             "    color: rgb(0, 51, 116);\n"
                                             "}");
    this->worstScoreTitleLabel->setStyleSheet("QLabel {\n"
                                              "    border-color: rgba(97, 131, 143, 0.79);\n"
                                              "    border-width: 2px;\n"
                                              "    border-radius: 3px;\n"
                                              "    border-style: double;\n"
                                              "    background-color: rgb(255, 255, 255);\n"
                                              "    min-height: 45px;\n"
                                              "    font-size: 30px;\n"
                                              "    color: rgb(116, 0, 0);\n"
                                              "}");
    this->mostTimePlayedTitleLabel->setStyleSheet("QLabel {\n"
                                                  "    border-color: rgba(97, 131, 143, 0.79);\n"
                                                  "    border-width: 2px;\n"
                                                  "    border-radius: 3px;\n"
                                                  "    border-style: double;\n"
                                                  "    background-color: rgb(255, 255, 255);\n"
                                                  "    min-height: 45px;\n"
                                                  "    font-size: 30px;\n"
                                                  "    color: rgb(0, 80, 25);\n"
                                                  "}");
    this->coinsEarnedTitleLabel->setStyleSheet("QLabel {\n"
                                               "    border-color: rgba(97, 131, 143, 0.79);\n"
                                               "    border-width: 2px;\n"
                                               "    border-radius: 3px;\n"
                                               "    border-style: double;\n"
                                               "    background-color: rgb(255, 255, 255);\n"
                                               "    min-height: 45px;\n"
                                               "    font-size: 30px;\n"
                                               "    color: rgb(116, 102, 0);\n"
                                               "}");

    this->bestScoreLabel->setStyleSheet("QLabel {\n"
                                             "    font-size: 20px;\n"
                                             "}");
    this->worstScoreLabel->setStyleSheet("QLabel {\n"
                                        "    font-size: 20px;\n"
                                        "}");
    this->mostTimePlayedLabel->setStyleSheet("QLabel {\n"
                                        "    font-size: 20px;\n"
                                        "}");
    this->coinsEarnedLabel->setStyleSheet("QLabel {\n"
                                        "    font-size: 20px;\n"
                                        "}");

    this->backButton->setStyleSheet(Util::getStyle("GeneralButton.css").c_str());
}

void Statistics::connectComponents() noexcept {
    connect (this->backButton, & QPushButton::clicked, [this] {
        emit this->back();
    });
}

Statistics::~Statistics() noexcept {
   this->coinsEarnedLayout->removeWidget(this->coinsEarnedTitleLabel);
   this->coinsEarnedLayout->removeWidget(this->coinsEarnedLabel);

   this->mostTimePlayedLayout->removeWidget(this->mostTimePlayedTitleLabel);
   this->mostTimePlayedLayout->removeWidget(this->mostTimePlayedLabel);

   this->worstScoreLayout->removeWidget(this->worstScoreTitleLabel);
   this->worstScoreLayout->removeWidget(this->worstScoreLabel);

   this->bestScoreLayout->removeWidget(this->bestScoreTitleLabel);
   this->bestScoreLayout->removeWidget(this->bestScoreLabel);

   this->generalLayout->removeItem(this->coinsEarnedLayout);
   this->generalLayout->removeItem(this->mostTimePlayedLayout);
   this->generalLayout->removeItem(this->worstScoreLayout);
   this->generalLayout->removeItem(this->bestScoreLayout);
   this->generalLayout->removeWidget(this->backButton);

   delete this->generalLayout;

   delete this->bestScoreLayout;
   delete this->bestScoreTitleLabel;
   delete this->bestScoreLabel;

   delete this->worstScoreLayout;
   delete this->worstScoreTitleLabel;
   delete this->worstScoreLabel;

   delete this->mostTimePlayedLayout;
   delete this->mostTimePlayedTitleLabel;
   delete this->mostTimePlayedLabel;

   delete this->coinsEarnedLayout;
   delete this->coinsEarnedTitleLabel;
   delete this->coinsEarnedLabel;

   delete this->backButton;
}