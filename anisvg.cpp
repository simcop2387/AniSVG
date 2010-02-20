#include "anisvg.h"
#include "glwidget.h"
#include <QPainter>
#include <QFontMetrics>
#include <QSizeF>
#include <KLocale>
#include <QFile>
#include <QMessageBox>
#include <QPicture>
//#include <QGLWidget>

#include <GL/gl.h>

extern "C" void glInit();

#include <plasma/svg.h>
#include <plasma/theme.h>

AniSVG::AniSVG(QObject *parent, const QVariantList &args)
    : Plasma::Wallpaper(parent, args)
{

    glInit();

    if (!QGLFormat::hasOpenGL() || !QGLFramebufferObject::hasOpenGLFramebufferObjects()) {
	QMessageBox::information(0, "OpenGL framebuffer objects",
				 "This system does not support OpenGL/framebuffer objects.");
    } 
        const QString file("/home/ryan/projects/AniSVG/files/bubbles.svg");
	pic = new QSvgRenderer(file, parent);
	_timer  = new QTimer(this);
	connect(_timer, SIGNAL(timeout()), this, SLOT(updateWallpaper()));
	_timer->start((int)(60000 / FRAMES_PER_MINUTE));
	
	if (this->isWidgetType())
	printf("this is a widget\n");
	else
	printf("This is not a widget\n");

    GLWidget widget(0);
    widget.resize(640, 480);
    widget.show();
//	setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
	//pic->load("/home/ryan/projects/AniSVG/files/bubbles.svg", "svg");
}

void AniSVG::paint(QPainter *painter, const QRectF& exposedRect)
{
    painter->setBrush(Qt::white);
    painter->drawRect(boundingRect());
 
    painter->setPen(Qt::blue);
    painter->setFont(QFont("Arial", 50));
    painter->drawText(boundingRect(), Qt::AlignCenter, "Hello World!");
    //painter->drawPicture(0, 0, *pic);
    painter->setViewport(boundingRect().toRect());

//    saveGLState(); //needed apparently

    //QPainter fbo_painter(render_fbo);
    //pic->render(&fbo_painter);
    //svg_renderer->render(&fbo_painter);
    //fbo_painter.end();
    
//    restoreGLState(); //needed apparently
    
    //painter->drawImage(boundingRect(), render_fbo->toImage());
}

void AniSVG::updateWallpaper() {
    
    // shift seamless picture back to start
    emit update(boundingRect());  
}

#include "anisvg.moc"
