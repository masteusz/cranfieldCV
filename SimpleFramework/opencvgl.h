#ifndef OPENCVGL_H
#define OPENCVGL_H

#include <QGLWidget>

class OpenCVGL : public QGLWidget
{
public:
    OpenCVGL();
    void renderImage(const QImage& frame); // set images for rendering
protected:
    virtual void paintGL();
    virtual void resizeGL(int width, int height);
    void initializeGL();
private:
    QImage m_GLFrame;
    QImage m_GLImg;
};

#endif // OPENCVGL_H
