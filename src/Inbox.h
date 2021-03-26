//
// Created by danie on 20.03.2021.
//

#ifndef PROIECT_INBOX_H
#define PROIECT_INBOX_H

#include <QWidget>
#include <QListWidget>
#include <QLayout>

class Inbox : public QWidget {
private:
    QLayout     * generalLayout    {nullptr};

    QListWidget * messageList       {nullptr};
public:
    explicit Inbox (QWidget * ) noexcept;

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void addMessage ( std::string const &, std::string const & ) noexcept;
//    void adjustComponents() noexcept;
//    void styleComponents () noexcept;
//    void connectComponents () noexcept;

    ~Inbox () noexcept override;
};


#include <QLabel>
class InboxListItem : public QWidget {
Q_OBJECT

private:
    QLayout * generalLayout {nullptr};
    QLabel  * developerNameLabel {nullptr};
    QLabel  * messageLabel  {nullptr};

public:
    explicit InboxListItem ( QWidget * pParent = nullptr ) noexcept : QWidget(nullptr) { }

    void init () {
        this->createComponents();
        this->alignComponents();
        this->adjustComponents();
        this->styleComponents();
        this->connectComponents();
    }

    void createComponents () {
        this->generalLayout = new QHBoxLayout (nullptr);

        this->developerNameLabel = new QLabel (this);
        this->messageLabel = new QLabel (this);
    }

    void alignComponents () {
        this->setLayout(this->generalLayout);

        this->generalLayout->addWidget(this->developerNameLabel);
        this->generalLayout->addWidget(this->messageLabel);
    }

    void adjustComponents () {

    }

    void styleComponents () {

    }

    void connectComponents () {

    }

    void setDeveloperName ( std::string const & name ) noexcept {
        this->developerNameLabel->setText(name.c_str());
    }

    void setMessage ( std::string const & msg ) noexcept {
        this->messageLabel->setText(msg.c_str());
    }
};

#endif //PROIECT_INBOX_H
