//
// Created by danie on 15.04.2021.
//

#ifndef PROIECT_FRIENDS_H
#define PROIECT_FRIENDS_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QListWidget>

class Friends : public QWidget {
private:
    QLayout     * generalLayout {nullptr};
    QListWidget * friendsList   {nullptr};
public:
    explicit Friends (QWidget *) noexcept;

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void addFriend ( std::string const &) noexcept;

    ~Friends () noexcept override;
};

class FriendsListItem : public QWidget {
private:
    QLayout     * generalLayout   {nullptr};
    QLabel      * userName        {nullptr};
    QPushButton * unfriendButton  {nullptr};
public:
    explicit FriendsListItem (QWidget * pParent = nullptr) noexcept : QWidget (nullptr) { }

    void init () {
        this->createComponents();
        this->alignComponents();
        this->adjustComponents();
        this->styleComponents();
    }

    void createComponents () {
        this->generalLayout = new QHBoxLayout (nullptr);

        this->userName = new QLabel (this);
        this->unfriendButton = new QPushButton (this);
    }

    void alignComponents () {
        this->setLayout (this->generalLayout);

        this->generalLayout->addWidget(this->userName);
        this->generalLayout->addWidget(this->unfriendButton);
    }

    void adjustComponents () {
        this->unfriendButton->setMaximumWidth(80);
        this->unfriendButton->setMinimumWidth(80);
        this->unfriendButton->setFixedHeight(28);
        this->unfriendButton->setText("Unfriend");
    }

    void styleComponents () {
        this->unfriendButton->setStyleSheet("QPushButton {\n"
                                            "    border-color: #1e3f71;\n"
                                            "    background-color: #f1f1f1;\n"
                                            "    color: #1e3f71;\n"
                                            "    border-width: 3px;\n"
                                            "    border-radius: 3px;\n"
                                            "    border-style: outset;\n"
                                            "    margin: 3px;\n"
                                            "    font-size: 15px;\n"
                                            "}");
    }

    void setFriendName (std::string const & name) noexcept {
        this->userName->setText(name.c_str());
    }
};

#endif //PROIECT_FRIENDS_H
