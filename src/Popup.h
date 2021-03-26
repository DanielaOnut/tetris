//
// Created by vladl on 3/20/2021.
//

#ifndef TETRIS_POPUP_H
#define TETRIS_POPUP_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>

class Popup : public QWidget {
    Q_OBJECT
private:
    int x;
    int y;

    int width;
    int height;

    QLayout * generalLayout = nullptr;

    QLayout * buttonsLayout = nullptr;

    QPushButton * closeButton = nullptr;
    QPushButton * minimiseButton = nullptr;

    QWidget * popupContent = nullptr;

public:

//    Popup ( QWidget * parent, int x, int y, int w, int h ) noexcept;
    Popup ( QWidget * parent, QPoint p, QSize s ) noexcept;

    ~Popup() noexcept override;

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void adjustComponents () noexcept;
    void styleComponents () noexcept;
    void connectComponents () noexcept;

    void paintEvent ( QPaintEvent * ) noexcept override;

    void setContent ( QWidget * ) noexcept;
signals:
    void close ();
};

#endif //TETRIS_POPUP_H
