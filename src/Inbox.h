//
// Created by danie on 20.03.2021.
//

#ifndef PROIECT_INBOX_H
#define PROIECT_INBOX_H

#include <QWidget>
#include <QListWidget>

class Inbox : public QWidget {
private:
    QLayout     * generalLayout    {nullptr};

    QListWidget * messageList       {nullptr};
public:
    Inbox (QWidget * ) noexcept;

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
//    void adjustComponents() noexcept;
//    void styleComponents () noexcept;
//    void connectComponents () noexcept;

    ~Inbox () noexcept;
};


#endif //PROIECT_INBOX_H
