#ifndef PIEVIEW_H
#define PIEVIEW_H

#include <QAbstractItemView>
#include <QRubberBand>

class PieView : public QAbstractItemView
{
    Q_OBJECT
public:
    PieView(QWidget * parent = 0);
    QRect visualRect(const QModelIndex & index) const;
    void scrollTo(const QModelIndex & index, ScrollHint hint = EnsureVisible);
    QModelIndex indexAt(const QPoint & point) const;

protected slots:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());
    void rowsInserted(const QModelIndex & parent, int start, int end);
    void rowsAboutToBeRemoved(const QModelIndex & parent, int start, int end);

protected:
    bool edit(const QModelIndex & index, QAbstractItemView::EditTrigger trigger, QEvent * event);
    QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers);

    int horizontalOffset() const;
    int verticalOffset() const;
    bool isIndexHidden(const QModelIndex & index) const;
    void setSelection(const QRect& rect, QItemSelectionModel::SelectionFlags command);

    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent * evnet);

    void paintEvent(QPaintEvent * event);
    void resizeEvent(QResizeEvent * event);
    void scrollContentsBy(int dx, int dy);

    QRegion visualRegionForSelection(const QItemSelection & selection) const;

private:
    QRect itemRect(const QModelIndex & item) const;
    QRegion itemRegion(const QModelIndex & index) const;
    void updateGeometries();
    int margin;
    int totalSize; //逻辑上容纳饼分图矩形大小
    int pieSize;   //逻辑上饼分图大小
    int validItems;
    int totalValue;
    QPoint origin;
    QRubberBand * rubberBand;
    QStyleOptionViewItem *option;
};

#endif // PIEVIEW_H
