#include <QLabel>
#include <QStyle>
#include <QKeyEvent>

#include "combobox.h"

ComboBox::ComboBox(QWidget *parent) : QComboBox(parent) {
  m_label = new QLabel(this);

  int frame_width = frameWidth();
  QPixmap pixmap(":/icons/birthday-cake.png");
  pixmap = pixmap.scaled(QSize(sizeHint().height() - frame_width,
                      sizeHint().height() - frame_width),
                Qt::KeepAspectRatio);
  m_label->setPixmap(pixmap);
  m_label->setStyleSheet("QLabel { border: none; padding: 0px; }");

  // Add extra padding to the right of the comboBox. It looks better.
  setStyleSheet(QString("QComboBox { padding-left: %1px; }").arg(m_label->sizeHint().width() +
                                                                 frame_width + 5));

  QSize min_size_hint = minimumSizeHint();
  setMinimumSize(qMax(min_size_hint.width(),
                      m_label->sizeHint().height() + frame_width),
                 qMax(min_size_hint.height(),
                      m_label->sizeHint().height() + frame_width));
}

ComboBox::~ComboBox() {
  delete m_label;
}

int ComboBox::frameWidth() const {
  return style()->pixelMetric(QStyle::PM_DefaultFrameWidth, 0, this);
}

void ComboBox::resizeEvent(QResizeEvent *event) {
  Q_UNUSED(event);

  // Place clear button correctly, according to size of comboBox.
  QSize sz = m_label->sizeHint();
  m_label->move(frameWidth()+2,
                (rect().height() - sz.height())/2 + frameWidth());
}
