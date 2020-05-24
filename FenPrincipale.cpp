#include "FenPrincipale.h"
#include "Canevas.h"
#include "FenTaille.h"
#include <QMainWindow>

template <class T>
class SmartPtr {
    T *obj;
public:
    SmartPtr(T *_obj = nullptr) : obj(_obj) {}
    ~SmartPtr() { if (obj != nullptr) delete obj; }
    T* operator->() { return obj; }
    T& operator*() { return *obj; }
    void operator=(T* _obj) { obj = _obj; }
    void* operator new(size_t size) { return ::operator new(size); }
};

WinBody::WinBody()
{
    resize(500,500);
    //Инициализация

    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 0;
    traitEnable = 0;
    valeurSlider = 1;

    WorkSpace *workSpace = new WorkSpace(this);
    setCentralWidget(workSpace);

    //Menu File
  //  SmartPtr<QMenu> menuFile;
  //  menuFile = menuBar()->addMenu("Файл");
    QMenu *menuFile = menuBar()->addMenu("Файл");
    QAction *actionSave = new QAction("Сохранить",this);
    menuFile->addAction(actionSave);
    QAction *actionOpen = new QAction("Открыть",this);
    menuFile->addAction(actionOpen);

    connect(actionSave,SIGNAL(triggered(bool)),workSpace,SLOT(saveWorkSpace()));
    connect(actionOpen,SIGNAL(triggered(bool)),workSpace,SLOT(openWorkSpace()));


     QAction *actionDraw = new QAction("Кисть",this);

    //Menu form

//     SmartPtr<QMenu> menuForm = menuBar()->addMenu("Добавить");
    QMenu *menuForm = menuBar()->addMenu("Добавить");


   // menuForm->addAction(actionDraw);
    QAction *actionRectangle = new QAction("Прямоугольник",this);
    menuForm->addAction(actionRectangle);
    QAction *actionCircle = new QAction("Круг",this);
    menuForm->addAction(actionCircle);
    QAction *actionTrait = new QAction("Прямая линия",this);
    menuForm->addAction(actionTrait);

    connect(actionDraw,SIGNAL(triggered(bool)),this,SLOT(slotDraw()));
    connect(actionRectangle,SIGNAL(triggered(bool)),this,SLOT(slotRectangle()));
    connect(actionCircle,SIGNAL(triggered(bool)),this,SLOT(slotCircle()));
    connect(actionTrait,SIGNAL(triggered(bool)),this,SLOT(slotTrait()));

    //Панель инструментов
    QToolBar *toolBar = addToolBar("Цвет");

    QPushButton *boutonColour = new QPushButton;
    boutonColour->setText("Цвет");
    colourDialogue = new QColorDialog; //выбор различного цвета
    toolBar->addWidget(boutonColour);

    QSlider *slider = new QSlider(Qt::Horizontal); //ползунок толщины
    slider->setRange(1,15);
    toolBar->addWidget(slider);

    connect(boutonColour,SIGNAL(clicked(bool)),this,SLOT(slotColour()));
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(slotSlider(int)));
}

//функции
bool WinBody::getDrawEnable()
{
    return drawEnable;
}
bool WinBody::getRectangleEnable()
{
    return rectangleEnable;
}
bool WinBody::getCircleEnable()
{
    return circleEnable;
}
bool WinBody::getTraitEnable()
{
    return traitEnable;
}

QColor WinBody::getColour()
{
    return colour;
}

int WinBody::getVeleurSlider()
{
    return valeurSlider;
}

//SLOTS
void WinBody::slotDraw()
{
    drawEnable = 1;
    rectangleEnable = 0;
    circleEnable = 0;
    traitEnable = 0;
}

void WinBody::slotRectangle()
{
    drawEnable = 0;
    rectangleEnable = 1;
    circleEnable = 0;
    traitEnable = 0;
}

void WinBody::slotCircle()
{
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 1;
    traitEnable = 0;
}

void WinBody::slotTrait()
{
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 0;
    traitEnable = 1;
}

void WinBody::slotColour()
{
    colour = colourDialogue->getColor();
}

void WinBody::slotSlider(int x)
{
    valeurSlider = x;
}
