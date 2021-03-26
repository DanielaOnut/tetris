//
// Created by danie on 20.03.2021.
//

#include "Inbox.h"


Inbox::Inbox (QWidget * parent) noexcept : QWidget(parent) {

}

void Inbox::init() noexcept {
    this->createComponents();
    this->alignComponents();
//    this->adjustComponents();
//    this->styleComponents();
//    this->connectComponents();
//    this->messageList->addItem("ana are mere");

    this->addMessage( "Loghin", "Salut, merge lista" );
}

void Inbox::addMessage(const std::string & developer, const std::string & message) noexcept {
    auto container = new QListWidgetItem(this->messageList);
    this->messageList->addItem(container );

    auto widget = new InboxListItem();
    widget->init();
    widget->setDeveloperName(developer);
    widget->setMessage(message);

    container->setSizeHint(widget->sizeHint() ); /// spunem cam cat de mare sa fie container-ul

    this->messageList->setItemWidget ( container, widget );
}

void Inbox::createComponents() noexcept {
    this->generalLayout = new QVBoxLayout (nullptr);
    this->messageList = new QListWidget (this);
}

void Inbox::alignComponents() noexcept {
    this->setLayout(this->generalLayout);
    this->generalLayout->addWidget(this->messageList);
}

Inbox::~Inbox () noexcept {
    this->generalLayout->removeWidget(this->messageList);

    delete this->messageList; /// TODO : memory leak
    delete this->generalLayout;
}
