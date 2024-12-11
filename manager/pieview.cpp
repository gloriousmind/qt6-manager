#include "pieview.h"
#include <QScrollBar>
#include <QtMath>
#include <QPainterPath>
#include <QMouseEvent>
#include <QPen>
#include <QPainter>
#include <QAbstractItemView>
#include <QDebug>
#include <QSqlQuery>
#include <QApplication>

PieView::PieView(QWidget * parent) : QAbstractItemView(parent)
{
    margin = 8;
    totalSize = 230;
    pieSize = totalSize - 2 * margin;
    product_has_sold_cnt = 0;
    totalValue = 0;
    rubberBand = nullptr;
    option = new QStyleOptionViewItem;
    initViewItemOption(option);
}

// Returns the rectangle of the item at position index in the model. The rectangle is in contents coordinates.
QRect PieView::itemRect(const QModelIndex & index) const
{
    if (!index.isValid())
        return QRect();
    // Check whether the index's row is in the list of rows represented
    // by slices.
    QModelIndex salesIndex;
    if (index.column() != 1)
        salesIndex = model()->index(index.row(), 1, rootIndex());
    else
        salesIndex = index;
    if (model()->data(salesIndex).toInt() <= 0)
        return QRect();

    int display_row_num = 0;
    for (int row = index.row() - 1; row >= 0; --row)
    {
        if (model()->data(model()->index(row, 1, rootIndex())).toInt() > 0)
            display_row_num++;
    }

    switch(index.column())
    {
    case 0 :
    {
        const qreal itemHeight = QFontMetrics(option->font).height();
        return QRect(totalSize + margin, qRound(margin + display_row_num * itemHeight), totalSize, qRound(itemHeight));
    }
    case 1 :
    {
        return viewport()->rect();
    }
    }
    return QRect();
}

//Returns the rectangle of the item in viewport coordinates.
QRect PieView::visualRect(const QModelIndex &index) const
{
    QRect rect = itemRect(index);
    if (!rect.isValid())
        return rect;
    return QRect(rect.left() - horizontalScrollBar()->value(), rect.top() - verticalScrollBar()->value(), rect.width(), rect.height());
}

void PieView::paintEvent(QPaintEvent * event)
{
    QItemSelectionModel * selections = selectionModel();

    QBrush background = option->palette.base();
    QPen foreground(option->palette.color(QPalette::WindowText));

    QPainter painter(viewport());
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(event->rect(), background);
    painter.setPen(foreground);

    QRect pieRect = QRect(margin, margin, pieSize, pieSize);

    if (product_has_sold_cnt <= 0)
        return;

    painter.save();
    painter.translate(pieRect.x() - horizontalScrollBar()->value(), pieRect.y() - verticalScrollBar()->value());
    painter.drawEllipse(0, 0, pieSize, pieSize);

    double startAngle = 0.0;
    for (int row = 0; row < model()->rowCount(rootIndex()); ++row)
    {
        QModelIndex index = model()->index(row, 1, rootIndex());
        int value = model()->data(index).toInt();
        if (value > 0)
        {
            double angle = (double) 360 * value / (double) totalValue;

            QModelIndex colorIndex = model()->index(row, 0, rootIndex());
            QColor color = QColor(model()->data(colorIndex, Qt::DecorationRole).toString());

            if (currentIndex() == index)
                painter.setBrush(QBrush(color, Qt::Dense4Pattern));
            else if (selections->isSelected(index))
                painter.setBrush(QBrush(color, Qt::Dense3Pattern));
            else
                painter.setBrush(QBrush(color));

            painter.drawPie(0, 0, pieSize, pieSize, int(startAngle * 16), int(angle * 16));
            startAngle += angle;
        }
    }
    painter.restore();

    for (int row = 0; row < model()->rowCount(rootIndex()); ++row)
    {
        QModelIndex index = model()->index(row, 1, rootIndex());
        int value = model()->data(index).toInt();
        if (value > 0)
        {
            QModelIndex labelIndex = model()->index(row, 0, rootIndex());
            initViewItemOption(option);
            option->rect = visualRect(labelIndex);
            if (selections->isSelected(labelIndex))
                option->state |= QStyle::State_Selected;
            if (currentIndex() == labelIndex)
                option->state |= QStyle::State_HasFocus;

            itemDelegate()->paint(&painter, *option, labelIndex);
        }
    }
}

void PieView::scrollTo(const QModelIndex& index, QAbstractItemView::ScrollHint)
{
    QRect area = viewport()->rect();
    QRect rect = visualRect(index);

    if (rect.left() < area.left())
    {
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + rect.left() - area.left());
    }
    else if (rect.right() > area.right())
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + qMin(rect.right() - area.right(), rect.left() - area.left()));

    if (rect.top() < area.top())
    {
        verticalScrollBar()->setValue(verticalScrollBar()->value() + rect.top() - area.top());
    }
    else if (rect.bottom() > area.bottom())
    {
        verticalScrollBar()->setValue(verticalScrollBar()->value() + qMin(rect.top() - area.top(), rect.bottom() - area.bottom()));
    }
    update();
}

void PieView::dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight, const QVector<int> &roles)
{
    product_has_sold_cnt = 0;
    totalValue = 0;
    for (int row = 0; row < model()->rowCount(QModelIndex()); ++row)
    {
        QModelIndex index = model()->index(row, 1, rootIndex());
        int value = model()->data(index).toInt();

        if (value > 0)
        {
            totalValue += value;
            product_has_sold_cnt++;
        }
    }
    QAbstractItemView::dataChanged(topLeft, bottomRight);
}

bool PieView::edit(const QModelIndex & index, QAbstractItemView::EditTrigger trigger, QEvent * event)
{
    if (index.column() == 0)
        return QAbstractItemView::edit(index, trigger, event);
    else
    {
        if (trigger == DoubleClicked)
            qDebug() << "modifying pie is not allowed!";
        return false;
    }
}

QModelIndex PieView::indexAt(const QPoint & point) const
{
    if (product_has_sold_cnt == 0)
        return QModelIndex();

    int wx = point.x() + horizontalScrollBar()->value();
    int wy = point.y() + verticalScrollBar()->value();

    if (wx < totalSize)
    {
        double cx = wx - totalSize / 2;
        double cy = totalSize / 2 - wy;
        double d = qPow(qPow(cx, 2) + qPow(cy, 2), 0.5);

        if (d == 0 || d > pieSize / 2)
            return QModelIndex();

        double angle = qRadiansToDegrees(qAtan2(cy, cx));
        if (angle < 0.0)
            angle = 360 + angle;

        double startAngle = 0.0;

        for (int row = 0; row < model()->rowCount(rootIndex()); ++row)
        {
            QModelIndex index = model()->index(row, 1, rootIndex());
            int value = model()->data(index).toInt();
            if (value > 0)
            {
                double SliceAngle = (double) 360 * value / (double) totalValue;
                if (angle >= startAngle && angle < (startAngle + SliceAngle))
                    return model()->index(row, 1, rootIndex());
                startAngle += SliceAngle;
            }
        }
    }
    else if (wx > totalSize + margin && wx < totalSize + margin + option->decorationSize.width() + QFontMetrics(option->font).horizontalAdvance("产品品牌"))
    {

        double itemHeight = QFontMetrics(option->font).height();
        int index_Of_listItem = int((wy - margin) / itemHeight);
        int validRow = 0;

        for (int row = 0; row < model()->rowCount(rootIndex()); ++row)
        {
            QModelIndex index = model()->index(row, 1, rootIndex());
            if (model()->data(index).toInt() > 0)
            {
                if (index_Of_listItem == validRow)
                    return model()->index(row, 0, rootIndex());
                ++validRow; //列表中点击的项目不匹配，继续找表格下一排
            }
        }

    }
    return QModelIndex();
}

bool PieView::isIndexHidden(const QModelIndex &) const
{
    return false;
}

int PieView::horizontalOffset() const
{
    return horizontalScrollBar()->value();
}

int PieView::verticalOffset() const
{
    return verticalScrollBar()->value();
}

void PieView::mousePressEvent(QMouseEvent * event)
{
    QAbstractItemView::mousePressEvent(event);
    origin = event->position().toPoint();
    if (!rubberBand)
        rubberBand = new QRubberBand(QRubberBand::Line, viewport());
    rubberBand->setGeometry(QRect(origin, QSize()));
    rubberBand->show();
}

void PieView::mouseMoveEvent(QMouseEvent * event)
{
    if (rubberBand)
        rubberBand->setGeometry(QRect(origin, event->position().toPoint()).normalized());
    QAbstractItemView::mouseMoveEvent(event);
}

void PieView::mouseReleaseEvent(QMouseEvent * event)
{
    QAbstractItemView::mouseReleaseEvent(event);
    if (rubberBand)
        rubberBand->hide();
    viewport()->update();
}

QModelIndex PieView::moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{
    QModelIndex current = currentIndex();

    switch(cursorAction)
    {
    case MoveLeft :
    case MoveUp :
    {
        QModelIndex temp = current;
        QModelIndex old = current;
        for (int row = temp.row() - 1; row >= 0; row--)
        {
            temp = model()->index(row, temp.column(), temp.parent());
            if (model()->index(row, 1, temp.parent()).data().toInt() > 0)
            {
                current = temp;
                break;
            }
        }
        if (old == current)
            QApplication::beep();
        break;
    }
    case MoveRight :
    case MoveDown :
    {
        QModelIndex temp = current;
        QModelIndex old = current;
        for (int row = temp.row() + 1; row < model()->rowCount(temp.parent()); row++)
        {
            temp = model()->index(row, temp.column(), temp.parent());
            if (model()->index(row, 1, temp.parent()).data().toInt() > 0)
            {
                current = temp;
                break;
            }
        }
        if (old == current)
            QApplication::beep();
        break;
    }
    default :
        break;
    }
    viewport()->update();
    return current;
}

QRegion PieView::itemRegion(const QModelIndex & index) const
{
    if (!index.isValid())
        return QRegion();

    if (index.column() != 1) //列数为1在扇形图上否则就是在提示的矩形图上
        return QRegion(itemRect(index));

    if (model()->data(index).toInt() <= 0)
        return QRegion();
    double startAngle = 0.0;
    for (int row = 0; row < model()->rowCount(index.parent()); ++row)
    {
        QModelIndex sliceIndex = model()->index(row, 1, index.parent());
        int value = model()->data(sliceIndex).toInt();

        if (value > 0)
        {
            double angle = (double) 360 * value / (double) totalValue;

            if (sliceIndex == index)
            {
                QPainterPath slicePath;
                slicePath.moveTo(totalSize / 2, totalSize / 2);
                slicePath.arcTo(margin, margin, margin + pieSize, margin + pieSize, startAngle, angle);
                slicePath.closeSubpath();
                return QRegion(slicePath.toFillPolygon().toPolygon());
            }
            startAngle += angle;
        }
    }
    return QRegion();
}

void PieView::setSelection(const QRect& rect, QItemSelectionModel::SelectionFlags flags)
{
    QRect contents_Rect = rect.translated(horizontalScrollBar()->value(), verticalScrollBar()->value()).normalized();
    int rows = model()->rowCount(rootIndex());
    int columns = model()->columnCount(rootIndex());
    QModelIndexList indexes;

    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            QModelIndex index = model()->index(row, column, rootIndex());
            QRegion region = itemRegion(index);
            if (region.intersects(contents_Rect))
            {
                indexes.append(index);
            }
        }
    }

    if (indexes.size() > 0)
    {
        QItemSelection selection;
        for (int i = 0; i < indexes.size(); ++i)
        {
            selection.select(indexes[i], indexes[i]);
        }
        selectionModel()->select(selection, flags);
    }
    else
        selectionModel()->select(QModelIndex(), flags);

    viewport()->update();
}

void PieView::resizeEvent(QResizeEvent *event)
{
    QAbstractScrollArea::resizeEvent(event);
    updateGeometries();
}

void PieView::updateGeometries()
{
    horizontalScrollBar()->setPageStep(viewport()->width());
    horizontalScrollBar()->setRange(0, qMax(0, 2 * totalSize - viewport()->width()));
    verticalScrollBar()->setPageStep(viewport()->height());
    verticalScrollBar()->setRange(0, qMax(0, totalSize - viewport()->height()));
}

void PieView::rowsInserted(const QModelIndex & parent, int start, int end)
{
    for (int row = start; row <= end; ++row)
    {
        QModelIndex index = model()->index(row, 1, rootIndex());
        int value = model()->data(index).toInt();
        if (value > 0)
        {
            totalValue += value;
            ++product_has_sold_cnt;
        }
    }
    QAbstractItemView::rowsInserted(parent, start, end);
}

void PieView::rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end)
{
    for (int row = start; row <= end; ++row)
    {
        QModelIndex index = model()->index(row, 1, rootIndex());
        int value = model()->data(index).toInt();
        if (value > 0)
        {
            totalValue -= value;
            --product_has_sold_cnt;
        }
    }
    QAbstractItemView::rowsAboutToBeRemoved(parent, start, end);
}

void PieView::scrollContentsBy(int dx, int dy)
{
    viewport()->scroll(dx, dy);
}

QRegion PieView::visualRegionForSelection(const QItemSelection & selection) const
{
    int ranges = selection.count();
    if (ranges == 0)
        return QRect();

    QRegion region;
    for (int i = 0; i < ranges; ++i)
    {
        const QItemSelectionRange &range = selection.at(i);
        for (int row = range.top(); row <= range.bottom(); ++row)
        {
            for (int col = range.left(); col <= range.right(); ++col)
            {
                QModelIndex index = model()->index(row, col, rootIndex());
                region += visualRect(index);
            }
        }
    }
    return region;
}
