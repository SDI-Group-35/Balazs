#include "pixelmap.h"
#include "mainwindow.h"
#include <iostream>
using namespace std;

pixelmap::pixelmap(QObject *parent)
{
    //connect the point together
    connect(this, SIGNAL(drawLines(QPointF, QPointF)), parent, SLOT(drawLines(QPointF,QPointF)));
    connect(this, SIGNAL(drawPolygon(QPolygonF)), parent, SLOT(drawPolygon(QPolygonF)));
}

//loads image
void pixelmap::loadImg(QGraphicsScene *scene)
{
    //loads file dialog
    QString filename = QFileDialog::getOpenFileName(nullptr, tr("Choose"), "",tr("Images (*.png *.jpg *.jpeg *.bmp *.gif"));
    //stores image
    QImage image(filename);

    if (true)
    {
        //load image onto pixmap (canvas)
        QPixmap *p = new QPixmap(QPixmap::fromImage(image));

        //update pixmap
        setPixmap(*p);
    }
}


void pixelmap::mousePressEvent(QGraphicsSceneMouseEvent * event){

    if(sides == 1){

        //getting postions and updating/storing the coordinates into the vector
        xyPress.push_back(event->pos());

        //after second point is clicked
        if(xyPress.size() > 1)
        {
            //drawline
            emit drawLines(xyPress.back(), xyPress.at(xyPress.size()-2));
        }
    }
}

void pixelmap::clearVectors(){

    xyPress.clear();
    lineV.clear();
}

//end drawing
void pixelmap::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event){

    if(sides == 1){
        //draws line from first and last point
        emit drawLines(xyPress.back(), xyPress.at(xyPress.size()-2));


        QPolygonF newPoly(xyPress);

        emit drawPolygon(newPoly);

        clearVectors();
    }
}

/* List releated */
/* Initialize all of them to NULL */
coordList::coordList(){
    head = NULL;
    curr = NULL;
    temp = NULL;
}
/* Define addNode function */
void coordList::addNode(int addData){
    nodePtr n = new node;   /* Node pointer n point to a newly created node*/
    n->next = NULL;         /* Finding the node n is poiting to and setting its pointer to NULL */
    n->data = addData;

    if(head != NULL){                   /* This part requires at least 1 element alreay in the node */
        curr = head;
        while(curr->next != NULL){      /* While the current node is not poitning to NULL, point to the next node */
            curr = curr->next;          /* If current is NULL, exit out of while loop */
        }
        curr->next = n;                 /* After pointing to the last node, process restarts*/
    }
    else
    {
        head = n;
    }
}

/* Initialize deleteNode function */
void coordList::deleteNode(int delData){

}
