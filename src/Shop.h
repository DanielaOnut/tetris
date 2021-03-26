//
// Created by danie on 20.03.2021.
//

#ifndef PROIECT_SHOP_H
#define PROIECT_SHOP_H

#include <Popup.h>
#include <Menu.h>

#include <QWidget>
#include <QListWidget>

class Shop : public QWidget {
private:
    QLayout     * generalLayout    {nullptr};

    QListWidget * itemsList       {nullptr};
public:
    Shop (QWidget * ) noexcept;

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
//    void adjustComponents() noexcept;
//    void styleComponents () noexcept;
//    void connectComponents () noexcept;

    ~Shop () noexcept;
};


#endif //PROIECT_INBOX_H
