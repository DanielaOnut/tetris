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
    this->mainLayout = new QVBoxLayout ( nullptr ); /// layout owned by nobody on creation
    this->textLayout = new QHBoxLayout ( nullptr );
    this->lowerButtonsLayout = new QHBoxLayout ( nullptr );

    this->tutorialText = new QLabel (this); /// objects must be owned
//    this->tutorialText->setText("The tutorial is HERE");
    this->backButton = new QPushButton ( this->backButtonText, this );
}

void Tutorial::alignComponents() noexcept {
    this->setLayout( this->mainLayout ); /// assign layout to this Widget

    this->mainLayout->addItem (this->textLayout);
    this->mainLayout->addItem (this->lowerButtonsLayout);

    this->textLayout->addWidget(this->tutorialText);
    this->lowerButtonsLayout->addWidget(this->backButton);

    this->textLayout->setAlignment(Qt::AlignVCenter);
    this->lowerButtonsLayout->setAlignment(this->backButton, Qt::AlignBottom | Qt::AlignLeft);
}

void Tutorial::adjustComponents() noexcept {
    this->backButton->setMinimumWidth(100);
}

void Tutorial::styleComponents() noexcept {
    auto buttonStyle = Util::getStyle("GeneralButton.css");
    auto textStyle = Util::getStyle("TutorialText.html");

    this->backButton->setStyleSheet(buttonStyle.c_str());
    this->tutorialText->setTextFormat(Qt::RichText);
    this->tutorialText->setWordWrap(true);
    this->tutorialText->setText(textStyle.c_str());
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