#pragma once

#include "qfl_global.h"

#include <math.h>
#include <QWidget>
#include <QtDesigner/QDesignerExportWidget>
#include <QtGui>

class QFL_EXPORT QflPot : public QWidget {
  Q_OBJECT
  Q_ENUMS(MeterColor)
  Q_PROPERTY(double minValue READ minValue WRITE setMinValue)
  Q_PROPERTY(double maxValue READ maxValue WRITE setMaxValue)
  Q_PROPERTY(int dotStep READ dotStep WRITE setDotStep)
  Q_PROPERTY(int wheelStep READ wheelStep WRITE setWheelStep)
  Q_PROPERTY(int fontDim READ fontDim WRITE setFontDim)
  Q_PROPERTY(int numPrec READ numPrec WRITE setPrecision)
  Q_PROPERTY(MeterColor startColor READ fstcolor WRITE setFstColor)
  Q_PROPERTY(MeterColor endColor READ sndcolor WRITE setSndColor)

 public:
  QflPot(QWidget *parent = nullptr);
  QSize minimumSizeHint() const;
  QSize sizeHint() const;
  enum MeterColor { white, green, red, yellow, magenta, blue };
  double actValue() const { return value; }
  double minValue() const { return min; }
  double maxValue() const { return max; }
  int dotStep() const { return dot; }
  int wheelStep() const { return wheel; }
  int fontDim() const { return font; }
  int numPrec() const { return precision; }
  MeterColor fstcolor() const { return fstColor; }
  MeterColor sndcolor() const { return sndColor; }

 signals:

  void valueChanged(double);

 public slots:

  void setMinValue(double);
  void setMaxValue(double);
  void setDotStep(int);
  void setWheelStep(int);
  void setFontDim(int);
  void setPrecision(int);
  void setFstColor(MeterColor);
  void setSndColor(MeterColor);

 protected:
  void paintEvent(QPaintEvent *);
  void wheelEvent(QWheelEvent *);
  void paintDial();
  void paintBorder();
  void paintDot();
  void paintValue();
  void paintArc();

 private:
  int spanAngle;
  int startAngle;
  int startPoint;
  double arc;
  double value;
  double min;
  double max;
  int dot;
  int wheel;
  int font;
  int precision;
  MeterColor fstColor;
  MeterColor sndColor;
};
