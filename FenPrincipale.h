#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE
#include <QtWidgets>


class WinBody : public QMainWindow
{
   Q_OBJECT

public:
    WinBody();
    bool getDrawEnable();
    bool getRectangleEnable();
    bool getCircleEnable();
    bool getTraitEnable();
    QColor getColour();
    int getVeleurSlider();

public slots :

    void slotDraw();
    void slotRectangle();
    void slotCircle();
    void slotTrait();
    void slotColour();
    void slotSlider(int x);

private:
    bool drawEnable;
    bool rectangleEnable;
    bool circleEnable;
    bool traitEnable;
    int valeurSlider;
    QColorDialog *colourDialogue;
    QColor colour;
};

#endif
