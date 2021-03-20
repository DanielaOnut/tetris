//
// Created by danie on 20.03.2021.
//

#include "Inbox.h"
#include <QLayout>

Inbox::Inbox (QWidget * parent) noexcept : QWidget(parent) {

}

void Inbox::init() noexcept {
    this->createComponents();
    this->alignComponents();
//    this->adjustComponents();
//    this->styleComponents();
//    this->connectComponents();
    this->messageList->addItem("ana are mere");
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

    delete this->messageList;
    delete this->generalLayout;
}
