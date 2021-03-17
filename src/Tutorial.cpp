//
// Created by loghin on 05.03.2021.
//

#include "Tutorial.h"
#include "Util.h"
#include <QTextEdit>
#include <QLabel>

void Tutorial::init() {
    this->createComponents();
    this->alignComponents();
    this->adjustComponents();
    this->styleComponents();
    this->connectComponents();
}

void Tutorial::createComponents () noexcept {
    this->mainLayout = new QVBoxLayout ( this );
    this->textLayout = new QHBoxLayout ( this );
    this->lowerButtonsLayout = new QHBoxLayout ( this );

    this->tutorialText = new QTextEdit ();
    this->tutorialText->setText("The tutorial is HERE");
    this->backButton = new QPushButton ( this->backButtonText, this );
}

void Tutorial::alignComponents() noexcept {
    this->setLayout( this->mainLayout );

    this->mainLayout->addItem (this->textLayout);
    this->mainLayout->addItem (this->lowerButtonsLayout);

    this->textLayout->addWidget(this->tutorialText);
    this->lowerButtonsLayout->addWidget(this->backButton);

    this->textLayout->setAlignment(this->tutorialText, Qt::AlignCenter);
    this->lowerButtonsLayout->setAlignment(this->backButton, Qt::AlignBottom | Qt::AlignLeft);
}

void Tutorial::adjustComponents() noexcept {
    this->backButton->setMinimumWidth(100);
}

void Tutorial::styleComponents() noexcept {
    auto buttonStyle = Util::getStyle("GeneralButton.css");
    this->backButton->setStyleSheet(buttonStyle.c_str());
}

void Tutorial::connectComponents() noexcept {
    connect( this->backButton, & QPushButton::clicked, [this] () { emit this->back(); } );
}

Tutorial::~Tutorial() noexcept {
    this->lowerButtonsLayout->removeWidget(this->backButton);
    this->textLayout->removeWidget(this->tutorialText);

    this->mainLayout->removeItem(this->textLayout);
    this->mainLayout->removeItem(this->lowerButtonsLayout);

    delete this->mainLayout;
    delete this->textLayout;
    delete this->lowerButtonsLayout;

    delete this->tutorialText;
    delete this->backButton;
}