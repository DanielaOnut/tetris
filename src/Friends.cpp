//
// Created by danie on 15.04.2021.
//

#include "Friends.h"

Friends::Friends (QWidget * parent) noexcept : QWidget(parent) {

}

void Friends::init () noexcept {
    this->createComponents();
    this->alignComponents();
    this->addFriend("Friend01");
}

void Friends::addFriend(const std::string & name) noexcept {
    auto container = new QListWidgetItem (this->friendsList);
    this->friendsList->addItem(container);

    auto widget = new FriendsListItem();
    widget->init();
    widget->setFriendName(name);

    container->setSizeHint(widget->sizeHint());

    this->friendsList->setItemWidget(container, widget);
}

void Friends::createComponents() noexcept {
    this->generalLayout = new QVBoxLayout (nullptr);
    this->friendsList = new QListWidget (this);
}

void Friends::alignComponents() noexcept {
    this->setLayout(this->generalLayout);
    this->generalLayout->addWidget(this->friendsList);
}

Friends::~Friends() noexcept {
    for ( int i = this->friendsList->count() - 1; i >= 0; i-- ) {
        auto container = this->friendsList->item(i);
        auto widget = this->friendsList->itemWidget( container );
        this->friendsList->removeItemWidget( container );

        delete widget;
        delete container;
    }

    this->generalLayout->removeWidget(this->friendsList);

    delete this->friendsList;
    delete this->generalLayout;
}