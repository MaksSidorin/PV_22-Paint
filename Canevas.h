#ifndef CANEVAS
#define CANEVAS
#include <QtWidgets>
#include <FenPrincipale.h>

class Pile{    
private:
    int x;
    int y;

public:
    Pile(int a,int b) : x(a),y(b) {}
    ~Pile();
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

};

class WorkSpace : public QWidget
{
 Q_OBJECT

public :

    WorkSpace(WinBody *p);

    void draw();
    void drawRectangle();
    void drawCircle();
    void drawTrait();
    void paintEvent(QPaintEvent* event);

    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
public slots:
    void saveWorkSpace();
    void openWorkSpace();

private :

    int xMove;
    int yMove;
    int xPress;
    int yPress;
    int xRelease;
    int yRelease;

    int pixActuel;
    int xMax;
    int yMax;

    QPainter *painter;
    QLabel *label;
    WinBody *win;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QImage *image;
    QVector<QPixmap*> pixmapListe;
    QPainterPath *path;
};

#endif
