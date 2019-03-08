#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>


class ScribbleArea
{
public:
    ScribbleArea(QWidget *parent = 0);
    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat );
    void setPenColour(const QColor &newColour);
    void setPenWidth(int newWidth);

    bool isModified() const { return modified; }
    QColor penColour() const { return myPenColour; }
    int penWidth() const { return myPenWidth; }

public slots:
    void clearImage;
    void print();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);
    bool modified;
    bool scribbling;
    QColor myPenColour;
    QImage image;
    QPoint lastPoint;

};

#endif // SCRIBBLEAREA_H
