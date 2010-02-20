// Here we avoid loading the header multiple times
#ifndef ANISVG_HEADER
#define ANISVG_HEADER
// We need the Plasma Applet headers

#include <Plasma/Wallpaper>
#include <QSvgRenderer>
#include <QtGui>
#include <QtOpenGL>

class QSizeF;

// Define our plasma Applet
class AniSVG : public Plasma::Wallpaper
{
    Q_OBJECT
    public:
        // Basic Create/Destroy
        AniSVG(QObject *parent, const QVariantList &args);

        // The paint procedure paints the applet to screen
        void paint(QPainter *painter,
                const QRectF& exposedRect);
//        void openFile(const QString &path);
//void saveGLState();
//void restoreGLState();

  protected slots:
      void updateWallpaper();
    private:
	QSvgRenderer *pic;
	QTimer*        _timer;
	static const int FRAMES_PER_MINUTE = 600;
	QGLFramebufferObject *render_fbo;	
};
 
// This is the command that links your applet to the .desktop file
K_EXPORT_PLASMA_WALLPAPER(anisvg, AniSVG)
#endif
