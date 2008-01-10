#include "widgetitem.h"
#include <QtCore>
#include <QtGui>
#include "customproxy.h"

namespace PlexyDesk
{
    WidgetItem::WidgetItem(const QRectF &rect, QWidget *widget ):QGraphicsRectItem(rect)
    {
                if (widget) {
                    proxyWidget = new CustomProxy(this,Qt::Window);
              //      proxyWidget->setFocusPolicy(Qt::StrongFocus);
                    proxyWidget->setWidget(widget);
                    proxyWidget->setGeometry(boundingRect().adjusted(25, 25, -25, -25));
                    proxyWidget->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
                   // proxyWidget->setFlag(QGraphicsItem::ItemIsMovable,true);
                }

                setAcceptedMouseButtons(Qt::LeftButton | Qt::RightButton);
                setFlag(QGraphicsItem::ItemIsMovable,true);
                /*
                QTransform transform;
                     transform.translate(50, 50);
                          transform.rotate(15,Qt::YAxis);
                transform.scale(0.5, 1.0);
                proxyWidget->setTransform(transform,true);
                */
    }
    
    WidgetItem::~WidgetItem()
    {

    }

    void WidgetItem::paint(QPainter *p, const QStyleOptionGraphicsItem * e , QWidget * widget)
    {
        if (proxyWidget && !proxyWidget->isVisible()) {
               proxyWidget->show();
                       proxyWidget->setFocus();
                       qDebug("Shwoing");
        }
        if (proxyWidget && proxyWidget->pos() != QPoint()) {
            proxyWidget->setGeometry(boundingRect().adjusted(25, 25, -25, -25));
            }
    }


    QRectF WidgetItem::boundingRect() const
    {
//        return proxyWidget->boundingRect();
        
        qreal penW = 0.5;
        qreal shadowW = 2.0;
        return rect().adjusted(-penW, -penW, penW + shadowW, penW + shadowW);
    }

} // namespace PlexyDesk

#include "widgetitem.moc"