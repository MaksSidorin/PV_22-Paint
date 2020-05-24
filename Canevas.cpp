#include <Canevas.h>
#include "FenTaille.h"

WorkSpace::WorkSpace(WinBody *p) : QWidget()
{
    win = p;

    xMax = 500;
    yMax = 500;
    label = new QLabel(this);
    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixmapListe.size()-1;
    pixmapListe[pixActuel]->fill();
    painter = new QPainter(pixmapListe[pixActuel]);

    label->setPixmap(*pixmapListe[pixActuel]);
}

void WorkSpace::paintEvent(QPaintEvent *event)
{}

//Движение мышью
void WorkSpace::mouseMoveEvent(QMouseEvent *event)
{
    if(win->getDrawEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        draw();
    }

    if(win->getRectangleEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
    }

    if(win->getCircleEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
    }

    if(win->getTraitEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
    }

}
void WorkSpace::mousePressEvent(QMouseEvent* event)
{
    if(win->getRectangleEnable()||win->getCircleEnable()
            ||win->getTraitEnable())
    {
        xPress = event->pos().x();
        yPress = event->pos().y();

    }

    if(win->getDrawEnable())
    {
        pixmapListe.push_back(new QPixmap(xMax,yMax));
        pixActuel = pixActuel+1;
        pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);
        painter->end();
        delete painter;
        painter = new QPainter(pixmapListe[pixActuel]);
    }

    if(win->getDrawEnable())
    {
        xPress = event->pos().x();
        yPress = event->pos().y();
        path = new QPainterPath(QPointF(xPress,yPress));
        path->moveTo(xPress,yPress);
    }

}

void WorkSpace::mouseReleaseEvent(QMouseEvent *event)
{
    if(win->getRectangleEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawRectangle();
    }

    if(win->getCircleEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawCircle();
    }

    if(win->getTraitEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawTrait();
    }

    if(win->getDrawEnable())
    {
        delete path;
    }
}

//Functions
void WorkSpace::draw()
{
    QPen pen;

    path->lineTo(xMove,yMove);
    pen.setColor(win->getColour());
    pen.setWidth(win->getVeleurSlider());
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPath(*path);

    label->setPixmap(*pixmapListe[pixActuel]);
}

void WorkSpace::drawRectangle()
{
    QPen pen;
    pen.setColor(win->getColour());
    pen.setWidth(win->getVeleurSlider());

    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixActuel+1;
    pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapListe[pixActuel]);

    painter->setPen(pen);
    painter->drawRect(xPress,yPress,xRelease-xPress,yRelease-yPress);

    label->setPixmap(*pixmapListe[pixActuel]);
}

void WorkSpace::drawCircle()
{
    QPen pen;
    pen.setColor(win->getColour());
    pen.setWidth(win->getVeleurSlider());

    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixActuel+1;
    pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapListe[pixActuel]);

    painter->setPen(pen);
    painter->drawEllipse(xPress,yPress,xRelease-xPress,yRelease-yPress);
    label->setPixmap(*pixmapListe[pixActuel]);
}

void WorkSpace::drawTrait()
{
    QPen pen;
    pen.setColor(win->getColour());
    pen.setWidth(win->getVeleurSlider());

    pixmapListe.push_back(new QPixmap(xMax,yMax));
    pixActuel = pixActuel+1;
    pixmapListe[pixActuel]->operator =(*pixmapListe[pixActuel-1]);
    painter->end();
    delete painter;
    painter = new QPainter(pixmapListe[pixActuel]);

    painter->setPen(pen);
    painter->drawLine(xPress,yPress,xRelease,yRelease);
    label->setPixmap(*pixmapListe[pixActuel]);

}

//функции слотов
void WorkSpace::saveWorkSpace()
{
    QString file = QFileDialog::getSaveFileName(0, "Сохранить изображение", QString(), "Images (*.png *.gif *.jpg *.jpeg)");

    pixmapListe[pixActuel]->save(file);
}

void WorkSpace::openWorkSpace()
{
    QString file = QFileDialog::getOpenFileName(0,"Открыть изображение",QString(),"Images (*.png *.gif *.jpg *.jpeg)");
    painter->end();
    delete painter;
    pixmapListe.remove(pixActuel);
    pixmapListe.push_back(new QPixmap(file));
    painter = new QPainter(pixmapListe[pixActuel]);
    label->setPixmap(*pixmapListe[pixActuel]);
}

